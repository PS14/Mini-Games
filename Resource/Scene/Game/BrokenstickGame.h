#pragma once
#include"../../Object/Object.h"

class Brokenstick_Game : public MyApp::Scene
{
private:

	//音楽
	const Sound sound{ L"res/Sound/explosion.mp3" };
	const Sound bgm{ L"res/Sound/Brokenstick_Game.mp3" };
	//ボールの速さ
	const double speed = 8.0;
	const Point blockSize{ 30 , 20 };
	//四角
	Rect wall{ 60,10 };
	//円
	Circle ball{ 320,400,8 };
	//座標
	Vec2 ballSpeed{ 0,-speed };
	//ブロックの動的配列
	Array<Rect> blocks;

public:

	void init() override
	{
		//ブロックの初期化

		for (auto p : step({ Window::Width() / blockSize.x, 5 }))
		{
			//コンテナ　push_back → emplace_back
			//movedBy	座標をずらす    
			blocks.emplace_back((p * blockSize).movedBy(0, 60), blockSize);
		}
	}

	void update() override
	{
		//音楽再生
		bgm.play();
		//音量設定
		bgm.setVolume(0.1);
		//Controlキーを押したら
		if (Input::KeyControl.pressed)
		{
			//画面の切り替え
			changeScene(L"Result");
		}
		//
		ball.moveBy(ballSpeed);
		//壁を中心に移動する
		wall.setCenter(Mouse::Pos().x, 420);

		for (auto it = blocks.begin(); it != blocks.end(); ++it)
		{
			//もし壁に当たったら
			if (it->intersects(ball))
			{
				(it->bottom.intersects(ball) || it->top.intersects(ball) ? ballSpeed.y : ballSpeed.x) *= -1;
				//ブロックを消す
				blocks.erase(it);
				//効果音再生
				sound.playMulti(0.1);

				break;
			}
		}
		//画面の上を超えたらはね返る
		if (ball.y < 0 && ballSpeed.y < 0)
		{
			ballSpeed *= -1;
		}
		//画面の縦を超えたらはね返る
		if (ball.x < 0 && ballSpeed.x < 0 || (Window::Width() < ball.x && ballSpeed.x > 0))
		{
			ballSpeed.x *= -1;
		}
		//壁に当たったらはね返る
		if (ballSpeed.y > 0 && wall.intersects(ball))
		{
			ballSpeed = Vec2((ball.x - wall.center.x) / 8, -ballSpeed.y).setLength(speed);
		}
		//画面の下を超えたら
		if (ball.y > 600)
		{
			//画面の切り替え
			changeScene(L"GameOver");
		}
	}

	void draw() const override
	{
		//ブロックの描画
		for (auto const& block : blocks)
		{
			//stretched 伸縮した長方形
			//HSV色空間(H : 色相　, S : 彩度, V : 明度)
			block.stretched(-3).draw(HSV(block.y - 40));
		}
		if (wall.x < 0 || wall.x > Window::Width())
		{
			m_data->font(L"画面外だよ").drawCenter(240, Palette::Yellow);
		}
		//描画
		ball.draw();
		wall.draw();
	}
};