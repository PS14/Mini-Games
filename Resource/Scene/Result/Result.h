#pragma once
#include"../../Object/Object.h"

class Result : public MyApp::Scene
{
private:

	const Sound sound{ L"res/Sound/Fin.mp3" };

	const Texture textureGrass{ L"Example/Grass.jpg", TextureDesc::For3D };
	const Texture texture{ L"Example/Particke.png",TextureDesc::For3D };

	Array<Particle> particles{ 400 };

public:

	void init() override
	{
		for (auto& particle : particles)
		{
			const Vec3 pos = RandomVec3({ -20,20 }, { -0.2,4 }, { -20,20 });

			particle = Particle(pos, 0.2, ColorF(1.0, 0.6, 0.0));

		}


		
	}

	void update() override
	{
		sound.play();

		sound.setVolume(0.1);

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

		if (Input::KeyControl.pressed)
		{
			++m_data->counter;
			changeScene(L"Title");
		}

	}

	void draw() const override
	{
		
		Graphics::SetBackground(Color(20, 40, 60));
		Graphics3D::SetLight(0, Light::None());

		Graphics3D::FreeCamera();

		Plane(40).draw(textureGrass);

		Graphics3D::DrawParticlesForward(particles, texture);

		m_data->font(L"èIóπ").draw(Window::Center());

	}
};
