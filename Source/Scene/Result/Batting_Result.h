#pragma once
#include"../../Object/Object.h"
#include <deque>


class Batting_Result : public MyApp::Scene
{
private:

	//BGM
	const Sound bgm{ L"Resource/Sound/Game_clear.mp3" };

	//テキスト読み込み関係
	TextReader reader{ L"Resource/Text/batting_score.txt" };
	const String s = reader.readAll();

	//枠
	const RoundRect rect{ 120, 200, 400, 200, 10 };
	//画像
	const Texture textureGrass{ L"Example/Grass.jpg", TextureDesc::For3D };
	const Texture texture{ L"Example/Particke.png",TextureDesc::For3D };

	Array<Particle> particles{ 1000 };

public:
	void init() override
	{
		for (auto& particle : particles)
		{
			const Vec3 pos = RandomVec3({ -20,20 }, { -2,4 }, { -20,20 });
			particle = Particle(pos, 0.2, ColorF(0.0, 0.8, 1.0));
		}
	}

	void update() override
	{
		bgm.play();

		bgm.setVolume(0.1);

		for (auto& particle : particles)
		{
			particle.pos.y += 0.01f;

			if (4.0 < particle.pos.y)
			{
				particle.pos.y -= 4.2f;
			}

			const float s = 1.0f - (Abs(2.0f - particle.pos.y) / 2.0f);
			particle.scaling.x = particle.scaling.y = 0.2f * s;
			particle.color.w = s;
		}

		if (Input::MouseL.clicked)
		{
			++m_data->counter;
			changeScene(L"Title");


		}

	}

	void draw() const override
	{
		Window::ClientRect().draw(Palette::Black);

		Graphics::SetBackground(Color(0, 0, 0));
		Graphics3D::SetLight(0, Light::None());
		Graphics3D::SetBlendStateForward(BlendState::Additive);
		Graphics3D::SetDepthStateForward(DepthState::TestOnly);
		Graphics3D::FreeCamera();

		Plane(400).draw(textureGrass);
		Graphics3D::DrawParticlesForward(particles, texture);

		rect.draw(Palette::White);
		rect.drawFrame(0, 5, Palette::Orange);

		m_data->font(s).draw(200, 250, Palette::Black);

		m_data->font(L"終了").draw(150, 100, Palette::Yellow);

	}

};