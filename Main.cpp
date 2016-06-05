
#include"Resource\Object\stdafx.h"
#include"Resource\Scene\Title\Title.h"
#include"Resource\Scene\Menu\Menu.h"
#include"Resource\Scene\Game_Menu\BattingGame_Menu.h"
#include"Resource\Scene\Game_Menu\InvaderGame_Menu.h"
#include"Resource\Scene\Game_Menu\PuzzleGame_Menu.h"
#include"Resource\Scene\Game_Menu\ShootingGame_Menu.h"
#include"Resource\Scene\Game_Menu\TargetGame_Menu.h"
#include "Resource\Scene\Game\PuzzleGame.h"
#include"Resource\Scene\Game\ShootingGame.h"
#include"Resource\Scene\Game\BattingGame.h"
#include"Resource\Scene\Game\InvaderGame.h"
#include"Resource\Scene\Game\TargetGame.h"
#include"Resource\Scene\Result\Result.h"

void Main()
{
	MyApp manager;

	// シーンを設定
	
	//タイトル
	manager.add<Title>(L"Title");
	//メインメニュー
	manager.add<Menu>(L"Menu");
	//各メニュー
	manager.add<BattingGame_Menu>(L"BattingGame_Menu");
	manager.add<PuzzleGame_Menu>(L"PuzzleGame_Menu");
	manager.add<ShootingGame_Menu>(L"ShootingGame_Menu");
	manager.add<InvaderGame_Menu>(L"InvaderGame_Menu");
	manager.add<TargetGame_Menu>(L"TargetGame_Menu");

	//ゲーム
	manager.add<Puzzle_Game>(L"Puzzle_Game");
	manager.add<Shooting_Game>(L"Shooting_Game");
	manager.add<Batting_Game>(L"Batting_Game");
	manager.add<Invader_Game>(L"Invader_Game");
	manager.add<Target_Game>(L"Target_Game");
	
	//リザルト
	manager.add<Result>(L"Result");

	while (System::Update())
	{
		if (!manager.updateAndDraw())
			break;
	}
}
