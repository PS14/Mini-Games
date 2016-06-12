#pragma once
#include"../../Object/Object.h"

class GameClear : public MyApp::Scene
{
private:

public:

	void update() override
	{
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