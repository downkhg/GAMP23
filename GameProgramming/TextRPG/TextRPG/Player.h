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
	void SetIventory(Item* item)
	{
		m_listIventory.push_back(item);
	}
	Item* GetIventoryIdx(int idx)
	{
		return m_listIventory[idx];
	}
	void DeleteIventory(int idx)
	{
		m_listIventory.erase(m_listIventory.begin() + idx);
	}
public:
	Player(string strName = "none", int _gold = 0, int _hp = 100, int _mp = 100, int _str = 20, int _int = 10, int _def = 10, int _exp = 0)
	{
		Set(strName, _hp, _mp, _str, _int, _def, _exp);
		m_nGold = _gold;
		m_listEqument.resize(3);
	}

	bool UseItem(int idx)
	{
		Item* pItem = GetIventoryIdx(idx);

		if (pItem->eItemKind == Item::E_ITEM_KIND::ETC)
			return false;

		int nIdx = pItem->eItemKind;
		m_listEqument[nIdx] = pItem;
		m_sStatus = m_sStatus + pItem->sFuction;
		DeleteIventory(idx);

		return true;
	}

	bool ReleaseEqument(int idx)
	{
		Item* pItem = m_listEqument[idx];
		if (pItem)
		{
			m_sStatus = m_sStatus - pItem->sFuction;
			SetIventory(pItem);
			return true;
		}
		return false;
	}

	void Set(string strName, int _hp, int _mp, int _str, int _int, int _def, int _exp)
	{
		m_strName = strName;
		m_sStatus.nHP = _hp;
		m_sStatus.nMP = _mp;
		m_sStatus.nStr = _str;
		m_sStatus.nInt = _int;
		m_sStatus.nDef = _def;
		m_nExp = _exp;
		m_nLv = 1;
	}

	void Attack(Player& taget)
	{
		taget.m_sStatus.nHP -= m_sStatus.nStr - m_sStatus.nDef;
	}

	void StillExp(Player& target)
	{
		//타겟의 경험치를 가져와서 내 경험치에 올린다.
		this->m_nExp = target.m_nLv * 100 + target.m_nExp;
	}

	void StillItem(Player& target, int idx = 0)
	{
		SetIventory(target.GetIventoryIdx(idx));
	}

	bool Buy(Player& target, int idx)
	{
		Item* pItem = target.GetIventoryIdx(idx);
		if (pItem->nGold <= m_nGold)
		{
			SetIventory(pItem);
			m_nGold -= pItem->nGold;
			return true;
		}
		return false;
	}

	void Sell(int idx)
	{
		Item* pItem = GetIventoryIdx(idx);
		DeleteIventory(idx);
		m_nGold += pItem->nGold;
	}

	bool LvUp()
	{
		//만약 경험치가 100 이상되면, 레벨+1, 모든 능력치 10증가, 경험치 초기화.
		if (m_nExp >= 100)
		{
			m_sStatus += 10;
			m_nLv++;
			m_nExp -= 100;
			return true;
		}
		return false;
	}

	bool Dead()
	{
		if (m_sStatus.nHP <= 0)
			return true;
		return false;
	}

	void Show()
	{
		cout << "######### " << m_strName << "######### " << endl;
		m_sStatus.Show();
		cout << "######### Inventory ######### " << endl;
		for (int i = 0; i < m_listIventory.size(); i++)
			if (m_listIventory[i] != nullptr)
				cout << i << ":" << m_listIventory[i]->strName << endl;
			else
				cout << i << ": null" << endl;
		cout << "######### Equiment ######### " << endl;
		for (int i = 0; i < m_listEqument.size(); i++)
			if (m_listEqument[i] != nullptr)
				cout << i << ":" << m_listEqument[i]->strName << endl;
			else
				cout << i << ": null" << endl;
		cout << "######### Gold:" << m_nGold << " ######### " << endl;
	}
};