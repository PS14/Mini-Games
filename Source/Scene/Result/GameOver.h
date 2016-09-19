#pragma once
#include"../../Object/Object.h"

class GameOver : public MyApp::Scene
{
private:

	const Sound bgm{ L"Res/Sound/gameover.mp3" };

public:

	void update() override
	{
		bgm.play();

		//リトライ
		if (Input::KeyR.pressed)
		{
			changeScene(L"BrokenstickGame_Menu");
		}

		//タイトルへ
		if (Input::KeySpace.pressed)
		{
			changeScene(L"Title");
		}
	}

	void draw() const override
	{
		m_data->font(L"GAME OVER").draw(150, 100, Palette::Red);
		m_data->font(L"Rキー で リトライ").draw(150, 150, Palette::Yellow);
		m_data->font(L"スペースキー で タイトル").draw(150, 200, Palette::Blue);
	}

};