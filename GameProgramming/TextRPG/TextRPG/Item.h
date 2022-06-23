#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Status {
	int nHP;
	int nMP;
	int nStr;
	int nInt;
	int nDef;

	Status(int _hp = 0, int _mp = 0, int _str = 0, int _int = 0, int _def = 0)
	{
		nHP = _hp;
		nMP = _mp;
		nStr = _str;
		nInt = _int;
		nDef = _def;
	}
	void operator+=(const int value)
	{
		this->nHP += value;
		this->nMP += value;
		this->nStr += value;
		this->nDef += value;
		this->nInt += value;
	}
	Status operator+(const Status& status)
	{
		Status sResult;
		sResult.nHP = nHP + status.nHP;
		sResult.nMP = nMP + status.nMP;
		sResult.nStr = nStr + status.nStr;
		sResult.nDef = nDef + status.nDef;
		sResult.nInt = nInt + status.nInt;
		return sResult;
	}
	Status operator-(const Status& status)
	{
		Status sResult;
		sResult.nHP = nHP - status.nHP;
		sResult.nMP = nMP - status.nMP;
		sResult.nStr = nStr - status.nStr;
		sResult.nDef = nDef - status.nDef;
		sResult.nInt = nInt - status.nInt;
		return sResult;
	}
	void Show()
	{
		cout << "HP:" << nHP << endl;
		cout << "MP:" << nMP << endl;
		cout << "STR:" << nStr << endl;
		cout << "INT:" << nInt << endl;
		cout << "DEF:" << nDef << endl;
	}
};

class Item {
public:
	enum E_ITEM_KIND { WEAPON, ARMOR, ACC, ETC };
	E_ITEM_KIND eItemKind;
	string strName;
	string strComment;
	Status sFuction;
	int nGold;
	Item(E_ITEM_KIND kind = WEAPON, string name = "test", string comment = "test", Status status = Status(), int gold = 0)
	{
		Set(kind, name, comment, status, gold);
	}
	void Set(E_ITEM_KIND kind, string name, string comment, Status status, int gold)
	{
		eItemKind = kind;
		strName = name;
		strComment = comment;
		sFuction = status;
		nGold = gold;
	}
};

class ItemManager {
	vector<Item> m_listItems;
public:
	enum E_ITEM_LIST { WOOD_SOWRD, BONE_SOWRD, WOOD_ARMOR, BONE_AMROR, WOOD_RING, BONE_RING, HP_POTION, MP_POTION, STONE, BOOM };
	ItemManager()
	{

	}

	void Init()
	{
		m_listItems.resize(10);
		m_listItems[0] = Item(Item::E_ITEM_KIND::WEAPON, "목검", "데미지_증가", Status(0, 0, 10), 100);
		m_listItems[1] = Item(Item::E_ITEM_KIND::WEAPON, "본소드", "데미지_증가", Status(0, 0, 20), 100);
		m_listItems[2] = Item(Item::E_ITEM_KIND::ARMOR, "나무갑옷", "방어력_증가", Status(0, 0, 0, 10), 100);
		m_listItems[3] = Item(Item::E_ITEM_KIND::ARMOR, "본아머", "방어력_증가", Status(0, 0, 20), 100);
		m_listItems[4] = Item(Item::E_ITEM_KIND::ACC, "나무반지", "체력_증가", Status(10), 100);
		m_listItems[5] = Item(Item::E_ITEM_KIND::ACC, "해골반지", "체력_증가", Status(20), 100);
		m_listItems[6] = Item(Item::E_ITEM_KIND::ETC, "힐링포션", "HP회복", Status(100), 100);
		m_listItems[7] = Item(Item::E_ITEM_KIND::ETC, "마나포션", "MP회복", Status(0, 100), 100);
		m_listItems[8] = Item(Item::E_ITEM_KIND::ETC, "짱돌", "단일_적_대미지", Status(0, 0, 50), 100);
		m_listItems[9] = Item(Item::E_ITEM_KIND::ETC, "목검", "다수_적_대미지", Status(0, 0, 50), 100);
		cout << "Init Items:" << m_listItems.size() << endl;
	}

	void SaveFile()
	{
		FILE* pFile = fopen("itemdatabase.csv", "wt");
		if (pFile)
		{
			if (m_listItems.empty() == false)
			{
				fprintf(pFile, "%d\n", m_listItems.size());
				vector<Item>::iterator it = m_listItems.begin();
				for (; it != m_listItems.end(); it++)
				{
					Item sItem = *(it);
					fprintf(pFile, "%d,%s,%s,%d,%d,%d,%d,%d,%d\n", sItem.eItemKind, sItem.strName.c_str(), sItem.strComment.c_str(), sItem.nGold,
						sItem.sFuction.nHP, sItem.sFuction.nMP, sItem.sFuction.nStr, sItem.sFuction.nInt, sItem.sFuction.nDef);
				}
				fclose(pFile);
			}
			else
			{
				cout << "Item is Empty!!" << m_listItems.size() << endl;
			}
		}
		else
			cout << " Save Failed!" << endl;
	}

	void LoadFile()
	{
		FILE* pFile = fopen("itemdatabase.csv", "rt");
		if (pFile)
		{
			int nSize;
			fscanf(pFile, "%d", &nSize);

			for (int i = 0; i < nSize; i++)
			{
				char strTemp[2048];
				fscanf(pFile, "%s\n", strTemp);
				cout << strTemp << endl;
				char  arrStrs[10][128];
				char* strTemps = strtok(strTemp, ",");
				int idx = 0;
				while (strTemps != NULL)
				{
					//memcpy(arrStrs[idx], strTemps, 128);
					strcpy(arrStrs[idx], strTemps);
					cout << arrStrs[idx] << ",";
					//cout << strTemps << ",";
					strTemps = strtok(NULL, ",");
					idx++;
				}
				cout << endl;
				string name = arrStrs[1];
				string info = arrStrs[2];
				Item sItem((Item::E_ITEM_KIND)atoi(arrStrs[0]), name, info,
					Status(atoi(arrStrs[4]), atoi(arrStrs[5]), atoi(arrStrs[6]), atoi(arrStrs[7])),
					atoi(arrStrs[3]));
				m_listItems.push_back(sItem);
			}
			fclose(pFile);
		}
		else
			cout << " Load Failed!" << endl;
	}

	Item* GetItem(int idx)
	{
		return &m_listItems[idx];
	}
};