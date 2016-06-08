#pragma once
#include"../../Object/Object.h"

class GameOver : public MyApp::Scene
{
private:

public:

	void update() override
	{
		//リトライ
		if (Input::KeyR.pressed)
		{
			++m_data->counter;
			changeScene(L"BrokenstickGame_Menu");
		}

		//タイトルへ
		if (Input::KeySpace.pressed)
		{
			++m_data->counter;
			changeScene(L"Title");
		}
	}

	void draw() const override
	{

		m_data->font(L"GAME OVER").draw(150, 100, Palette::White);
		m_data->font(L"Key で リトライ").draw(150, 150, Palette::White);
		m_data->font(L"Key で タイトル").draw(150, 170, Palette::White);
	}

};