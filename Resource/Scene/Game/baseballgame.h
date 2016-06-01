#pragma once
#include"../../Object/Object.h"

class BaseBall : public MyApp::Scene
{
private:
	//�摜
	const Texture texture{ L"res/texture/baseballstadium.png" };
	const Texture ball_texture{ L"res/texture/ball.png" };
	//��]()
	const double degree = 45;
	double radian = Radians(degree);
	//�v���C���[���W
	double player_x = 270;
	double player_y = 420;

	const double speed = 2.0;

	const Rect player{ player_x, player_y, 70, 10 };
	const Rect enemy{ 300, 180, 40, 40 };

	Circle ball{ 320,180,10 };
	Vec2 ball_Speed{ 0, speed };
	Array<Vec2> shots, bullets;
	int32 score;
	int32 count;



public:

	void update() override
	{
		ball.moveBy(ball_Speed);

		for (auto& shot : shots)
		{
			shot.y -= 7.0;
		}

		for (auto& bullet : bullets)
		{
			bullet.y += 2.0;
		}

		//��ʐ؂�ւ�
		if (Input::KeyControl.pressed)
		{
			++m_data->counter;
			changeScene(L"Result");
		}

		//�o�b�g��U��
		if (Input::KeySpace.pressed)
		{
			radian -= 0.1;
		}
		
		//ball���G�ꂽ��
		if (ball_Speed.y > 0 && player.intersects(ball))
		{
			ball_Speed = Vec2((ball.x - player.center.x) / 8, -ball_Speed.y).setLength(speed);

			score += 1;
		}

		ball.y += 2.0;
		
	}


	void draw() const override
	{
		//�w�i
		Window::ClientRect().draw(HSV(120, 0.5, 0.7));

		
		//�摜
		texture.resize(700, 550).draw(-30, -50);
		
		ball.draw();
		
		m_data->font(L"score : ", score).drawCenter(100, 100);

		//����
		enemy.draw(Palette::Blue);
		//�v���C���[(�o�b�g)
		player.rotatedAt(player.pos, radian).draw(Palette::Gray);
		//Player.draw(Palette::Black);
	}

};