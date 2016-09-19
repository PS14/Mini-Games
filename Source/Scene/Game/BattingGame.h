#pragma once
#include"../../Object/Object.h"


class Batting_Game : public MyApp::Scene
{
private:
	//画像
	const Texture texture{ L"Res/Texture/baseballstadium.png" };
//	const Texture ball_texture{ L"Res/Texture/ball.png" };
	//音
	const Sound hit{ L"Res/Sound/hit.mp3" };
	const Sound bgm{ L"Res/Sound/Baseball.mp3" };

	//回転
	 double degree = 65;
	double radian = Radians(degree);

	//プレイヤー
	Rect player{ 60, 10 };

	//投手
	Triangle enemy{ 320,180,30.0 };

	//球関係
	Array<Vec2> balls;
	double speed = 5.0;
	Vec2 ballspeed{ 0, speed };

	//スコア
	int32 score;
	//フラグ
	bool collided;
	int32 count = 0;

	//test
	Circle ball{ 320,170,8 };
	//経過時間
	Stopwatch time;
	
	enum Change
	{
		SCENE_1,
		SCENE_2,
		SCENE_3
	};

	int32  change = SCENE_1;

	enum Hit
	{
		SHAKE,
		RETURN
	};
	
	int32 bat = SHAKE;

public:

	void init() override
	{
		for (auto& ballsize : balls)
		{
			ballsize.x = 320;
			ballsize.y = 170;
		}	
		player.setCenter(320, 420);
		count = 1;
	}
	
	void update() override
	{
		bgm.play();
		bgm.setVolume(0.1);
	
		collided = false;

		time.start();

		if (Input::KeyControl.pressed)
		{
			changeScene(L"Result");
		}

		//ボールの動き
		switch (change)
		{
		case SCENE_1:

			
			if (time.s() == 3 )
			{
				count--;
				change = SCENE_2;
			}
			break;

		case SCENE_2:
			ball.moveBy(ballspeed);

			if ((ball.x < 0 && ballspeed.x < 0) || (Window::Width() < ball.x && ballspeed.x > 0))
			{
				change = SCENE_3;
			}

			if (ballspeed.y > 0 && player.intersects(ball))
			{
				hit.playMulti(0.1);
				ballspeed = Vec2((ball.x - player.center.x), -ballspeed.y).setLength(speed);
			}

			if (ball.y < 0 && ballspeed.y <  0)
			{
				change = SCENE_3;
			}
			break;

		case SCENE_3:

			if (count == 0)
			{
				changeScene(L"Result");
			}
		
			break;
		}

		switch (bat)
		{
		case SHAKE:

			if (Input::MouseL.clicked)
			{
				radian -= degree;
				bat = RETURN;
			}
			break;

		case RETURN:

			if (Input::MouseL.released)
			{
				radian += degree;
				bat = SHAKE;
			}
			break;
		}
	}

	void draw() const override
	{
		//背景
		Window::ClientRect().draw(HSV(120, 0.5, 0.7));

		//画像
		texture.resize(700, 550).draw(-30, -50);

		//スコア表示
		//m_data->font(L"score : ", score).draw(10, 10);
		m_data->font(L"残り球 :", count ).draw(10, 50);

		switch (change)
		{
		case SCENE_1:

			if (time.s() == 3)
			{
			
				m_data->font(L"投げた").draw(300, 200, Palette::Yellow);
			}
			break;

		case SCENE_2:
			if (ballspeed.y > 0 && player.intersects(ball))
			{
				m_data->font(L"打った！").draw(300, 200, Palette::Yellow);
				
			}
			break;


		case SCENE_3:
			m_data->font(L"ヒット！").draw(300, 200, Palette::Yellow);

			break;

		}
		ball.draw();
		
		//投手
		enemy.draw(Palette::Blue);

		//プレイヤー(バット)
		player.rotatedAt(player.pos, radian).draw(Palette::Gray);
		//player.draw(Palette::Gray);
	}

};