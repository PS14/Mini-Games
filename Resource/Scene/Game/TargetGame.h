#pragma once
#include"../../Object/Object.h"

class Target_Game : public MyApp::Scene
{
private:

	//キャラ
	const Texture tex1_1{ L"Res/Texture/シンデレラ_ドレス.png" };
	const Texture tex1_2{ L"Res/Texture/キューブ.jpg" };
	const Texture tex1_3{ L"Res/Texture/コマ.png" };
	const Texture tex1_4{ L"Res/Texture/王子.png" };
	const Texture tex1_5{ L"Res/Texture/熊.png" };
	const Texture tex2_1{ L"Res/Texture/ロボット.png" };
	const Texture tex2_2{ L"Res/Texture/町男水やり.png" };
	const Texture tex2_3{ L"Res/Texture/カード.jpg" };
	const Texture tex2_4{ L"Res/Texture/町娘.png" };
	const Texture tex2_5{ L"Res/Texture/店主.png" };
	const Texture tex3_1{ L"Res/Texture/PS2.jpg" };
	const Texture tex3_2{ L"Res/Texture/Creeper.png" };
	const Texture tex3_3{ L"Res/Texture/本.png" };
	const Texture tex3_4{ L"Res/Texture/箱.png" };
	const Texture tex3_5{ L"Res/Texture/ルンバ.png" };
	//カーソル
	const Texture target{ L"Res/Texture/target.png" };
	//サウンド
	const Sound  bgm{ L"Res/Sound/Target_Game.mp3" };

	int32 count = 0;

	const Rect rect1{50,50,200,200};
	const Rect rect2{50,100,130,50};
	const Rect rect3{100,100,130,50};

public:

	void init() override
	{
		count = 5;
		
	}

	void update() override
	{
		bgm.play();
		bgm.setVolume(0.1);

		if (Input::KeyControl.pressed)
		{
			changeScene(L"Result");
		}

		if (Input::MouseL.clicked)
		{
			count--;
		}

		if (count == 0)
		{
			changeScene(L"Result");
		}

		

	}

	void draw() const override
	{
		Window::ClientRect().draw({ 255,255,255 });

		const Rect collision(Mouse::Pos(), 50,50);
		const bool r1 = collision.intersects(rect1);
		const bool r2 = collision.intersects(rect2);
		const bool r3 = collision.intersects(rect3);


		//1-1
		tex1_1.resize(50, 100).draw(r2 ? 130, 0 : 130, 0,Alpha(180));
		//1-2
		tex1_2.resize(50, 50).draw(r1 ? 200, 50 : 200, 50, Alpha(180));
		//1-3
		tex1_3.resize(50, 50).draw(r1 ? 270, 50 : 270, 50, Alpha(180));
		//1-4
		tex1_4.resize(50, 100).draw(r2 ? 350, 0 : 350, 0, Alpha(180));
		//1-5
		tex1_5.resize(50, 70).draw(r2 ? 420, 30 : 420, 30, Alpha(180));
		//2-1
		tex2_1.resize(50, 100).draw(r2 ? 130, 130 : 130, 130, Alpha(180));
		//2-2
		tex2_2.resize(50, 100).draw(r2 ? 200, 130 : 200, 130, Alpha(180));
		//2-3
		tex2_3.resize(50, 50).draw(r1 ? 270, 180 : 270, 180, Alpha(180));
		//2-4
		tex2_4.resize(50, 100).draw(r2 ? 350, 130 : 350, 130, Alpha(180));
		//2-5
		tex2_5.resize(50, 100).draw(r2 ? 420, 130 : 420, 130, Alpha(180));
		//3-1
		tex3_1.resize(50, 100).draw(r2 ? 130, 260 : 130, 260, Alpha(180));
		//3-2
		tex3_2.resize(50, 100).draw(r2 ? 200, 260 : 200, 260, Alpha(180));
		//3-3
		tex3_3.resize(50, 50).draw(r1 ? 270, 300 : 270, 300, Alpha(180));
		//3-4
		tex3_4.resize(50, 50).draw(r1 ? 350, 320 : 350, 320, Alpha(180));
		//3-5
		tex3_5.resize(50, 50).draw(r1 ? 420, 310 : 420, 310, Alpha(180));

		
		//枠
		for (int32 i = 0; i < 3; ++i)
		{
			Rect(100, (i * 130) + 100, 400, 20).draw({ 173,140,56 });
		}

		//描画
		Rect(70, 0, 30, 500).draw({ 173,140,56 });
		Rect(500, 0, 30, 500).draw({ 173,140,56 });
		//collision.draw();

		//カーソルに画像を描画
		target.resize(40, 40).draw((Mouse::Pos().x - 20), (Mouse::Pos().y - 20));
		//文字
		m_data->font(L"あと", count, L"回").draw(500, 400, Palette::Black);
	}
};