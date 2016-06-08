#pragma once
#include "../../Object/Object.h"

class Title : public MyApp::Scene
{
private:
	//�T�E���h
	const Sound sound{ L"res/Sound/button.mp3" };
	const Sound t_sound{ L"res/Sound/Title.mp3" };



public:

	void update() override
	{
		//�T�E���h�Đ�
		t_sound.play();

		t_sound.setVolume(0.2);
	
		//Enter���������灨���j���[��
		if (Input::KeyEnter.pressed)
		{
			sound.playMulti(0.5);
			++m_data->counter;
			changeScene(L"Menu");
		}
	}

	void draw() const override
	{
		//�w�i
		Window::ClientRect().draw(Palette::Lightblue);
		
		//����
		m_data->font(L"THE�EMiniGames").draw(150, 50, Palette::Black);
		m_data->font(L"Enter key�@To  Start").draw(200, 300, Palette::Green);

	}

};
