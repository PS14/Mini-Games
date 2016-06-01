
#include"Resource\Object\stdafx.h"
#include"Resource\Scene\Title\Title.h"
#include"Resource\Scene\Menu\Menu.h"
#include "Resource\Scene\Game\PuzzleGame.h"
#include"Resource\Scene\Game\Shootinggame.h"
#include"Resource\Scene\Game\baseballgame.h"
#include"Resource\Scene\Game\InvaderGame.h"
#include"Resource\Scene\Game\TargetGame.h"
#include"Resource\Scene\Result\Result.h"

void Main()
{
	MyApp manager;

	// シーンを設定
	manager.add<Title>(L"Title");
	manager.add<Menu>(L"Menu");
	manager.add<PuzzleGame>(L"PuzzleGame");
	manager.add<Shootinggame>(L"Shootinggame");
	manager.add<BaseBall>(L"BaseBall");
	manager.add<Invader>(L"Invader");
	manager.add<TargetGame>(L"TargetGame");
	manager.add<Result>(L"Result");

	while (System::Update())
	{
		if (!manager.updateAndDraw())
			break;
	}
}
