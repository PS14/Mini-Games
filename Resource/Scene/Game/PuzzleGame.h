#pragma once
#include"../../Object/Object.h"
#include"../../Collision/Collision.h"

class PuzzleGame : public MyApp::Scene
{
private:
	//ŽžŠÔ
	Stopwatch stopwatch;

	const Rect puzzle_rect{ 50, 50, 400, 400 };
	const Rect finished_rect{ 480, 230, 150, 200 };

	std::array<Optional<int32>, 16> pieces =
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

	const int32 pieceSize = 100;

	const Texture texture{ L"res/texture/miku.jpg" };
	const Sound sound{ L"res/Sound/game_sound.mp3" };

public:

	void init() override
	{
		//ƒ‰ƒ“ƒ_ƒ€”z’u
		for (int i = 0; i < 10000; ++i)
		{
			const int a = Random(0, 15);
			const int b = a + RandomSelect({ -4, -1, 1, 4 });

			if (pieces[a] && InRange(b, 0, 15) && !pieces[b] && Swappable(a, b))
			{
				std::swap(pieces[a], pieces[b]);
			}
		}
	}

	void update() override
	{
		//ŽžŠÔSTART
		stopwatch.start();

		sound.play();

		sound.setVolume(0.1);

		if (Input::KeyControl.pressed)
		{
			++m_data->counter;
			changeScene(L"Result");
			stopwatch.reset();
		}
	}

	void draw() const override
	{
		Optional<int32> grabbed;

		//‘€ì
		if (!Input::MouseL.pressed)
		{
			grabbed = none;
		}

		for (auto i : step(16))
		{
			const Rect pieceRect(i % 4 * pieceSize + 50, i / 4 * pieceSize + 50, pieceSize, pieceSize);

			if (!pieces[i])
			{
				//“ü‚ê‘Ö‚¦
				if (grabbed && pieceRect.mouseOver && Swappable(i, grabbed.value()))
				{
					//?
					//std::swap(pieces[i], pieces[grabbed.value()]);
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

		//˜g
		puzzle_rect.drawFrame(0, 5, Palette::Lightsalmon);
		finished_rect.drawFrame(0, 5, Palette::Lightblue);
		//Š®¬}
		texture.resize(150, 200).draw(480, 230);

		m_data->font(L"Š®¬}").draw(500, 180, Palette::Yellow);
		m_data->font(stopwatch.s(), L"•b").draw(500, 10);
	}
};
