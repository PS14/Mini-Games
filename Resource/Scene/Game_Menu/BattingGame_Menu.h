#pragma once
#include"../../Object/Object.h"

class BattingGame_Menu : public MyApp::Scene
{
private:
	//�摜
	const Texture texture{ L"res/texture/baseballstadium.png" };

	const Sound bgm{ L"res/Sound/game_menu.mp3" };
	const Sound hit{ L"res/Sound/hit.mp3" };

public:

	void update() override
	{
		bgm.play();

		bgm.setVolume(0.05);

		if (Input::KeySpace.pressed)
		{
			
			hit.play();
			++m_data->counter;
			changeScene(L"Batting_Game");

		}


	}

	void draw() const override
	{
		Window::ClientRect().draw(Palette::Black);
		//�摜
		texture.resize(700, 550).draw(-30, -50, Alpha(50));

		m_data->font(L"������@").draw(200, 10, Palette::White);
		m_data->font(L"space Key �Ł@�o�b�g��U��").draw(100, 100, Palette::White);
		m_data->font(L"�Q�[�����[��").draw(200, 200, Palette::White);
		m_data->font(L"�Ђ�����ł�").draw(200, 250, Palette::White);
		m_data->font(L"space�@key to game start").draw(200, 400, Palette::Yellow);
	}
};