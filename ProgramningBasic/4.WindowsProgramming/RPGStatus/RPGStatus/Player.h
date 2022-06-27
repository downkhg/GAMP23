#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Item.h"

using namespace std;

class Player {
	string m_strName;
	Status m_sStatus;
	int m_nLv;
	int m_nExp;
	int m_nGold;

	vector<Item*> m_listIventory;
	vector<Item*> m_listEqument;
public:
	//Status GetStatus() { return m_sStatus; }
	//void SetStatus(Status status) { m_sStatus = status; }

	Status* GetStatus() { return &m_sStatus; }

	void SetIventory(Item* item);
	Item* GetIventoryIdx(int idx);
	void DeleteIventory(int idx);

	Player(string strName = "none", int _gold = 0, int _hp = 100, int _mp = 100, int _str = 20, int _int = 10, int _def = 10, int _exp = 0);

	bool UseItem(int idx);

	bool ReleaseEqument(int idx);

	void Set(string strName, int _hp, int _mp, int _str, int _int, int _def, int _exp);

	void Attack(Player& taget);
	void StillExp(Player& target);

	void StillItem(Player& target, int idx = 0);

	bool Buy(Player& target, int idx);

	void Sell(int idx);

	bool LvUp();

	bool Dead();

	void Show();
};