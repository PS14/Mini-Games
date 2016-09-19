#pragma once
#include"../../Object/Object.h"

class BrokenstickGame_Menu : public MyApp::Scene
{
private:

	//画像
	const Texture texture{ L"Res/Texture/image (3).png" };

	//音
	const Sound sound{ L"Res/Sound/explosion.mp3" };
	const Sound bgm{ L"Res/Sound/game_menu.mp3" };

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

		if (Input::KeyBackspace.pressed)
		{
			++m_data->counter;
			changeScene(L"Menu");
		}
	}

	void draw() const override
	{
		Window::ClientRect().draw(Palette::Black);

		texture.draw(Alpha(60));

		m_data->font(L"操作方法").draw(200, 10, Palette::Green);
		m_data->font(L"マウスの左右で移動").draw(150, 100, Palette::White);
		m_data->font(L"ゲームルール").draw(150, 170, Palette::Orange);
		m_data->font(L"ブロックを壊す").draw(150, 230, Palette::White);

		m_data->font(L"Click to game start").draw(200, 400, Palette::Yellow);
	}

};