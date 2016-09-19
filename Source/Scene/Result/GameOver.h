#pragma once
#include"../../Object/Object.h"

class GameOver : public MyApp::Scene
{
private:

	const Sound bgm{ L"Resource/Sound/gameover.mp3" };

	//�g
	const RoundRect rect{ 200, 150, 300, 150, 10 };

	//�e�L�X�g�ǂݍ��݊֌W
	TextReader reader{ L"Resource/Text/block_score.txt" };
	const String s = reader.readAll();

public:

	void update() override
	{
		bgm.play();
		bgm.setVolume(0.1);
		//���g���C
		if (Input::MouseL.clicked)
		{
			changeScene(L"BrokenstickGame_Menu");
		}

		//�^�C�g����
		if (Input::KeySpace.pressed)
		{
			changeScene(L"Title");
		}
	}

	void draw() const override
	{
		rect.draw(Palette::White);
		rect.drawFrame(0, 5, Palette::Orange);

		m_data->font(s).drawCenter(350, 230, Palette::Black);

		m_data->font(L"GAME OVER").draw(300, 10, Palette::Red);
		m_data->font(L"���N���b�N �� ���g���C").draw(50, 350, Palette::Yellow);
		m_data->font(L"�X�y�[�X�L�[ �� �^�C�g��").draw(50, 400, Palette::Orange);
	}

};