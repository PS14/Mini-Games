#pragma once
#include"stdafx.h"
#include <HamFramework.hpp>

struct CommonData
{
	int counter = 0;
	Font font{ 20 };
};



// �V�[���̃L�[�̌^�ƁA���L�f�[�^�̌^���w��
using MyApp = SceneManager<String, CommonData>;