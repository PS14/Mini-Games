#pragma once
#include"../../Object/Object.h"

class Menu : public MyApp::Scene
{
private:
	const int32 font_size = 18;
	const Font font{ font_size, Typeface::Light };

	//音
	const Sound sound{ L"Resource/Sound/button.mp3" };
	const Sound bgm{ L"Resource/Sound/Menu.mp3" };
	const Sound cursor{ L"Resource/Sound/cursor.mp3" };


	//画像
	const Texture tex_puzzle{ Image(L"Resource/Texture/image (1).png").scale(270, 180) };
	const Texture tex_bat{ Image(L"Resource/Texture/baseballstadium.png").scale(270, 180) };
	const Texture tex_block{ Image(L"Resource/Texture/image (3).png").scale(270, 180) };
	const Texture tex_target{ Image(L"Resource/Texture/image (2).png").scale(270, 180) };
	
	 
	const Array<Application> applications =
	{
		{ L"1. 15パズル"		, L"changeScene(PuzzleGame_Menu)",tex_puzzle ,L"" },
		{ L"2. バッティング"	, L"changeScene(BattingGame_Menu)", tex_bat,L"" },
		{ L"3. ブロック崩し" , L"changeScene(BrokenstickGame_Menu)",tex_block,L"" },
		{ L"4. 的当て"		, L"changeScene(ShootingGame_Menu)",tex_target,L"" },
	};

	Optional<ProcessInfo> process;

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


		for (auto i : step(applications.size()))
		{
			const Rect rect(40 + i % 2 * 20, 40 + i * 80, 250, 60);

			if (rect.leftClicked)
			{
				process = System::CreateProcess(applications[i].changeScene,applications[i].option);
			}
		}
		
		//key1を押したら→PuzzleGameへ
		if (Input::Key1.pressed || Input::KeyNum1.pressed)
		{
			sound.playMulti(0.5);
			changeScene(L"PuzzleGame_Menu");
		}

		//key2を押したら→BaseBall
		if (Input::Key2.pressed || Input::KeyNum2.pressed)
		{
			sound.playMulti(0.5);
			changeScene(L"BattingGame_Menu");
		}

		//key3押したら→ブロック崩し
		if (Input::Key3.pressed || Input::KeyNum3.pressed)
		{
			sound.playMulti(0.5);
			changeScene(L"BrokenstickGame_Menu");
		}

		//key3を押したら→的当て
		if (Input::Key4.pressed || Input::KeyNum4.pressed)
		{
			sound.playMulti(0.5);
			changeScene(L"ShootingGame_Menu");
		}
	}

	void draw() const override
	{
		Window::ClientRect().draw(Palette::Papayawhip);
		
		size_t currentIndex = 0;

		m_data->font(L"１～４のキーを").draw(300, 10, Palette::Green);
		m_data->font(L"押してスタート！").draw(350, 40, Palette::Green);
		
		
		for (auto i : step(applications.size()))
		{
			const Rect rect(40 + i % 2 * 20, 40 + i * 80, 250, 60);

			if (rect.mouseOver)
			{
				currentIndex = i;
			}

			/*if (rect.leftClicked)
			{
				m_data->font(L"Click！！").draw(10, 10,Palette::Black);
			}*/
			const bool selected = (currentIndex == i);

			Graphics2D::SetTransform(Mat3x2::Rotate(Radians(selected ? 3 : 1), rect.pos));
			rect.drawShadow({ 1, 1 }, 12, -1, ColorF(0, 0.4));
			Graphics2D::SetTransform(Mat3x2::Identity());

			rect.draw(HSV(i * 40, 0.6, selected ? 1.0 : 0.95));
			font(applications[i].name).draw(rect.pos.movedBy(24, 8), Palette::Black);

		}
		const Vec2 pinPos(465, 250);
		
		Rect(330, 340, tex_puzzle.size).drawShadow({ 2, 2 }, 12, 3, ColorF(1, 0.4));
		Rect(330, 340, tex_bat.size).drawShadow({ 2, 2 }, 12, 3, ColorF(1, 0.4));
		Rect(330, 340, tex_block.size).drawShadow({ 2, 2 }, 12, 3, ColorF(1, 0.4));
		Rect(330, 340, tex_target.size).drawShadow({ 2, 2 }, 12, 3, ColorF(1, 0.4));
		applications[currentIndex].thumbnail.draw(330, 240).drawFrame(10, 0).stretched(-10).drawFrame(1, 0, Palette::Gray);
		Graphics2D::SetTransform(Mat3x2::Identity());

		Circle(pinPos, 6).drawShadow({ 3, 3 }, 4, 1);
		Circle(pinPos, 6).draw(HSV(0, 0.7, 0.9)).stretched(-2).draw(HSV(0, 0.5, 0.4));
	
		
	
	}
};
