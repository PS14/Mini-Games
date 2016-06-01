#pragma once
#include"../../Object/Object.h"

class Result : public MyApp::Scene
{
private:

	const Sound sound{ L"res/Sound/Fin.mp3" };

	const int32 w = 100, h = 100;

	Array<Particle> particles{ w * h };

	const Texture texture{ L"Example/Particle.png", TextureDesc::For3D };

public:

	void init() override
	{
		for (int32 y = 0; y < h; ++y)
		{
			for (int32 x = 0; x < w; ++x)
			{
				const Vec3 pos = RandomVec3({ -20,20 }, { -0.2,4 }, { -20,20 });

				const ColorF color = HSV(pos.y * 20.0);

				particles[y * w + x] = Particle(pos, 0.5, color);
			}
		}
	}

	void update() override
	{
		sound.play();

		sound.setVolume(0.1);

		if (Input::KeyControl.pressed)
		{
			++m_data->counter;
			changeScene(L"Title");
		}

	}

	void draw() const override
	{
		Graphics3D::SetBlendStateForward(BlendState::Additive);
		Graphics3D::SetDepthStateForward(DepthState::TestOnly);

		Graphics3D::FreeCamera();

		m_data->font(L"èIóπ").draw(Window::Center());

		Graphics3D::DrawParticlesForward(particles, texture);
	
	}
};
