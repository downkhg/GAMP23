#pragma once
//#include "Player.h"

using namespace std;

class Player;
class ItemManager;

class GameManager
{
public:
	enum E_STAGE { EXIT = -1, CRATE, IVENTORY, SHOP, TOWN, FILED, BATTLE, GAME_OVER, THE_END, MAX };
	enum E_MONSTER { SILME, SKELETON, BOSS, MON_MAX };
	int GetStage() { return eStage; }

	void init();
	void Release();
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

	ItemManager* m_pItemManager;

	Player* m_pPlayer;
	Player* m_pMonster;
	Player* m_pShop;
public:
	//값에의한호출
	Player* GetPlayer() { return m_pPlayer; }
	void SetPlayer(Player* player) { m_pPlayer = player; }
	//참조에의한호출
	//Player& GetPlayer() { return m_pPlayer; }
};