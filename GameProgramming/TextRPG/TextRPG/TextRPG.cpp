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
		m_listItems[0] = Item(Item::E_ITEM_KIND::WEAPON, "���", "������ ����", Status(0, 0, 10), 100);
		m_listItems[1] = Item(Item::E_ITEM_KIND::WEAPON, "���ҵ�", "������ ����", Status(0, 0, 20), 100);
		m_listItems[2] = Item(Item::E_ITEM_KIND::ARMOR, "��������", "���� ����", Status(0, 0, 0, 10), 100);
		m_listItems[3] = Item(Item::E_ITEM_KIND::ARMOR, "���Ƹ�", "���� ����", Status(0, 0, 20), 100);
		m_listItems[4] = Item(Item::E_ITEM_KIND::ACC, "��������", "ü�� ����", Status(10), 100);
		m_listItems[5] = Item(Item::E_ITEM_KIND::ACC, "�ذ����", "ü�� ����", Status(20), 100);
		m_listItems[6] = Item(Item::E_ITEM_KIND::ETC, "��������", "HPȸ��", Status(100), 100);
		m_listItems[7] = Item(Item::E_ITEM_KIND::ETC, "��������", "MPȸ��", Status(0, 100), 100);
		m_listItems[8] = Item(Item::E_ITEM_KIND::ETC, "¯��", "���� �� �����", Status(0, 0, 50), 100);
		m_listItems[9] = Item(Item::E_ITEM_KIND::ETC, "���", "�ټ� �� �����", Status(0, 0, 50), 100);
	}

	void SaveFile()
	{
		FILE* pFile = fopen("itemdatabase.csv", "wt");
		if (pFile)
		{
			fprintf(pFile, "%d\n", m_listItems.size());
			vector<Item>::iterator it = m_listItems.begin();
			for (; it != m_listItems.end(); it++)
			{
				Item sItem = *(it);
				fprintf(pFile, "%d,%s,%s,%d,%d,%d,%d,%d\n", sItem.eItemKind, sItem.strName.c_str(), sItem.strComment.c_str(), sItem.nGold,
					sItem.sFuction.nHP, sItem.sFuction.nMP, sItem.sFuction.nStr, sItem.sFuction.nInt, sItem.sFuction.nDef);
			}
			fclose(pFile);
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
				char  arrStrs[8][128];
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
			cout << " Save Failed!" << endl;
	}

	Item* GetItem(int idx)
	{
		return &m_listItems[idx];
	}
};

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
		//Ÿ���� ����ġ�� �����ͼ� �� ����ġ�� �ø���.
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
		//���� ����ġ�� 100 �̻�Ǹ�, ����+1, ��� �ɷ�ġ 10����, ����ġ �ʱ�ȭ.
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
			if(m_listIventory[i] != nullptr)
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

void main()
{
	enum E_STAGE { EXIT = -1, CRATE, IVENTORY, SHOP, TOWN, FILED, BATTLE, GAME_OVER, THE_END, MAX };
	const char* strStageName[] = { "CRATE", "INVENTORY","SHOP","TOWN", "FILED", "BATTLE", "GAME_OVER", "THE_END" };

	enum E_MONSTER { SILME, SKELETON, BOSS, MON_MAX };

	const char* strMonsterName[] = { "SILME", "SKELETON", "BOSS" };

	int eStage = E_STAGE::CRATE;

	ItemManager cItemManager;

	//cItemManager.Init();
	//cItemManager.SaveFile();
	cItemManager.LoadFile();

	Player cPlayer("unkown",9999999);
	Player cMonster;
	Player cShop("Shop",99999999);

	cShop.SetIventory(cItemManager.GetItem(ItemManager::E_ITEM_LIST::WOOD_SOWRD));
	cShop.SetIventory(cItemManager.GetItem(ItemManager::E_ITEM_LIST::WOOD_ARMOR));
	cShop.SetIventory(cItemManager.GetItem(ItemManager::E_ITEM_LIST::WOOD_RING));
	cShop.SetIventory(cItemManager.GetItem(ItemManager::E_ITEM_LIST::BONE_SOWRD));
	cShop.SetIventory(cItemManager.GetItem(ItemManager::E_ITEM_LIST::BONE_AMROR));
	cShop.SetIventory(cItemManager.GetItem(ItemManager::E_ITEM_LIST::BONE_RING));
	cShop.SetIventory(cItemManager.GetItem(ItemManager::E_ITEM_LIST::HP_POTION));
	cShop.SetIventory(cItemManager.GetItem(ItemManager::E_ITEM_LIST::MP_POTION));
	cShop.SetIventory(cItemManager.GetItem(ItemManager::E_ITEM_LIST::STONE));
	cShop.SetIventory(cItemManager.GetItem(ItemManager::E_ITEM_LIST::BOOM));
	cShop.Show();

	cPlayer.SetIventory(cItemManager.GetItem(ItemManager::E_ITEM_LIST::WOOD_SOWRD));
	cPlayer.SetIventory(cItemManager.GetItem(ItemManager::E_ITEM_LIST::WOOD_ARMOR));
	cPlayer.SetIventory(cItemManager.GetItem(ItemManager::E_ITEM_LIST::WOOD_RING));

	cMonster.Set("Slime",100, 100, 20, 10, 10, 100);
	cMonster.SetIventory(cItemManager.GetItem(ItemManager::E_ITEM_LIST::WOOD_SOWRD));
	//cMonster.SetIventory(Item(Item::E_ITEM_KIND::WEAPON, "���", "������ ����", Status(0, 0, 10), 100));

	while (eStage != E_STAGE::EXIT)
	{
		switch (eStage)
		{
		case E_STAGE::CRATE:
		{
			string name;
			cout << "�ɸ��� �̸��� �Է��ϼ���!:";
			cin >> name;
			cPlayer.Set(name, 100, 100, 20, 10, 10, 0);
			eStage = E_STAGE::TOWN;
		}
		break;
		case E_STAGE::IVENTORY:
		{
			cPlayer.Show();
			int nSelect;
			cout << "�޴��� �����ϼ���!(1: �����ۻ��. 2: ������� etc: ����):";
			cin >> nSelect;
			if (nSelect == 1)
			{
				cout << "����� �������� ���ϼ���!:";
				cin >> nSelect;
				cout << "Select:" << nSelect << endl;
				if (!cPlayer.UseItem(nSelect))
					cout << "����Ҽ������ϴ�!" << endl;
			}
			else if (nSelect == 2)
			{
				cout << "��������� ����Կ��� �����ϼ���!:";
				cin >> nSelect;
				cPlayer.ReleaseEqument(nSelect);
			}
			else
				eStage = E_STAGE::TOWN;
		}
		case E_STAGE::SHOP:
		{
			cShop.Show();
			int nInput;
			cout << "�����Դϴ�. ������ �Ͻðڽ��ϱ�? 1: ����, 2: �ȱ�, etc:����";
			cin >> nInput;
			switch (nInput)
			{
			case 1:
			{
				cout << "������ �������� ��Ͽ��� �����ϼ���! -1:����";
				cin >> nInput;
				if (nInput != -1)
					cPlayer.Buy(cShop, nInput);
				else
					eStage = E_STAGE::TOWN;
			}
			break;
			case 2:
			{
				cPlayer.Show();
				cout << "�Ǹ��� �������� ��Ͽ��� �����ϼ���! -1:����";
				cin >> nInput;
				if (nInput != -1)
					cPlayer.Sell(nInput);
				else
					eStage = E_STAGE::TOWN;
			}
			break;
			default:
			{
				eStage = E_STAGE::TOWN;
			}
			break;
			}

		}
		break;
		case E_STAGE::TOWN:
		{
			cout << "���� �Դϴ�." << endl;
			cout << "���� ���ðڽ��ϱ�?" << endl;
			for (int i = 0; i < E_STAGE::MAX; i++)
				cout << i << ":" << strStageName[i] << ",";
			cin >> eStage;
		}
		break;
		case E_STAGE::FILED:
		{
			int nSelect;
			cout << "���� ���ðڽ��ϱ�?";
			for (int i = 0; i < E_MONSTER::MON_MAX; i++)
				cout << i << ":" << strMonsterName[i] << ",";
			cin >> nSelect;
			switch (nSelect)
			{
			case E_MONSTER::SILME:
				cMonster.Set("Slime",100, 100, 20, 10, 10, 100);
				break;
			case E_MONSTER::SKELETON:
				cMonster.Set("Skeleton", 200, 200, 30, 10, 10, 100);
				break;
			case E_MONSTER::BOSS:
				cMonster.Set("Boss", 300, 100, 50, 10, 10, 100);
				break;
			}
			eStage = E_STAGE::BATTLE;
		}
		break;
		case E_STAGE::BATTLE:
		{
			if (cPlayer.Dead() == false)
				cPlayer.Attack(cMonster);
			else
			{
				eStage = GAME_OVER;
			}
			cMonster.Show();
			if (cMonster.Dead() == false)
				cMonster.Attack(cPlayer);
			else
			{
				cPlayer.StillItem(cMonster);
				if (cPlayer.LvUp())
					cout << "����!" << endl;
				eStage = TOWN;
			}
		}
		break;
		case E_STAGE::GAME_OVER:
			printf("GAME OVER");
			break;
		case E_STAGE::THE_END:
			printf("THE EMD");
			break;
		default:
			break;
		}	
	}
}