#pragma once
#pragma once
#include"../../Object/Object.h"
#include"../../Collision/Collision.h"
#include<ctime>


class Shooting_Game : public MyApp::Scene
{
private:

	//âπ
	const Sound bgm{ L"res/Sound/Shooting_Game.mp3" };

	Vec2 target_pos{0,0};

	int32 target_size =Random(20,50);

	float warp_time = 60 * 1.5f;

	//â~ä÷åW
	Vec2 pos{ 0,0 };
	Vec2 size{0,0};
	int32 circle_y = 20;
	bool circle_move = false;
	int32 up_time = 1;
	float power = 10.0;
	float gravity = -1;
	float first_speed = 0.0;

	

public:

	

	void update() override
	{
		bgm.play();
		bgm.setVolume(0.1);
		if (Input::KeyControl.pressed)
		{
			++m_data->counter;
			changeScene(L"Result");
		}

		up_time -= 1; //â~ÇÃêLÇ—èkÇ›

		warp_time -= 1;

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

		
		if (warp_time == 0)
		{
			warp_time = 60 * 1.5f;
			target_pos.x = Random(100, 500);
			target_pos.y = Random(100, 400);
			target_size = Random(20, 50);
		}

		pos.x = Random(pos.x - size.x, pos.x + size.x);
		pos.y = Random(pos.y - size.y, pos.y + size.y);
	}

	void draw() const override
	{
		Window::ClientRect().draw(Palette::White);
		

		Circle(target_pos.x, target_pos.y, (target_size + 40)).draw(Palette::Red);
		Circle(target_pos.x, target_pos.y, (target_size + 20)).draw(Palette::White);
		Circle(target_pos.x, target_pos.y, (target_size - 10)).draw(Palette::Red);


		Circle(Mouse::Pos(),(size.x, size.y)).drawFrame(0, 5, Palette::Blue);

		Circle(pos.x, pos.y, 3).draw(Palette::Yellow);

	}
};
