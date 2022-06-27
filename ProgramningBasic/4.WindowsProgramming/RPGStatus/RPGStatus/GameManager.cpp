#include "pch.h"

void GameManager::init()
{
	//cItemManager.Init();
	//cItemManager.SaveFile();
	cItemManager.LoadFile();

	Item* pItem = cItemManager.GetItem(ItemManager::E_ITEM_LIST::WOOD_SOWRD);
	cShop.SetIventory(pItem);
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

	cMonster.Set("Slime", 100, 100, 20, 10, 10, 100);
	cMonster.SetIventory(cItemManager.GetItem(ItemManager::E_ITEM_LIST::WOOD_SOWRD));
}
void  GameManager::EventCreate()
{
	string name;
	cout << "�ɸ��� �̸��� �Է��ϼ���!:";
	cin >> name;
	cPlayer.Set(name, 100, 100, 20, 10, 10, 0);
	eStage = E_STAGE::TOWN;
}
void  GameManager::EventInventory()
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
void  GameManager::EventShop()
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
void  GameManager::EventTown()
{
	const char* strStageName[] = { "CRATE", "INVENTORY","SHOP","TOWN", "FILED", "BATTLE", "GAME_OVER", "THE_END" };
	cout << "���� �Դϴ�." << endl;
	cout << "���� ���ðڽ��ϱ�?" << endl;
	for (int i = 0; i < E_STAGE::MAX; i++)
		cout << i << ":" << strStageName[i] << ",";
	cin >> eStage;
}
void  GameManager::EventFiled()
{
	const char* strMonsterName[] = { "SILME", "SKELETON", "BOSS" };
	int nSelect;
	cout << "���� ���ðڽ��ϱ�?";
	for (int i = 0; i < E_MONSTER::MON_MAX; i++)
		cout << i << ":" << strMonsterName[i] << ",";
	cin >> nSelect;
	switch (nSelect)
	{
	case E_MONSTER::SILME:
		cMonster.Set("Slime", 100, 100, 20, 10, 10, 100);
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
void  GameManager::EventBattle()
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
void GameManager::EventTheEnd()
{
	printf("GAME OVER");
}
void GameManager::EventGameOver()
{
	printf("THE EMD");
}
void GameManager::Update()
{
	switch (eStage)
	{
	case E_STAGE::CRATE:
		EventCreate();
		break;
	case E_STAGE::IVENTORY:
		EventInventory();
		break;
	case E_STAGE::SHOP:
		EventShop();
		break;
	case E_STAGE::TOWN:
		EventTown();
		break;
	case E_STAGE::FILED:
		EventFiled();
		break;
	case E_STAGE::BATTLE:
		EventBattle();
		break;
	case E_STAGE::GAME_OVER:
		EventGameOver();
		break;
	case E_STAGE::THE_END:
		EventTheEnd();
		break;
	}
}