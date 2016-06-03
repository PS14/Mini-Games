#pragma once
#include"../../Object/Object.h"


class InvaderGame_Menu : public MyApp::Scene 
{
private:

	const Sound bgm{ L"res/Sound/game_menu.mp3" };

public:

	void update() override
	{
		bgm.play();

		if (Input::KeySpace.pressed)
		{
		

			++m_data->counter;
			changeScene(L"Invader_Game");

		}


	}

	void draw() const override
	{
		Window::ClientRect().draw(Palette::Black);

		m_data->font(L"������@").draw(Window::Center());

	}

};