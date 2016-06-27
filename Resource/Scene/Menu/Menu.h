#pragma once
#include"../../Object/Object.h"

class Menu : public MyApp::Scene
{
private:
	const int32 font_size = 18;
	const Font font{ font_size, Typeface::Light };

	//��
	const Sound sound{ L"res/Sound/button.mp3" };
	const Sound bgm{ L"res/Sound/Menu.mp3" };

	//�摜
	const Texture texture1{ Image(L"res/texture/image (1).png").scale(270, 180) };
	const Texture texture2{ Image(L"res/texture/baseballstadium.png").scale(270, 180) };
	const Texture texture3{ Image(L"res/texture/image (2).png").scale(270, 180) };
	const Texture texture4{ Image(L"res/texture/image (3).png").scale(270, 180) };
	const Texture texture5{ Image(L"res/texture/image (4).png").scale(270, 180) };

	const Array<Application> applications =
	{
		{ L"1. 15�p�Y��"		, L"",texture1 },
		{ L"2. �o�b�e�B���O"	, L"",texture2 },
		{ L"3. �I����"		, L"",texture3 },
		{ L"4. �u���b�N����" , L"",texture4 },
		{ L"5. �˓I(��)"		, L"",texture5 },
	};

	

public:

	void init() override
	{
		Array<double> angleOffsets(applications.size());

		for (auto& angleOffset : angleOffsets)
		{
			angleOffset = Random(-1.5, 1.5);
		}
	}

	void update() override
	{
		bgm.play();

		bgm.setVolume(0.05);

		//key1���������灨PuzzleGame��
		if (Input::Key1.pressed)
		{
			sound.playMulti(0.5);
			++m_data->counter;
			changeScene(L"PuzzleGame_Menu");
		}

		//key2���������灨BaseBall
		if (Input::Key2.pressed)
		{
			sound.playMulti(0.5);
			++m_data->counter;
			changeScene(L"BattingGame_Menu");
		}
		
		//key3���������灨�I����
		if (Input::Key3.pressed)
		{
			sound.playMulti(0.5);
			++m_data->counter;
			changeScene(L"ShootingGame_Menu");
		}

		//key4�������灨�u���b�N����
		if (Input::Key4.pressed)
		{
			sound.playMulti(0.5);
			++m_data->counter;
			changeScene(L"BrokenstickGame_Menu");
		}

		//key5�������Ă灨TargetGame
		if (Input::Key5.pressed)
		{
			sound.playMulti(0.5);
			++m_data->counter;
			changeScene(L"TargetGame_Menu");
		}

	

	}

	void draw() const override
	{
		Window::ClientRect().draw(Palette::Papayawhip);
		
		size_t currentIndex = 0;

		m_data->font(L"�P�`�T�̃L�[��").draw(300, 10, Palette::Green);
		m_data->font(L"�����Ă�������").draw(350, 40, Palette::Green);
		

		for (auto i : step(applications.size()))
		{
			const Rect rect(40 + i % 2 * 20, 40 + i * 80, 250, 60);

			if (rect.mouseOver)
			{
				currentIndex = i;
			}

			const bool selected = (currentIndex == i);

			Graphics2D::SetTransform(Mat3x2::Rotate(Radians(selected ? 3 : 1), rect.pos));
			rect.drawShadow({ 1, 1 }, 12, -1, ColorF(0, 0.4));
			Graphics2D::SetTransform(Mat3x2::Identity());

			rect.draw(HSV(i * 40, 0.6, selected ? 1.0 : 0.95));
			font(applications[i].name).draw(rect.pos.movedBy(24, 8), Palette::Black);
		}

		const Vec2 pinPos(465, 250);

		Rect(330, 340, texture1.size).drawShadow({ 2, 2 }, 12, 3, ColorF(1, 0.4));
		Rect(330, 340, texture2.size).drawShadow({ 2, 2 }, 12, 3, ColorF(1, 0.4));
		Rect(330, 340, texture3.size).drawShadow({ 2, 2 }, 12, 3, ColorF(1, 0.4));
		Rect(330, 340, texture4.size).drawShadow({ 2, 2 }, 12, 3, ColorF(1, 0.4));
		Rect(330, 340, texture5.size).drawShadow({ 2, 2 }, 12, 3, ColorF(1, 0.4));
		applications[currentIndex].thumbnail.draw(330, 240).drawFrame(10, 0).stretched(-10).drawFrame(1, 0, Palette::Gray);
		Graphics2D::SetTransform(Mat3x2::Identity());

		Circle(pinPos, 6).drawShadow({ 3, 3 }, 4, 1);
		Circle(pinPos, 6).draw(HSV(0, 0.7, 0.9)).stretched(-2).draw(HSV(0, 0.5, 0.4));
	
	
	}
};
