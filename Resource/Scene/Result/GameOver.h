#pragma once
#include"../../Object/Object.h"

class GameOver : public MyApp::Scene
{
private:

	const Sound bgm{ L"res/Sound/gameover.mp3" };

public:

	void update() override
	{
		bgm.play();

		//���g���C
		if (Input::KeyR.pressed)
		{
			++m_data->counter;
			changeScene(L"BrokenstickGame_Menu");
		}

		//�^�C�g����
		if (Input::KeySpace.pressed)
		{
			++m_data->counter;
			changeScene(L"Title");
		}
	}

	void draw() const override
	{

		m_data->font(L"GAME OVER").draw(150, 100, Palette::White);
		m_data->font(L"R�L�[ �� ���g���C").draw(150, 150, Palette::White);
		m_data->font(L"�X�y�[�X�L�[ �� �^�C�g��").draw(150, 200, Palette::White);
	}

};