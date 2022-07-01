#include "GameManager.h"
#include "Player.h"

void GameManager::init()
{
	m_pPlayer = new Player("unkown", 9999999);
	m_pMonster = new Player();
	m_pShop = new Player();
	//m_pItemManager->Init();
	//m_pItemManager->SaveFile();
	m_pItemManager = new ItemManager();
	m_pItemManager->LoadFile();

	Item* pItem = m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::WOOD_SOWRD);
	m_pShop->SetIventory(pItem);
	m_pShop->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::WOOD_ARMOR));
	m_pShop->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::WOOD_RING));
	m_pShop->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::BONE_SOWRD));
	m_pShop->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::BONE_AMROR));
	m_pShop->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::BONE_RING));
	m_pShop->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::HP_POTION));
	m_pShop->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::MP_POTION));
	m_pShop->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::STONE));
	m_pShop->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::BOOM));
	m_pShop->Show();

	m_pPlayer->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::WOOD_SOWRD));
	m_pPlayer->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::WOOD_ARMOR));
	m_pPlayer->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::WOOD_RING));

	m_pMonster->Set("Slime", 100, 100, 20, 10, 10, 100);
	m_pMonster->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::WOOD_SOWRD));
}

void GameManager::Release()
{
	delete m_pItemManager;
	delete m_pPlayer;
	delete m_pMonster;
	delete m_pShop;
}

void  GameManager::EventCreate()
{
	string name;
	cout << "�ɸ��� �̸��� �Է��ϼ���!:";
	cin >> name;
	m_pPlayer->Set(name, 100, 100, 20, 10, 10, 0);
	eStage = E_STAGE::TOWN;
}
void  GameManager::EventInventory()
{
	m_pPlayer->Show();
	int nSelect;
	cout << "�޴��� �����ϼ���!(1: �����ۻ��. 2: ������� etc: ����):";
	cin >> nSelect;
	if (nSelect == 1)
	{
		cout << "����� �������� ���ϼ���!:";
		cin >> nSelect;
		cout << "Select:" << nSelect << endl;
		if (!m_pPlayer->UseItem(nSelect))
			cout << "����Ҽ������ϴ�!" << endl;
	}
	else if (nSelect == 2)
	{
		cout << "��������� ����Կ��� �����ϼ���!:";
		cin >> nSelect;
		m_pPlayer->ReleaseEqument(nSelect);
	}
	else
		eStage = E_STAGE::TOWN;
}
void  GameManager::EventShop()
{
	m_pShop->Show();
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
			m_pPlayer->Buy(*m_pShop, nInput);
		else
			eStage = E_STAGE::TOWN;
	}
	break;
	case 2:
	{
		m_pPlayer->Show();
		cout << "�Ǹ��� �������� ��Ͽ��� �����ϼ���! -1:����";
		cin >> nInput;
		if (nInput != -1)
			m_pPlayer->Sell(nInput);
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
		m_pMonster->Set("Slime", 100, 100, 20, 10, 10, 100);
		break;
	case E_MONSTER::SKELETON:
		m_pMonster->Set("Skeleton", 200, 200, 30, 10, 10, 100);
		break;
	case E_MONSTER::BOSS:
		m_pMonster->Set("Boss", 300, 100, 50, 10, 10, 100);
		break;
	}
	eStage = E_STAGE::BATTLE;
}
void  GameManager::EventBattle()
{
	if (m_pPlayer->Dead() == false)
		m_pPlayer->Attack(*m_pMonster);
	else
	{
		eStage = GAME_OVER;
	}
	m_pMonster->Show();
	if (m_pMonster->Dead() == false)
		m_pMonster->Attack(*m_pPlayer);
	else
	{
		m_pPlayer->StillItem(*m_pMonster);
		if (m_pPlayer->LvUp())
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