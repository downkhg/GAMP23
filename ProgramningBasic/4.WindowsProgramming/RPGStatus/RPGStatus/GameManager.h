#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Item.h"
#include "Player.h"

using namespace std;

class GameManager
{
public:
	enum E_STAGE { EXIT = -1, CRATE, IVENTORY, SHOP, TOWN, FILED, BATTLE, GAME_OVER, THE_END, MAX };
	enum E_MONSTER { SILME, SKELETON, BOSS, MON_MAX };
	int GetStage() { return eStage; }

	void init();
	void EventCreate();
	void EventInventory();
	void EventShop();
	void EventTown();
	void EventFiled();
	void EventBattle();
	void EventTheEnd();
	void EventGameOver();
	void Update();
private:
	int eStage = E_STAGE::CRATE;

	ItemManager cItemManager;

	Player cPlayer = Player("unkown", 9999999);
	Player cMonster;
	Player cShop = Player("Shop", 99999999);
public:
	//값에의한호출
	Player GetPlayer() { return cPlayer; }
	void SetPlayer(Player player) { cPlayer = player; }
	//참조에의한호출
	//Player& GetPlayer() { return cPlayer; }
};