#pragma once
#include"../../Object/Object.h"

class GameClear : public MyApp::Scene
{
private:

	const Sound bgm{ L"res/Sound/  .mp3" };

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
		Window::ClientRect().draw(Palette::Black);


	}

};