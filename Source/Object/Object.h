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
	Texture thumbnail;
	String option;
	

};




// �V�[���̃L�[�̌^�ƁA���L�f�[�^�̌^���w��
using MyApp = SceneManager<String, CommonData>;