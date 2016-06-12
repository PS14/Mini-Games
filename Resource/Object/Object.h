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
	L"1. 15�p�Y��(��)",
	L"2. �싅",
	L"3. �I����",
	L"4. �u���b�N����",
	L"5. �˓I(��)",
};

struct Application
{
	String name;
	
	String changeScene;
	Texture thumbnail;
};




// �V�[���̃L�[�̌^�ƁA���L�f�[�^�̌^���w��
using MyApp = SceneManager<String, CommonData>;