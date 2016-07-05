#pragma once
#include"../../Object/Object.h"

class Target_Game : public MyApp::Scene
{
private:

	//キャラ
	const Texture tex1_1{ L"res/texture/シンデレラ_ドレス.png"};
	const Texture tex1_2{ L"res/texture/キューブ.jpg" };
	const Texture tex1_3{ L"res/texture/コマ.png" };
	const Texture tex1_4{ L"res/texture/王子.png" };
	const Texture tex1_5{ L"res/texture/熊.png" };
	const Texture tex2_1{ L"res/texture/ロボット.png" };
	const Texture tex2_2{ L"res/texture/町男水やり.png" };
	const Texture tex2_3{ L"res/texture/カード.jpg" };
	const Texture tex2_4{ L"res/texture/町娘.png" };
	const Texture tex2_5{ L"res/texture/店主.png" };
	const Texture tex3_1{ L"res/texture/PS2.jpg" };
	const Texture tex3_2{ L"res/texture/Creeper.png" };
	const Texture tex3_3{ L"res/texture/本.png" };
	const Texture tex3_4{ L"res/texture/箱.png" };
	const Texture tex3_5{ L"res/texture/ルンバ.png" };
	//カーソル
	const Texture target{ L"res/texture/target.png" };
	//サウンド
	const Sound  bgm{ L"res/Sound/Target_Game.mp3" };

	int32 count = 0;

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
		Window::ClientRect().draw({255,255,255 });

		//1-1
		tex1_1.resize(50,100).draw(130,0);
		//1-2
		tex1_2.resize(50, 50).draw(200,50);
		//1-3
		tex1_3.resize(50, 50).draw(270, 50);
		//1-4
		tex1_4.resize(50, 100).draw(350, 0);
		//1-5
		tex1_5.resize(50, 70).draw(420, 30);
		//2-1
		tex2_1.resize(50, 100).draw(130, 130);
		//2-2
		tex2_2.resize(50, 100).draw(200, 130);
		//2-3
		tex2_3.resize(50, 50).draw(270, 180);
		//2-4
		tex2_4.resize(50, 100).draw(350, 130);
		//2-5
		tex2_5.resize(50, 100).draw(420, 130);
		//3-1
		tex3_1.resize(50, 100).draw(130, 260);
		//3-2
		tex3_2.resize(50, 100).draw(200, 260);
		//3-3
		tex3_3.resize(50, 50).draw(270, 300);
		//3-4
		tex3_4.resize(50, 50).draw(350, 320);
		//3-5
		tex3_5.resize(50, 50).draw(420, 310);
	
		//枠
		for (int32 i = 0; i < 3; ++i)
		{
			Rect(100, (i * 130) + 100, 400, 20).draw({173,140,56});
		}
		
		//描画
		Rect(70, 0, 30, 500).draw({ 173,140,56 });
		Rect(500, 0, 30, 500).draw({ 173,140,56 });

		//カーソルに画像を描画
		target.resize(40, 40).draw((Mouse::Pos().x - 20), (Mouse::Pos().y - 20));
		//文字
		m_data->font(L"あと",count, L"回").draw(500, 400,Palette::Black);
	}
};