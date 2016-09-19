#pragma once
#include"../../Object/Object.h"


class PuzzleGame_Menu : public MyApp::Scene
{
private:
	
	const Texture texture{ Image( L"Res/Texture/image (1).png").mosaiced(10, 10) };

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
			changeScene(L"Puzzle_Game");
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
		m_data->font(L"クリックで選択し、").draw(150, 100, Palette::White);
		m_data->font(L"ドラッグで移動する").draw(150, 150, Palette::White);
		m_data->font(L"Click to game start").draw(300, 400, Palette::Yellow);


	}
};