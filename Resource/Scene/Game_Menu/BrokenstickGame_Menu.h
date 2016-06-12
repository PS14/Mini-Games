#pragma once
#include"../../Object/Object.h"

class BrokenstickGame_Menu : public MyApp::Scene
{
private:

	//画像
	const Texture texture{ L"res/texture/image (3).png" };

	//音
	const Sound sound{ L"res/Sound/explosion.mp3" };
	const Sound bgm{ L"res/Sound/game_menu.mp3" };

public:

	void update() override
	{
		bgm.play();

		bgm.setVolume(0.05);

		if (Input::MouseL.clicked)
		{
			sound.playMulti(0.1);
			++m_data->counter;
			changeScene(L"Brokenstick_Game");
		}
	}

	void draw() const override
	{
		Window::ClientRect().draw(Palette::Black);

		texture.draw(Alpha(60));

		m_data->font(L"操作方法").draw(200, 10, Palette::White);
		m_data->font(L"マウスの左右で移動").draw(150, 100, Palette::White);

		m_data->font(L"Click to game start").draw(200, 400, Palette::Yellow);
	}

};