#pragma once
#include"../../Object/Object.h"
#include <deque>


class GameClear : public MyApp::Scene
{
private:

	//BGM
	const Sound bgm{ L"Resource/Sound/Game_clear.mp3" };



	//�g
	const RoundRect rect{120, 200, 400, 200, 10};

	
public:
	
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
		Window::ClientRect().draw(Palette::Lightblue);

		rect.draw(Palette::White);
		rect.drawFrame(0, 5, Palette::Orange);

	

	}

};