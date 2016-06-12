#pragma once
#include"stdafx.h"
#include <HamFramework.hpp>

struct CommonData
{
	int counter = 0;
	Font font{ 20 };
};

const Array<String> texts =
{
	L"1. 15パズル(仮)",
	L"2. 野球",
	L"3. 的当て",
	L"4. ブロック崩し",
	L"5. 射的(仮)",
};

struct Application
{
	String name;
	
	String changeScene;
	Texture thumbnail;
};




// シーンのキーの型と、共有データの型を指定
using MyApp = SceneManager<String, CommonData>;