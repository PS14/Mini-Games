#pragma once
#include"../../Object/Object.h"

class Brokenstick_Game : public MyApp::Scene
{
private:

	//���y
	const Sound sound{ L"Resource/Sound/explosion.mp3" };
	const Sound bgm{ L"Resource/Sound/Brokenstick_Game.mp3" };

	const Point blockSize{ 30 , 20 };
	//�l�p
	Rect wall{ 60,10 };
	//�~
	Circle ball{ 320,400,8 };
	//�{�[���̑���
	const double speed = 8.0;

	//���W
	Vec2 ballSpeed{ 0,-speed };
	//�u���b�N�̓��I�z��
	Array<Rect> blocks;
	//�c�萔
	int32 count = 105;

	//�e�L�X�g�ɏ�������
	TextWriter writer{ L"Resource/Text/block_score.txt" };

public:

	void init() override
	{
		//�u���b�N�̏�����
		//step�N���X
		for (auto p : step({ Window::Width() / blockSize.x, 5 }))
		{
			//�R���e�i�@push_back �� emplace_back
			//movedBy	���W�����炷    
			blocks.emplace_back((p * blockSize).movedBy(0, 60), blockSize);
		}
	}

	void update() override
	{
		//���y�Đ�
		bgm.play();
		//���ʐݒ�
		bgm.setVolume(0.1);
		//Control�L�[����������
		if (Input::KeyControl.pressed)
		{
			//��ʂ̐؂�ւ�
			changeScene(L"Brokenstick_Result");
		}
		//�ړ�
		ball.moveBy(ballSpeed);
		//�ǂ𒆐S�Ɉړ�����
		wall.setCenter(Mouse::Pos().x, 420);

		for (auto it = blocks.begin(); it != blocks.end(); ++it)
		{
			//�����ǂɓ���������
			if (it->intersects(ball))
			{
				(it->bottom.intersects(ball) || it->top.intersects(ball) ? ballSpeed.y : ballSpeed.x) *= -1;
				//�u���b�N������
				blocks.erase(it);
				//���ʉ��Đ�
				sound.playMulti(0.1);
				

				count -= 1;
				break;
			}
			//�����u���b�N���Ȃ��Ȃ�����I��
			if (count == 0)
			{
				changeScene(L"GameClear");
			}
		}
		//��ʂ̏�𒴂�����͂˕Ԃ�
		if (ball.y < 0 && ballSpeed.y < 0)
		{
			ballSpeed *= -1;
		}
		//��ʂ̏c�𒴂�����͂˕Ԃ�
		if (ball.x < 0 && ballSpeed.x < 0 || (Window::Width() < ball.x && ballSpeed.x > 0))
		{
			ballSpeed.x *= -1;
		}
		//�v���C���[�ɓ���������͂˕Ԃ�
		if (ballSpeed.y > 0 && wall.intersects(ball))
		{
			ballSpeed = Vec2((ball.x - wall.center.x) / 8, -ballSpeed.y).setLength(speed);
		}

		//��ʂ̉��𒴂�����
		if (ball.y > 600)
		{
			//��ʂ̐؂�ւ�
			changeScene(L"GameOver");
			//�e�L�X�g�ɏ�������
			writer.writeln(L"�c��", count, L"��");
		
		}
		//��ʒ[�ɍs���Ȃ��悤�ɂ���
		if (wall.x < 0 )
		{
			wall.setCenter(30, 420);
		}
		if (wall.x > Window::Width() - 30)
		{
			wall.setCenter(Window::Width() - 30, 420);

		}

	}

	void draw() const override
	{
		//�u���b�N�̕`��
		for (auto const& block : blocks)
		{
			//stretched �L�k���������`
			//HSV�F���(H : �F���@, S : �ʓx, V : ���x)
			block.stretched(-3).draw(HSV(block.y - 40));
		}

		//�`��
		ball.draw();
		wall.draw();
		
	}
};