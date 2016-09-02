#pragma once
#include"stdafx.h"
#include <HamFramework.hpp>

struct CommonData
{
	int counter = 0;
	Font font{ 20 };
	
};


struct Application
{
	String name;
	String changeScene;

	//String option;
	String description;
	Texture thumbnail;
};




// �V�[���̃L�[�̌^�ƁA���L�f�[�^�̌^���w��
using MyApp = SceneManager<String, CommonData>;