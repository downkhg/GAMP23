#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Component
{

public:
	virtual void Start() = 0;//���������Լ�
	virtual void Update() = 0;

	Component() { cout << typeid(*this).name() << "[" << this << "]" << endl; }
	virtual ~Component() { cout << "~" << typeid(*this).name() << "[" << this << "]" << endl; }//����Ҹ���

	bool operator==(const char* typeidname)//���Կ�����
	{
		return !strcmp(typeid(*this).name(), typeidname);
	}
};

class GameObject
{
	string m_strName;
	list<Component*> m_listScrits;
public:
	GameObject(string name)
	{
		m_strName = name;
		cout << typeid(*this).name() << "[" << this << "]:"<< m_strName << endl;
	}
	~GameObject()
	{ 
		for (list<Component*>::iterator it = m_listScrits.begin(); it != m_listScrits.end(); it++)
			delete *it;
		m_listScrits.clear();
		cout << "~" <<typeid(*this).name() << "[" << this << "]" << endl;
	}
	void AddComponent(Component* script) { m_listScrits.push_back(script); }
	Component* GetComponent(const char* typeidname) 
	{ 
		for (list<Component*>::iterator it = m_listScrits.begin(); it != m_listScrits.end(); it++)
		{
			Component* pComponset = *it;
			if (*pComponset == typeidname)
			{
				cout << typeid(*this).name()<< ".GetComponent("<< typeidname <<")[" << pComponset << "]" << endl;
				return pComponset;
			}
		}
		return NULL; 
	} 
	//Component* GetComponent(const char* typeidname){ return *find(m_listScrits.begin(), m_listScrits.end(), typeidname); }
	string GetName(){ return m_strName; }

	void Start() 
	{
		for (list<Component*>::iterator it = m_listScrits.begin(); it != m_listScrits.end(); it++)
			(*it)->Sta
	};
	void Update();
};

class TargetTracker : public Component
{
	GameObject* m_pTarget = NULL;
public:
	TargetTracker() { cout << typeid(*this).name() << "[" << this << "]" << endl; }
	~TargetTracker() { cout << "~" << typeid(*this).name() << "[" << this << "]" << endl; }

	GameObject* GetTarget() { return m_pTarget; };
	void SetTarget(GameObject* obj) 
	{ 
		m_pTarget = obj;
		cout << typeid(*this).name() << ".SetTarget("<< m_pTarget << ")" << endl;
	};

	void Start() override
	{
		cout << typeid(*this).name() << "["<< this <<"]:Start()" << endl;
	}
	void Update() override
	{
		cout << typeid(*this).name() << "[" << this << "]:Update()" << endl;
	}
};

class Player : public Component
{
	int m_nHp;
	int m_nStr;
public:
	Player() { cout << typeid(*this).name() << "[" << this << "]" << endl; }
	~Player() { cout << "~" << typeid(*this).name() << "[" << this << "]" << endl; }

	void InitStatus(int hp, int str)
	{
		m_nHp = hp;
		m_nStr = str;
	}

	void Start() override
	{
		InitStatus(100, 10);
		cout << typeid(*this).name() << "[" << this << "]:Start()" << endl;
	}
	void Update() override
	{
		cout << "~" << typeid(*this).name() << "[" << this << "]:Update()" << endl;
	}
};


void SimulateUnityTestMain()
{
	cout << "###### SimulateUnityTestMain() Start ######" << endl;

	cout << "###### Create GameObjects ######" << endl;
	GameObject objPlayer("Player");
	GameObject objEagle("Eagle");

	vector<GameObject*> listGameObjects(3);

	listGameObjects[0] = &objPlayer;
	listGameObjects[1] = &objEagle;
	//java�� c#������ Ŭ������ �ݵ�� �����Ҵ�ȴ�. �������÷����� �����Ҵ�� �޸𸮰� ������������ �ڵ����� �����Ѵ�.(����Ʈ������)
	//��ü: �����Ҵ�� �޸𸮸� ����Ű�� ������, �ν��Ͻ�: �����Ҵ�� �޸�
	listGameObjects[2] = new GameObject("Opossum");
	delete listGameObjects[2]; 
	//delete listGameObjects[1]; //�����Ҵ�� �޸𸮸� ���������.

	for (int i = 0; i < listGameObjects.size(); i++)
		listGameObjects[i]->Start();

	cout << "###### " << objPlayer.GetName() <<".Add Componet ######"<< endl;
	objPlayer.AddComponent(new Player());

	cout << "###### " << objEagle.GetName() << ".Add Componet ######" << endl;
	objEagle.AddComponent(new Player());
	objEagle.AddComponent(new TargetTracker());

	cout << "###### "<< objEagle.GetName() <<".Target(" << objPlayer.GetName() <<") ######" << endl;
	TargetTracker* pTargetTarcker = dynamic_cast<TargetTracker*> (objEagle.GetComponent(typeid(TargetTracker).name()));

	pTargetTarcker->SetTarget(&objPlayer);


	for (int i = 0; i < listGameObjects.size(); i++)
		listGameObjects[i]->Update();

	cout << "###### SimulateUnityTestMain() End ######" << endl;
}

void main()
{
	SimulateUnityTestMain();
}