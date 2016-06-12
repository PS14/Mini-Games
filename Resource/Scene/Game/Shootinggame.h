#pragma once
#pragma once
#include"../../Object/Object.h"
#include<ctime>


class Shooting_Game : public MyApp::Scene
{
private:

	//‰¹
	const Sound bgm{ L"res/Sound/Shooting_Game.mp3" };

	//‰~ŠÖŒW
	Vec2 size{0,0};
	int32 circle_y = 20;
	bool circle_move = false;
	int32 up_time = 1;
	float power = 10.0;
	float gravity = -1;
	float first_speed = 0.0;

public:

	void init() override
	{
		up_time = 1;
		circle_move = false;
		size.x = 0;
		size.y = 0;
	}

	void update() override
	{
		bgm.play();
		bgm.setVolume(0.1);
		if (Input::KeyControl.pressed)
		{
			++m_data->counter;
			changeScene(L"Result");
		}

		up_time -= 1;

		if (up_time == 0)
		{
			if (!circle_move)
			{
				circle_move = true;
				first_speed = power;
			}
		}

		if (circle_move)
		{
			size.x += first_speed + 0.5 * gravity;
			size.y += first_speed + 0.5 * gravity;
			first_speed += gravity;
		}

		if (size.y <= 0)
		{
			size.y = 0;
			circle_move = false;
			up_time = 1;
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


		Circle(Mouse::Pos(),(size.x, size.y)).drawFrame(0, 5, Palette::Blue);

	}
};
