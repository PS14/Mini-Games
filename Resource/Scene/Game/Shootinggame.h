#pragma once
#pragma once
#include"../../Object/Object.h"


class Shooting_Game : public MyApp::Scene
{
private:

	int32 circle_y = 20;

public:

	void update() override
	{
		if (Input::KeyControl.pressed)
		{
			++m_data->counter;
			changeScene(L"Result");
		}

		circle_y += 1;

		if (circle_y < 50)
		{
			circle_y *= 1;
		}


	}

	void draw() const override
	{
		Window::ClientRect().draw(Palette::White);
		//“I
		Circle(Window::Width() / 2, Window::Height() / 2, 100).draw(Palette::Red);
		Circle(Window::Width() / 2, Window::Height() / 2, 70).drawFrame(0, 10, Palette::White);
		Circle(Window::Width() / 2, Window::Height() / 2, 30).drawFrame(0, 10, Palette::White);
		Circle(Window::Width() / 2, Window::Height() / 2, 10).draw(Palette::White);


		//Rect(Mouse::Pos(), 20).draw();
		Circle(Mouse::Pos(), circle_y).drawFrame(0, 5, Palette::Blue);

	}
};
