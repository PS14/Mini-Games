#pragma once
#include"../../Object/Object.h"

class Menu : public MyApp::Scene
{
private:
	const int32 font_size = 18;
	const Font font{ font_size, Typeface::Light };

	//音
	const Sound sound{ L"res/Sound/button.mp3" };
	const Sound bgm{ L"res/Sound/Menu.mp3" };

	//画像
	const Texture texture1{ Image(L"res/texture/image (1).png").scale(270, 180) };
	const Texture texture2{ Image(L"res/texture/baseballstadium.png").scale(270, 180) };
	const Texture texture3{ Image(L"res/texture/image (2).png").scale(270, 180) };
	const Texture texture4{ Image(L"res/texture/image (3).png").scale(270, 180) };
	const Texture texture5{ Image(L"res/texture/image (4).png").scale(270, 180) };

	const Array<Application> applications =
	{
		{ L"1. 15パズル"		, L"",texture1 },
		{ L"2. バッティング"	, L"",texture2 },
		{ L"3. 的当て"		, L"",texture3 },
		{ L"4. ブロック崩し" , L"",texture4 },
		{ L"5. 射的(仮)"		, L"",texture5 },
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

		//key1を押したら→PuzzleGameへ
		if (Input::Key1.pressed)
		{
			sound.playMulti(0.5);
			++m_data->counter;
			changeScene(L"PuzzleGame_Menu");
		}

		//key2を押したら→BaseBall
		if (Input::Key2.pressed)
		{
			sound.playMulti(0.5);
			++m_data->counter;
			changeScene(L"BattingGame_Menu");
		}
		
		//key3を押したら→的当て
		if (Input::Key3.pressed)
		{
			sound.playMulti(0.5);
			++m_data->counter;
			changeScene(L"ShootingGame_Menu");
		}

		//key4押したら→ブロック崩し
		if (Input::Key4.pressed)
		{
			sound.playMulti(0.5);
			++m_data->counter;
			changeScene(L"BrokenstickGame_Menu");
		}

		//key5を押してら→TargetGame
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

		m_data->font(L"１～５のキーを").draw(300, 10, Palette::Green);
		m_data->font(L"押してください").draw(350, 40, Palette::Green);
		

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
