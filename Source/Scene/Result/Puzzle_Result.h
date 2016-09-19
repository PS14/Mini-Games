#pragma once
#include"../../Object/Object.h"
#include <deque>


class Puzzle_Result : public MyApp::Scene
{
private:

	//BGM
	const Sound bgm{ L"Resource/Sound/Game_clear.mp3" };

	//�e�L�X�g�ǂݍ��݊֌W
	TextReader reader{ L"Resource/Text/puzzle_score.txt" };
	const String s = reader.readAll();

	//�g
	const RoundRect rect{ 120, 200, 400, 200, 10 };

public:

	void init() override
	{
		
	}
	void update() override
	{
		bgm.play();

		bgm.setVolume(0.1);

		

		if (Input::MouseL.clicked)
		{
			++m_data->counter;
			changeScene(L"Title");


		}

	}

	void draw() const override
	{
		Window::ClientRect().draw(Palette::Black);


		rect.draw(Palette::White);
		rect.drawFrame(0, 5, Palette::Orange);

		m_data->font(s).draw(200, 250, Palette::Black);

		m_data->font(L"GAME Clear").draw(150, 100, Palette::Yellow);

	}

};