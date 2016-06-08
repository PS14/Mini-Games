#pragma once
#include"../../Object/Object.h"



class Invader_Game : public MyApp::Scene
{
private:

	Triangle player{ 300, 400, 20.0};
	Vec2 playerSpeed{ 0,0 };
	const Vec2 g{ 0,0.5 };

	Array<Vec2> shots, bullets;

	int32 count = 0;

	Vec2 enemySpeed{ 0,0 };
	Rect enemy;

	const Texture enemy_tes{ L"res/texture/enemy.jpg" };
	
public:

	void update() override
	{
		playerSpeed += g;
		++count;

		for (auto& shot : shots)
			shot.y -= 8.0;

		for (auto& bullet : bullets)
			bullet.y += 2.0;

		//ˆÚ“®
		if (Input::KeyRight.pressed)
		{
			playerSpeed = { 8.0 ,0};
			player.moveBy(playerSpeed);
		}

		if (Input::KeyLeft.pressed)
		{
			playerSpeed = { -8.0 ,0};
			player.moveBy(playerSpeed);
		}

		//‘Å‚Â
		if (Input::KeySpace.released && count % 4 == 0)
		{
			shots.push_back(player.p0);
		}
		
		//‰æ–ÊØ‚è‘Ö‚¦
		if (Input::KeyControl.pressed)
		{
			++m_data->counter;
			changeScene(L"Result");
		}
	}

	void draw() const override
	{
		Window::ClientRect().draw(Palette::Black);

	
		for (int32 y = 0; y < 3; ++y)
		{
			for (int32 x = 0; x < 5; ++x)
			{
				enemy_tes.resize(40,40).draw((x * 120) + 50, y * 80);
	
			}
		}
		for (const auto& shot : shots)
			Circle(shot, 7).draw(Palette::Orange);

		for (const auto& bullet : bullets)
			Circle(bullet, 4).draw();
		
		player.draw(Palette::Lightblue);

	}
};
