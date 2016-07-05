#pragma once
#pragma once
#include"../../Object/Object.h"

class Batting_Game : public MyApp::Scene
{
private:
	//画像
	const Texture texture{ L"res/texture/baseballstadium.png" };
	const Texture ball_texture{ L"res/texture/ball.png" };
	//音
	const Sound hit{ L"res/Sound/hit.mp3" };
	const Sound bgm{ L"res/Sound/Baseball.mp3" };
	
	//回転()
	const double degree = 45;
	double radian = Radians(degree);
	//プレイヤー
	const Rect player = Rect{ 270, 420, 70, 10 };
	
	//投手
	Triangle enemy = Triangle{ 320,180,30.0 };

	//ボール
	Circle ball = Circle{ 320,180,10 };

	const double speed = 8.0;

	//スコア
	int32 score;
	
	std::vector<Circle> bullet_vector;
	bool collided;
	int32 ball_speed = 3 ;

public:

	void update() override
	{
		bgm.play();
		bgm.setVolume(0.1);
		
		//画面切り替え
		if (Input::KeyControl.pressed)
		{
			
			changeScene(L"Result");
		}

		//バットを振る
		if (Input::KeySpace.pressed)
		{
			radian -= 0.1;
		}
	
		collided = false;
		//ボールが飛ぶ
		if (Input::MouseL.clicked)
		{
			bullet_vector.push_back(ball);
		}

		//ボールの動き
		for (auto i = 0; i < bullet_vector.size(); i++)
		{
			bullet_vector[i].draw(Palette::Gold);

			if (!collided && bullet_vector[i].intersects(player))
			{
				hit.play();
				collided = true;
				bullet_vector[i].y += -ball_speed * 100;
				//score += 1;
			}
			else
			{
				bullet_vector[i].y += ball_speed;
			}

			if (bullet_vector[i].y > Window::Height())
			{
				bullet_vector.erase(bullet_vector.begin() + i);
			}
		}
	}

	void draw() const override
	{
		//背景
		Window::ClientRect().draw(HSV(120, 0.5, 0.7));

		//画像
		texture.resize(700, 550).draw(-30, -50);

		//スコア表示
		m_data->font(L"score : ", score).drawCenter(100, 100);
		
		for (auto i = 0; i < bullet_vector.size(); i++)
		{
			bullet_vector[i].draw(Palette::White);
		}

		//投手
		enemy.draw(Palette::Blue);
		//プレイヤー(バット)
		player.rotatedAt(player.pos, radian).draw(collided ? Palette::Gray : Palette ::Gray);

		
	}

};