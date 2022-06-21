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
	Item(E_ITEM_KIND kind, string name, string comment, Status status, int gold)
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
		m_listItems.resize(10);
		m_listItems[0] = Item(Item::E_ITEM_KIND::WEAPON, "목검", "데미지 증가", Status(0, 0, 10), 100);
		m_listItems[1] = Item(Item::E_ITEM_KIND::WEAPON, "본소드", "데미지 증가", Status(0, 0, 20), 100);
		m_listItems[2] = Item(Item::E_ITEM_KIND::ARMOR, "나무갑옷", "방어력 증가", Status(0, 0, 0, 10), 100);
		m_listItems[3] = Item(Item::E_ITEM_KIND::ARMOR, "본아머", "방어력 증가", Status(0, 0, 20), 100);
		m_listItems[4] = Item(Item::E_ITEM_KIND::ACC, "나무반지", "체력 증가", Status(10), 100);
		m_listItems[5] = Item(Item::E_ITEM_KIND::ACC, "해골반지", "체력 증가", Status(20), 100);
		m_listItems[6] = Item(Item::E_ITEM_KIND::ETC, "힐링포션", "HP회복", Status(100), 100);
		m_listItems[7] = Item(Item::E_ITEM_KIND::ETC, "마나포션", "MP회복", Status(0, 100), 100);
		m_listItems[8] = Item(Item::E_ITEM_KIND::ETC, "짱돌", "단일 적 대미지", Status(0, 0, 50), 100);
		m_listItems[9] = Item(Item::E_ITEM_KIND::ETC, "목검", "다수 적 대미지", Status(0, 0, 50), 100);
	}
	Item GetItem(int idx)
	{
		return m_listItems[idx];
	}
};

class Player {
	string m_strName;
	Status m_sStatus;
	int m_nLv;
	int m_nExp;

	vector<Item> m_listIventory;
public:
	void SetIventory(Item item)
	{
		m_listIventory.push_back(item);
	}
	Item GetIventoryIdx(int idx)
	{
		return m_listIventory[idx];
	}
	void DeleteIventory(int idx)
	{
		m_listIventory.erase(m_listIventory.begin() + idx);
	}
public:
	Player(string strName = "none", int _hp = 100, int _mp = 100, int _str = 20, int _int = 10, int _def = 10, int _exp = 0)
	{
		Set(strName, _hp, _mp, _str, _int, _def, _exp);
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
			cout << i << ":" << m_listIventory[i].strName << endl;
	}
};

void main()
{
	Player cPlayer("Player");
	Player cMonster("Monster");
	ItemManager cItemManager;
	//몬스터의 인벤토리에 포션을 추가하고, 
	//Item cHpPotion = Item(Item::E_ITEM_KIND::ETC, "HP포션", "HP회복", Status(100), 100);
	Item cHpPotion = cItemManager.GetItem(ItemManager::E_ITEM_LIST::HP_POTION);
	cMonster.SetIventory(cHpPotion);

	while (!cPlayer.Dead() && !cMonster.Dead())//둘중하나가 죽었을때 전투가 종료된다. -> 둘다 살아있으면 전투를한다.
	{
		//if (cPlayer.Dead() || cMonster.Dead()) break;
		if (!cPlayer.Dead())
		{
			cPlayer.Attack(cMonster);
			cMonster.Show();
		}
		else
		{
			cout << "Monster Win !!" << endl;
			cMonster.StillExp(cPlayer);
			if (cMonster.LvUp())
				cout << "Lv Up!!" << endl;
			cMonster.Show();
		}

		if (!cMonster.Dead())
		{
			cMonster.Attack(cPlayer);
			cPlayer.Show();
		}
		else//몬스터를 잡으면, 포션을 획득한다.(몬스터의 첫번째 인벤토리에서 아이템을 뺏어온다.)
		{
			cout << "Player Win !!" << endl;
			cPlayer.StillExp(cMonster);
			cPlayer.StillItem(cMonster);
			if (cPlayer.LvUp())
				cout << "Lv Up!!" << endl;
			cPlayer.Show();
		}
	}
}