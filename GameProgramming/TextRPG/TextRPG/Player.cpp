#include "Player.h"

void Player::SetIventory(Item* item)
{
	m_listIventory.push_back(item);
}
Item* Player::GetIventoryIdx(int idx)
{
	return m_listIventory[idx];
}
void Player::DeleteIventory(int idx)
{
	m_listIventory.erase(m_listIventory.begin() + idx);
}

Player::Player(string strName, int _gold, int _hp, int _mp, int _str, int _int, int _def, int _exp)
{
	Set(strName, _hp, _mp, _str, _int, _def, _exp);
	m_nGold = _gold;
	m_listEqument.resize(3);
}

bool Player::UseItem(int idx)
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

bool Player::ReleaseEqument(int idx)
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

void Player::Set(string strName, int _hp, int _mp, int _str, int _int, int _def, int _exp)
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

void Player::Attack(Player& taget)
{
	taget.m_sStatus.nHP -= m_sStatus.nStr - m_sStatus.nDef;
}

void Player::StillExp(Player& target)
{
	//Ÿ���� ����ġ�� �����ͼ� �� ����ġ�� �ø���.
	this->m_nExp = target.m_nLv * 100 + target.m_nExp;
}

void Player::StillItem(Player& target, int idx)
{
	SetIventory(target.GetIventoryIdx(idx));
}

bool Player::Buy(Player& target, int idx)
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

void Player::Sell(int idx)
{
	Item* pItem = GetIventoryIdx(idx);
	DeleteIventory(idx);
	m_nGold += pItem->nGold;
}

bool Player::LvUp()
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

bool Player::Dead()
{
	if (m_sStatus.nHP <= 0)
		return true;
	return false;
}

void Player::Show()
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