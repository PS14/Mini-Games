#pragma once
#include"../../Object/Object.h"

class TargetGame_Menu : public MyApp::Scene
{
private:

	const Texture texture{ Image(L"Res/Texture/image (4).png").mosaiced(20, 20)  };

	const Sound bgm{ L"Res/Sound/game_menu.mp3" };
	const Sound button{ L"Res/Sound/決定.mp3" };

public:

	void update() override
	{
		bgm.play();

		bgm.setVolume(0.05);

		if (Input::MouseL.clicked)
		{
			button.playMulti(0.1);
			++m_data->counter;
			changeScene(L"Target_Game");

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

		m_data->font(L"操作方法").draw(200, 10, Palette::Green);
		m_data->font(L"左クリックで商品を狙う").draw(100, 100, Palette::White);
		m_data->font(L"Click to game start").draw(200, 400, Palette::Yellow);

	}
};