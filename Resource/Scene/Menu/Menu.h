#pragma once
#include"../../Object/Object.h"

class Menu : public MyApp::Scene
{
private:
	const int font_size = 18;

	const Font font{ font_size, Typeface::Light };

	const Array<String> texts =
	{
		L"1. 15�p�Y��(��)",
		L"2. �싅",
		L"3. �I����",
		L"4. �C���x�[�_�[",
		L"5. �˓I(��)",
	};

	const Sound sound{ L"res/Sound/button.mp3" };
	const Sound bgm{ L"res/Sound/Menu.mp3" };

	const Rect rect{ 300,100,300,300 };
public:

	void update() override
	{
		bgm.play();
		//�^�C�g���֖߂�
		if (Input::MouseL.clicked)
		{
			sound.playMulti(0.5);
			++m_data->counter;
			changeScene(L"Title");
		}

		//key1���������灨PuzzleGame��
		if (Input::Key1.pressed)
		{
			sound.playMulti(0.5);
			++m_data->counter;
			changeScene(L"PuzzleGame");
		}

		//key2���������灨BaseBall
		if (Input::Key2.pressed)
		{
			sound.playMulti(0.5);
			++m_data->counter;
			changeScene(L"BaseBall");
		}
		
		//key3���������灨�I����
		if (Input::Key3.pressed)
		{
			sound.playMulti(0.5);
			++m_data->counter;
			changeScene(L"Shootinggame");
		}

		//key4�������灨Invader
		if (Input::Key4.pressed)
		{
			sound.playMulti(0.5);
			++m_data->counter;
			changeScene(L"Invader");
		}

		//key5�������Ă灨TargetGame
		if (Input::Key5.pressed)
		{
			sound.playMulti(0.5);
			++m_data->counter;
			changeScene(L"TargetGame");
		}

	}

	void draw() const override
	{

		m_data->font(L"�P�`�T�̃L�[�����Ă�������").draw(200, 10, Palette::White);

		for (auto p : step({ 1, 5 }))
		{
			const Rect rect(60 + p.x * 280, 60 + p.y * 80, 220, 60);

			Graphics2D::SetTransform(Mat3x2::Rotate(Radians(2), rect.pos));

			rect.drawShadow({ 1, 1 }, 12, -1, ColorF(0, 0.4));

			Graphics2D::SetTransform(Mat3x2::Identity());

			rect.draw(HSV((p.x * 5 + p.y) * 30, 0.5, 1.0));

			font(texts[p.x * 5 + p.y]).draw(rect.pos.movedBy(20, 12), Palette::Black);
		}

		rect.drawFrame(0, 10, Palette::Firebrick);
	}
};
