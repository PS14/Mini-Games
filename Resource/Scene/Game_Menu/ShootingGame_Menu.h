#pragma once
#include"../../Object/Object.h"

class ShootingGame_Menu : public MyApp::Scene
{
private:

	const Texture texture{ L"Res/Texture/image (2).png" };

	const Sound bgm{ L"Res/Sound/game_menu.mp3" };
	const Sound button{ L"Res/Sound/����.mp3" };

public:

	void update() override
	{
		bgm.play();

		bgm.setVolume(0.05);

		if (Input::MouseL.clicked)
		{
			button.playMulti(0.1);
			++m_data->counter;
			changeScene(L"Shooting_Game");
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

		texture.draw(Alpha(50));

		m_data->font(L"������@").draw(200, 10, Palette::Green);
		m_data->font(L"���N���b�N�œI��_��").draw(100, 100, Palette::White);

		m_data->font(L"Click to game start").draw(200, 400, Palette::Yellow);
	}
};