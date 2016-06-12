#pragma once
#include"../../Object/Object.h"


class PuzzleGame_Menu : public MyApp::Scene
{
private:
	
	const Texture texture{ Image( L"res/texture/image (1).png").mosaiced(10, 10) };

	const Sound bgm{ L"res/Sound/game_menu.mp3" };

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

		texture.draw(Alpha(50));

		m_data->font(L"操作方法").draw(200, 10, Palette::White);
		m_data->font(L"ドラックで移動").draw(150, 100, Palette::White);
		m_data->font(L"Click to game start").draw(300, 400, Palette::Yellow);


	}
};