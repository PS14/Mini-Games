#pragma once
#include"../../Object/Object.h"

class BattingGame_Menu : public MyApp::Scene
{
private:
	//�摜
	const Texture texture{ L"Resource/Texture/baseballstadium.png" };
	
	//��
	const Sound bgm{ L"Resource/Sound/game_menu.mp3" };
	const Sound hit{ L"Resource/Sound/hit.mp3" };

public:

	void update() override
	{
		bgm.play();
		bgm.setVolume(0.05);

		if (Input::MouseL.clicked)
		{	
			hit.play();
			++m_data->counter;
			changeScene(L"Batting_Game");
		}
		if (Input::KeyBackspace.pressed)
		{
			++m_data->counter;
			changeScene(L"Menu");
		}
	}

	void draw() const override
	{
		Window::ClientRect().draw(Palette::Black);
		//�摜
		texture.resize(700, 550).draw(-30, -50, Alpha(60));

		m_data->font(L"������@").draw(200, 10, Palette::Green);
		m_data->font(L"���N���b�N �� �o�b�g��U��").draw(100, 150, Palette::White);
		m_data->font(L"Click to game start").draw(200, 400, Palette::Yellow);
	}
};