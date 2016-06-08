#pragma once
#include"../../Object/Object.h"


class PuzzleGame_Menu : public MyApp::Scene
{
private:

	const Sound bgm{ L"res/Sound/game_menu.mp3" };
	const Texture texture{ L"res/texture/game_sound.mp3" };

public:

	void update() override
	{
		bgm.play();

		bgm.setVolume(0.05);

		if (Input::MouseL.clicked)
		{
			++m_data->counter;
			changeScene(L"Puzzle_Game");
		}
	}

	void draw() const override
	{
		Window::ClientRect().draw(Palette::Black);

		m_data->font(L"操作方法").draw(200, 10, Palette::White);
		m_data->font(L"ドラックで移動").draw(150, 100, Palette::White);
		m_data->font(L"Click to game start").draw(300, 400, Palette::Yellow);


	}
};