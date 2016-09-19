#pragma once
#include "../../Object/Object.h"

class Title : public MyApp::Scene
{
private:
	//�T�E���h
	const Sound sound{ L"Resource/Sound/button.mp3" };
	const Sound t_sound{ L"Resource/Sound/Title.mp3" };

	//�摜
	const Texture texture_1{L"Resource/Texture/crane.png"};
	const Texture texture_2{L"Resource/Texture/puzzle.png"};

	const Font font2{ 30, Typeface::Heavy, FontStyle::Outline };

	const int32 cycle = 1200;
	
	 int32 t;

	double a2;

public:

	void update() override
	{
		//�T�E���h�Đ�
		t_sound.play();
		t_sound.setVolume(0.2);
	
		//Enter���������灨���j���[��
		if (Input::MouseL.clicked)
		{
			sound.playMulti(0.5);
			++m_data->counter;
			changeScene(L"Menu");
		}
		
		t = Time::GetMillisec();

		a2 = Sin(t % cycle / static_cast<double>(cycle) * TwoPi) * 0.3 + 0.7;


	}

	void draw() const override
	{
		//�w�i
		Window::ClientRect().draw(Palette::White);
		
		RoundRect(180, 300, 250, 50, 40).draw(Palette::Lightblue);
	
	

		//����
		//m_data->font(L"Click To Start").draw(200, 300, Palette::Green);
		m_data->font(L"Click To Start").draw(200, 300, AlphaF(a2));
	
		font2.changeOutlineStyle( TextOutlineStyle(Palette::Green, Palette::Orange, 2.0) );
		font2(L"THE�EMiniGames").draw(150, 50);
	}

};
