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
	//�v���C���[
	const Rect player = Rect{ 270, 420, 70, 10 };
	
	//����
	Triangle enemy = Triangle{ 320,180,30.0 };

	//�{�[��
	Circle ball = Circle{ 320,180,10 };

	const double speed = 8.0;

	//�X�R�A
	int32 score;
	
	std::vector<Circle> bullet_vector;
	bool collided;
	int32 ball_speed = 3 ;

public:

	void update() override
	{
		bgm.play();
		bgm.setVolume(0.1);
		
		//��ʐ؂�ւ�
		if (Input::KeyControl.pressed)
		{
			
			changeScene(L"Result");
		}

		//�o�b�g��U��
		if (Input::KeySpace.pressed)
		{
			radian -= 0.1;
		}
	
		collided = false;
		//�{�[�������
		if (Input::MouseL.clicked)
		{
			bullet_vector.push_back(ball);
		}

		//�{�[���̓���
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
		//�w�i
		Window::ClientRect().draw(HSV(120, 0.5, 0.7));

		//�摜
		texture.resize(700, 550).draw(-30, -50);

		//�X�R�A�\��
		m_data->font(L"score : ", score).drawCenter(100, 100);
		
		for (auto i = 0; i < bullet_vector.size(); i++)
		{
			bullet_vector[i].draw(Palette::White);
		}

		//����
		enemy.draw(Palette::Blue);
		//�v���C���[(�o�b�g)
		player.rotatedAt(player.pos, radian).draw(collided ? Palette::Gray : Palette ::Gray);

		
	}

};