#pragma once
#pragma once
#include"../../Object/Object.h"

class Batting_Game : public MyApp::Scene
{
private:
	//�摜
	const Texture texture{ L"res/texture/baseballstadium.png" };
	const Texture ball_texture{ L"res/texture/ball.png" };
	//��
	const Sound hit{ L"res/Sound/hit.mp3" };
	const Sound bgm{ L"res/Sound/Baseball.mp3" };
	
	//��]()
	const double degree = 45;
	double radian = Radians(degree);
	//�v���C���[���W
	double player_x = 270;
	double player_y = 420;

	const double speed = 2.0;

	const Rect player{ player_x, player_y, 70, 10 };
	Triangle enemy{ 320,180,30.0 };

	Vec2 ball_Speed{ 0, speed };
	
	Circle ball{ 320,180,10 };
	int32 score;
	int32 count = 0;

public:

	void update() override
	{
		bgm.play();
		bgm.setVolume(0.1);

		ball.moveBy(ball_Speed);
		ball.y += speed;

		++count;

		//if (count % 60 == 0)
		//{
		//	ball.y += speed;
		//}

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
			hit.play();
			ball_Speed = Vec2((ball.x - player.center.x) / 8, -ball_Speed.y).setLength(speed);
			score += 1;
		}

		
	}

	void draw() const override
	{
		//�w�i
		Window::ClientRect().draw(HSV(120, 0.5, 0.7));

		//�摜
		texture.resize(700, 550).draw(-30, -50);

		ball.draw();
		//�X�R�A�\��
		m_data->font(L"score : ", score).drawCenter(100, 100);
		
		//����
		enemy.draw(Palette::Blue);
		//�v���C���[(�o�b�g)
		player.rotatedAt(player.pos, radian).draw(Palette::Gray);
		
	}

};