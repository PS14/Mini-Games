#pragma once
#include"../../Object/Object.h"
#include"../../Collision/Collision.h"


class Puzzle_Game : public MyApp::Scene
{
private:
	//����
	Stopwatch stopwatch;
	//�g
	const Rect puzzle_rect{ 50, 50, 400, 400 };
	const Rect finished_rect{ 480, 230, 150, 200 };
	//�l�p�̓��I�z��
	//Optional �����l
	std::array<Optional<int32>, 16> pieces =
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

	const int32 pieceSize = 100;
	//�摜
	const Texture texture{ L"Resource/Texture/miku.jpg" };
	//��
	const Sound bgm{ L"Resource/Sound/Puzzle_Game.mp3" };
	//Optional �����l
	Optional<int32> grabbed;

	//Clear����
	bool clear;

	//�摜�̃��l
	int32 alpha = 255;

	//�e�L�X�g�ɏ�������
	TextWriter writer{ L"Resource/Text/puzzle_score.txt" };

public:
	
	//�J�E���g
	int32 count = 0;
	

	void init() override
	{
		//�����_���z�u
		for (int32 i = 0; i < 10000; ++i)
		{
			//�����_���z�u
			const int32 a = Random(0,15);
			const int32 b = a + RandomSelect({ -4, -1, 1, 4 });
			//����ւ�����
			if (pieces[a] && InRange(b, 0, 15) && !pieces[b] && Swappable(a, b))
			{
				std::swap(pieces[a], pieces[b]);
			}
		}
	}

	void update() override
	{
		//����START
		stopwatch.start();
		//���y�Đ�
		bgm.play();
		//���ʐݒ�
		bgm.setVolume(0.1);

		clear = true;

		//����
		if (!Input::MouseL.pressed)
		{
			grabbed = none;
		}

		for (auto i : step(16))
		{
			const Rect pieceRect(i % 4 * pieceSize + 50, i / 4 * pieceSize + 50, pieceSize, pieceSize);

			if (!pieces[i])
			{
				//����ւ�
				if (grabbed && pieceRect.mouseOver && Swappable(i, grabbed.value()))
				{
					std::swap(pieces[i], pieces[grabbed.value()]);
					grabbed = none;

					count += 1;
				}
				continue;
			}

			if (pieces[i] != i)
			{
				clear = false;
			}
		
			if (pieceRect.leftPressed)
			{
				grabbed = i;
			}	
		}

		//������������A�N���A��ʂɈړ�
		if (clear)
		{
			changeScene(L"Puzzle_Result");
			//����Reset
			stopwatch.pause();
			
			//�e�L�X�g�ɏ�������
			writer.writeln(L"�o�ߕb���@:",stopwatch.s(), L"�b");
			writer.writeln(L"����ւ����� :", count, L"��");

		}

		//�f�o�b�N�p
		if (Input::KeyControl.pressed)
		{
			changeScene(L"Puzzle_Result");
			//����Reset
			//stopwatch.reset();
			stopwatch.pause();

			//�e�L�X�g�ɏ�������
			writer.writeln(L"�o�ߎ��� :", stopwatch.s(),L"�b");
			writer.writeln(L"����ւ����� :", count ,L"��");
		}

	}

	void draw() const override
	{
		Optional<int32> grabbed;

		for (auto i : step(16))
		{
			const Rect pieceRect(i % 4 * pieceSize + 50, i / 4 * pieceSize + 50, pieceSize, pieceSize);

			if (!pieces[i])
			{
				//����ւ�
				if (grabbed && pieceRect.mouseOver && Swappable(i, grabbed.value()))
				{
					grabbed = none;
				}
				continue;
			}

			const int offset = pieces[i].value();
			pieceRect(texture.uv(offset % 4 * 0.25, offset / 4 * 0.25, 0.25, 0.25)).draw(Alpha(alpha) );


			if (pieceRect.leftPressed)
			{
				grabbed = i;
				pieceRect.draw({ 255, 0, 0, 80 });
			}

			pieceRect.drawFrame();	
		}

		
		//�g
		puzzle_rect.drawFrame(0, 5, Palette::Lightsalmon);
		finished_rect.drawFrame(0, 5, Palette::Lightblue);
		//�����}
		texture.resize(150, 200).draw(480, 230);

		m_data->font(L"�����}").draw(500, 180, Palette::Yellow);
		m_data->font(stopwatch.s(), L"�b").draw(500, 10);
		m_data->font(L"��",count).draw(500,60);
	}
};
