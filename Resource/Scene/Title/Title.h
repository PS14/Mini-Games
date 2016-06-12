#pragma once
#include "../../Object/Object.h"

class Title : public MyApp::Scene
{
private:
	//サウンド
	const Sound sound{ L"res/Sound/button.mp3" };
	const Sound t_sound{ L"res/Sound/Title.mp3" };



public:

	void update() override
	{
		//サウンド再生
		t_sound.play();

		t_sound.setVolume(0.2);
	
		//Enterを押したら→メニューへ
		if (Input::MouseL.clicked)
		{
			sound.playMulti(0.5);
			++m_data->counter;
			changeScene(L"Menu");
		}
	}

	void draw() const override
	{
		//背景
		Window::ClientRect().draw(Palette::Lightblue);
		
		//文字
		m_data->font(L"THE・MiniGames").draw(150, 50, Palette::Black);
		m_data->font(L"Click To Start").draw(200, 300, Palette::Green);

	}

};
