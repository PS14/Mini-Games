#pragma once
#include"../../Object/Object.h"


class Batting_Game : public MyApp::Scene
{
private:
	//画像
	const Texture texture{ L"Resource/Texture/baseballstadium.png" };
	//音
	const Sound hit{ L"Resource/Sound/hit.mp3" };
	const Sound bgm{ L"Resource/Sound/Baseball.mp3" };

	//回転
	double degree = 65;
	double radian = Radians(degree);

	//プレイヤー
	Rect player{ 60, 10 };

	//投手
	Triangle enemy{ 320,180,30.0 };

	//球関係
	
	double speed = 5.0;
	Vec2 ballspeed{ 0, speed };

	//スコア
	int32 score;
	//フラグ
	bool collided;
	int32 count = 0;

	//test
	Circle ball{ 320,170,8 };
	Circle ball2{ 320,170,8 };
	//経過時間
	Stopwatch time;

	enum Change
	{
		SCENE_1,
		SCENE_2,
		SCENE_3,
		SCENE_4,
		SCENE_5
	};

	int32  change = SCENE_1;

	enum Hit
	{
		SHAKE,
		RETURN
	};

	int32 bat = SHAKE;

	//テキストに書き込む
	TextWriter writer{ L"Resource/Text/batting_score.txt" };

public:

	void init() override
	{
		player.setCenter(320, 420);
		count = 2;
	}

	void update() override
	{
		bgm.play();
		bgm.setVolume(0.1);

		collided = false;

		time.start();

		if (Input::KeyControl.pressed)
		{
			changeScene(L"Batting_Result");
		}

		//ボールの動き
		switch (change)
		{
		case SCENE_1:
			if (time.s() == 3)
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

			if (ballspeed.y > 0 && player.rotatedAt(player.pos, radian).intersects(ball))
			{
				hit.playMulti(0.1);
				score += 1;
				ballspeed = Vec2((ball.x - player.center.x), -ballspeed.y).setLength(speed);
			}

			if (ball.y < 0 && ballspeed.y < 0)
			{
				change = SCENE_3;
			}

			if (ball.y > Window::Height())
			{
				change = SCENE_3;
			}
			break;

		case SCENE_3:

			if (time.s() == 10)
			{
				count--;
				change = SCENE_4;
			}
			break;

		case SCENE_4:
			ball2.moveBy(-ballspeed);

			if ((ball2.x < 0 && ballspeed.x < 0) || (Window::Width() < ball2.x && ballspeed.x > 0))
			{
				change = SCENE_5;
			}

			if (ballspeed.y > 0 && player.rotatedAt(player.pos, radian).intersects(ball2))
			{
				hit.playMulti(0.1);
				score += 1;
				ballspeed = Vec2((ball2.x - player.center.x), ballspeed.y).setLength(speed);
			}

			if (ball2.y < 0 && ballspeed.y < 0)
			{
				change = SCENE_5;

			}

			if (ball2.y > Window::Height())
			{
				change = SCENE_5;
			}
			break;


		case SCENE_5:
			if (count == 0)
			{
				changeScene(L"Batting_Result");
				//テキストに書き込み
				writer.writeln(L"打った回数", score, L"回");
			}
			else
			{
				ballspeed *= -1;
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
		m_data->font(L"残り球 :", count).draw(10, 50);

		switch (change)
		{
		case SCENE_1:

			break;

		case SCENE_2:
			if (ball.y > Window::Height())
			{
				m_data->font(L"ストライク！").draw(300, 300, Palette::Red);
			}

			break;


		case SCENE_3:
			//m_data->font(L"ホームランん！").draw(300, 200, Palette::Orange);

			break;

		case SCENE_4:

			if (ball.y > Window::Height())
			{
				m_data->font(L"ストライク！").draw(300, 300, Palette::Red);
			}

			break;

		case SCENE_5:
			if (ball.y < Window::Height())
			{
				m_data->font(L"ストライク！").draw(300, 300, Palette::Red);
			}
			break;

		}
		//test ボール
		ball.draw();
		ball2.draw();
		m_data->font(change).draw(10, 10, Palette::Yellow);
		m_data->font(ballspeed).draw(10, 100, Palette::Black);
		//投手
		enemy.draw(Palette::Blue);

		//プレイヤー(バット)
		player.rotatedAt(player.pos, radian).draw(Palette::Gray);
		//player.draw(Palette::Gray);
	}

};