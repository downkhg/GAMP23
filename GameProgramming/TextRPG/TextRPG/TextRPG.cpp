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
		//Ÿ���� ����ġ�� �����ͼ� �� ����ġ�� �ø���.
		this->m_nExp = target.m_nLv * 100 + target.m_nExp;
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
	}
};

void main()
{
	Player cPlayer("Player");
	Player cMonster("Monster");

	//������ �κ��丮�� ������ �߰��ϰ�, 
	//���͸� ������, ������ ȹ���Ѵ�.
	//(������ ù��° �κ��丮���� �������� ����´�.)

	while (!cPlayer.Dead() && !cMonster.Dead())//�����ϳ��� �׾����� ������ ����ȴ�. -> �Ѵ� ��������� �������Ѵ�.
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
		else
		{
			cout << "Player Win !!" << endl;
			cPlayer.StillExp(cMonster);
			if (cPlayer.LvUp())
				cout << "Lv Up!!" << endl;
			cPlayer.Show();
		}
	}
}