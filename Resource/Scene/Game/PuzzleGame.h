#pragma once
#include"../../Object/Object.h"
#include"../../Collision/Collision.h"


class Puzzle_Game : public MyApp::Scene
{
private:
	//時間
	Stopwatch stopwatch;
	//枠
	const Rect puzzle_rect{ 50, 50, 400, 400 };
	const Rect finished_rect{ 480, 230, 150, 200 };
	//四角の動的配列
	//Optional 無効値
	std::array<Optional<int32>, 16> pieces =
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

	const int32 pieceSize = 100;
	//画像
	const Texture texture{ L"res/texture/miku.jpg" };
	//音
	const Sound bgm{ L"res/Sound/Puzzle_Game.mp3" };
	//Optional 無効値
	Optional<int32> grabbed;

public:

	void init() override
	{
		//ランダム配置
		for (int32 i = 0; i < 10000; ++i)
		{
			//ランダム配置
			const int32 a = Random(0, 15);
			const int32 b = a + RandomSelect({ -4, -1, 1, 4 });
			//入れ替え判定
			if (pieces[a] && InRange(b, 0, 15) && !pieces[b] && Swappable(a, b))
			{
				std::swap(pieces[a], pieces[b]);
			}
		}
	}

	void update() override
	{
	

		//時間START
		stopwatch.start();
		//音楽再生
		bgm.play();
		//音量設定
		bgm.setVolume(0.1);

		//画面切り替え
		if (Input::KeyControl.pressed)
		{
			changeScene(L"Result");
			//時間Reset
			stopwatch.reset();
		}

		//操作
		if (!Input::MouseL.pressed)
		{
			grabbed = none;
		}

		for (auto i : step(16))
		{

			const Rect pieceRect(i % 4 * pieceSize + 50, i / 4 * pieceSize + 50, pieceSize, pieceSize);

			if (!pieces[i])
			{
				//入れ替え
				if (grabbed && pieceRect.mouseOver && Swappable(i, grabbed.value()))
				{
					std::swap(pieces[i], pieces[grabbed.value()]);
					grabbed = none;
				}
				continue;
			}

			if (pieceRect.leftPressed)
			{
				grabbed = i;
			}
		}
	}

	void draw() const override
	{
		Optional<int32> grabbed;

		//操作
		if (!Input::MouseL.pressed)
		{
			grabbed = none;
		}

		for (auto i : step(16))
		{
			const Rect pieceRect(i % 4 * pieceSize + 50, i / 4 * pieceSize + 50, pieceSize, pieceSize);

			if (!pieces[i])
			{
				//入れ替え
				if (grabbed && pieceRect.mouseOver && Swappable(i, grabbed.value()))
				{
					grabbed = none;
				}
				continue;
			}

			const int offset = pieces[i].value();
			pieceRect(texture.uv(offset % 4 * 0.25, offset / 4 * 0.25, 0.25, 0.25)).draw();


			if (pieceRect.leftPressed)
			{
				grabbed = i;
				pieceRect.draw({ 255, 0, 0, 80 });
			}
			pieceRect.drawFrame();
		}

		//枠
		puzzle_rect.drawFrame(0, 5, Palette::Lightsalmon);
		finished_rect.drawFrame(0, 5, Palette::Lightblue);
		//完成図
		texture.resize(150, 200).draw(480, 230);

		m_data->font(L"完成図").draw(500, 180, Palette::Yellow);
		m_data->font(stopwatch.s(), L"秒").draw(500, 10);
	}
};
