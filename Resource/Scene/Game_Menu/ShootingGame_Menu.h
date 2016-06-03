#pragma once
#include"../../Object/Object.h"

class ShootingGame_Menu : public MyApp::Scene
{
private:

	const Sound bgm{ L"res/Sound/game_menu.mp3" };

public:

	void update() override
	{
		bgm.play();

		if (Input::MouseL.clicked)
		{
		

			++m_data->counter;
			changeScene(L"Shooting_Game");

		}


	}

	void draw() const override
	{
		Window::ClientRect().draw(Palette::Black);

		m_data->font(L"‘€ì•û–@").draw(Window::Center());
	}
};