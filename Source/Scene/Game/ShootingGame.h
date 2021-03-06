#pragma once

#include"../../Object/Object.h"
#include"../../Collision/Collision.h"
#include<ctime>

class Shooting_Game : public MyApp::Scene
{
private:

	//音
	const Sound bgm{ L"Resource/Sound/Shooting_Game.mp3" };

	const Sound button{ L"Resource/Sound/決定.mp3" };

	Vec2 target_pos{ 0,0 };
	int32 target_size = Random(20,50);
	float warp_time = 60 * 1.5f;

	Stopwatch time;

	//円関係
	Vec2 pos{ 0,0 };
	Vec2 size{0,0};
	bool circle_move = false;
	int32 up_time = 1;
	float power = 10.0;
	float gravity = -1;
	float first_speed = 0.0;
	int32 score;

	const bool small_circle = hit(target_pos.x,target_pos.y,target_size - 10,pos.x,pos.y);
	const bool middle_circle = hit(target_pos.x, target_pos.y, target_size + 20, pos.x, pos.y);
	const bool big_circle = hit(target_pos.x, target_pos.y, target_size + 40, pos.x, pos.y);

	//テキストに書き込む
	TextWriter writer{ L"Resource/Text/Shooting_score.txt" };

public:

	void update() override
	{
		bgm.play();
		bgm.setVolume(0.1);

		time.start();
	
		if (Input::KeyControl.pressed)
		{
			changeScene(L"Shooting_Result");
		}		

		up_time -= 1; //円の伸び縮み
		warp_time -= 1;

		if (up_time == 0)
		{
			if (!circle_move)
			{
				circle_move = true;
				first_speed = power;
			}
		}

		if (Input::MouseL.clicked &&  big_circle)
		{
				score += 1;
		}

		if (time.s() == 10)
		{
			changeScene(L"Shooting_Result");
			//テキストに書き込み
			writer.writeln(L"回数", score, L"回");
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
		
		//的
		Circle(target_pos.x, target_pos.y, (target_size + 40)).draw(Palette::Red);
		Circle(target_pos.x, target_pos.y, (target_size + 20)).draw(Palette::White);
		Circle(target_pos.x, target_pos.y, (target_size - 10)).draw(Palette::Red);
		
		//カーソル
		Circle(Mouse::Pos(),(size.x, size.y)).drawFrame(0, 5, Palette::Blue);

		Circle(Mouse::Pos()).draw(Palette::Orange);
	
		m_data->font(time.s(), L"秒").draw(10,10,Palette::Black);
		m_data->font(L"score :", score).drawCenter(50, 50,Palette::Black);
		
	}
};
