#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <unordered_map>//hash_map -> unordered_map: vs2019���� ����

using namespace std;
//����: �����迭
//0.�迭�� �����Ͱ� ����ɰ����� �̸� Ȯ���Ǿ��ִ�.
//1.�ε����� ���������� �����ϴ�.
//2.�� �ڷ�� �����Ϳ���(�ε���)�� ���� ����/���������� �����ϴ�.
//3.�迭�� ũ�⸦ ��Ÿ���߿� ���氡���ϴ�.
void VectorMain()
{
	vector<int> container(1);
	container[0] = 10;
	cout << "Print:";
	for (int i = 0; i < container.size(); i++)
		printf("[%d]%d,",i,container[i]);//cout << "[" << i << "]" << container[i] << ",";
	printf("\n");//cout << endl;
	container.resize(3);
	cout << "Print:";
	for (int i = 0; i < container.size(); i++)
		printf("[%d]%d,", i, container[i]);//cout << "[" << i << "]" << container[i] << ",";
	printf("\n");//cout << endl;
	//1.�߰� 2.���� 3.����
	container.push_back(100);//�߰�
	vector<int>::iterator it;//�ݺ���
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
	it = container.begin();
	container.insert(it, 110);//����
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
	it = find(container.begin(), container.end(), 10);
	if (it != container.end())
		cout << "Find:" << *it << endl;
	container.erase(it);//����
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
	container.clear();
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
}
//1.���� 10��
//2.ũ�⺯�� 5��
//3.0,-10�߰�, 
//4.ã�� 70
//5.���� 70�� -20���� -> 80�� ������ ã�⸦ ������ 70�̹Ƿ� 80�� �ɼ��� ����.
//6.����� ���Ե� ���(�ݺ���:���ͷ�����) ����
//7.����+3, ��+3
//8.������,��� ����
void VectorTestMain()
{
	//�����̵�6~10���� �׸��� ������ ������.
	vector<int> container(10);
	cout << "1.Init(" << container.size() << "):" << container.capacity() << endl;
	for (int i = 0; i < container.size(); i++)
		container[i] = 100 - (i * 10);
	for (int i = 0; i < container.size(); i++)
		cout << &container[i] << "[" << i << "]"<< container[i] <<",";
	cout << endl;

	container.resize(5);
	cout << "2.resize(" << container.size() << "):" << container.capacity() << endl;
	for (int i = 0; i < container.size(); i++)
		cout << &container[i] << "[" << i << "]" << container[i] << ",";
	cout << endl;

	container.push_back(0);
	cout << "3-1.push_back(0)" << endl;
	for (int i = 0; i < container.size(); i++)
		cout << &container[i] << "[" << i << "]" << container[i] << ",";
	cout << endl;

	container.push_back(-10);
	cout << "3-2.push_back(-10)" << endl;
	for (int i = 0; i < container.size(); i++)
		cout << &container[i] << "[" << i << "]" << container[i] << ",";
	cout << endl;

	vector<int>::iterator itFind = find(container.begin(), container.end(), 70);
	if (itFind != container.end())
		cout << "4.Find[" << &*itFind << "]:" << *itFind << endl;

	vector<int>::iterator itInsert = container.insert(itFind, -20);
	if (itInsert != container.end())
		cout << "5-1.itInsert[" << &*itInsert << "]:" << *itInsert << endl;
	cout << "5-2.itInsert(" << container.size() << ")" << endl;
	for (int i = 0; i < container.size(); i++)
		cout << &container[i] << "[" << i << "]" << container[i] << ",";
	cout << endl;
	/*if (itFind != container.end())
		cout << "5-3.Find[" << &*itFind << "]:" << *itFind << endl;*/

	container.erase(itInsert);
	cout << "6.erase("<<container.size()<<")" << endl;
	for (int i = 0; i < container.size(); i++)
		cout << &container[i] << "[" << i << "]" << container[i] << ",";
	cout << endl;

	vector<int>::iterator it = container.begin() + 3;
	if (it != container.end())
		cout << "7.1.begin+3[" << &*it << "]:" << *it << endl;

	it = container.end() - 3;
	if (it != container.end())
		cout << "7.1.end+3[" << &*it << "]:" << *it << endl;

	reverse(container.begin(), container.end());
	cout << "8-1.reverse(" << container.size() << ")" << endl;
	for (int i = 0; i < container.size(); i++)
		cout << &container[i] << "[" << i << "]" << container[i] << ",";
	cout << endl;

	container.clear();
	cout << "8-2.clear(" << container.size() << ")" << endl;
	for (int i = 0; i < container.size(); i++)
		cout << &container[i] << "[" << i << "]" << container[i] << ",";
	cout << endl;
}

//���Ḯ��Ʈ
//1.�����ʹ� �������ٸ� �����ϴ�.(����x)
//2.���Ḯ��Ʈ�� �߰�,����,����(?)�� O(1)�̴�.
//3.���Ḯ��Ʈ�� ����: ����, ȯ��, ���� stl�� ����Ʈ�� ��� �ش�Ǵ°�?
void ListMain()
{
	//�����̵�6~10���� �׸��� ������ ������.
	list<int> container(10);
	cout << "1.Init(" << container.size() << "):" << endl;
	list<int>::iterator it;
	int idx = 0;
	for (it = container.begin(); it != container.end(); it++)
	{
		*it = 100 - (idx * 10);
		idx++;
	}
	for (it = container.begin(); it != container.end(); it++)
		cout << &*it << ":" << *it << ",";
	cout << endl;

	container.resize(5);
	cout << "2.resize(" << container.size() << ")" << endl;
	for (it = container.begin(); it != container.end(); it++)
		cout << &*it << ":" << *it << ",";
	cout << endl;

	container.push_back(0);
	cout << "3-1.push_back(0)" << endl;
	for (it = container.begin(); it != container.end(); it++)
		cout << &*it << ":" << *it << ",";
	cout << endl;

	container.push_back(-10);
	cout << "3-2.push_back(-10)" << endl;
	for (it = container.begin(); it != container.end(); it++)
		cout << &*it << ":" << *it << ",";
	cout << endl;

	list<int>::iterator itFind = find(container.begin(), container.end(), 70);
	if (itFind != container.end())
		cout << "4.Find[" << &*itFind << "]:" << *itFind << endl;

	list<int>::iterator itInsert = container.insert(itFind, -20);
	if (itInsert != container.end())
		cout << "5-1.itInsert[" << &*itInsert << "]:" << *itInsert << endl;
	cout << "5-2.itInsert(" << container.size() << ")" << endl;
	for (it = container.begin(); it != container.end(); it++)
		cout << &*it << ":" << *it << ",";
	cout << endl;
	/*if (itFind != container.end())
		cout << "5-3.Find[" << &*itFind << "]:" << *itFind << endl;*/

	container.erase(itInsert);
	cout << "6.erase(" << container.size() << ")" << endl;
	for (it = container.begin(); it != container.end(); it++)
		cout << &*it << ":" << *it << ",";
	cout << endl;

	it = ++container.begin();
	if (it != container.end())
		cout << "7.1.begin++[" << &*it << "]:" << *it << endl;

	it = --container.end();
	if (it != container.end())
		cout << "7.1.end--[" << &*it << "]:" << *it << endl;

	reverse(container.begin(), container.end());
	cout << "8-1.reverse(" << container.size() << ")" << endl;
	for (it = container.begin(); it != container.end(); it++)
		cout << &*it << ":" << *it << ",";
	cout << endl;

	container.clear();
	cout << "8-2.clear(" << container.size() << ")" << endl;
	for (it = container.begin(); it != container.end(); it++)
		cout << &*it << ":" << *it << ",";
	cout << endl;
}
//��ũ: �յڷ� �ڷḦ �߰�/��������, �������ٰ���.
void DequeMain()
{
	//�����̵�6~10���� �׸��� ������ ������.
	deque<int> container(10);
	cout << "1.Init(" << container.size() << "):"  << endl;
	for (int i = 0; i < container.size(); i++)
		container[i] = 100 - (i * 10);
	for (int i = 0; i < container.size(); i++)
		cout << &container[i] << "[" << i << "]" << container[i] << ",";
	cout << endl;

	container.resize(5);
	cout << "2.resize(" << container.size() << "):"  << endl;
	for (int i = 0; i < container.size(); i++)
		cout << &container[i] << "[" << i << "]" << container[i] << ",";
	cout << endl;

	container.push_back(0);
	cout << "3-1.push_back(0)" << endl;
	for (int i = 0; i < container.size(); i++)
		cout << &container[i] << "[" << i << "]" << container[i] << ",";
	cout << endl;

	container.push_back(-10);
	cout << "3-2.push_back(-10)" << endl;
	for (int i = 0; i < container.size(); i++)
		cout << &container[i] << "[" << i << "]" << container[i] << ",";
	cout << endl;

	container.push_front(110);
	cout << "3-3.push_back(110)" << endl;
	for (int i = 0; i < container.size(); i++)
		cout << &container[i] << "[" << i << "]" << container[i] << ",";
	cout << endl;

	deque<int>::iterator itFind = find(container.begin(), container.end(), 70);
	if (itFind != container.end())
		cout << "4.Find[" << &*itFind << "]:" << *itFind << endl;

	deque<int>::iterator itInsert = container.insert(itFind, -20);
	if (itInsert != container.end())
		cout << "5-1.itInsert[" << &*itInsert << "]:" << *itInsert << endl;
	cout << "5-2.itInsert(" << container.size() << ")" << endl;
	for (int i = 0; i < container.size(); i++)
		cout << &container[i] << "[" << i << "]" << container[i] << ",";
	cout << endl;
	/*if (itFind != container.end())
		cout << "5-3.Find[" << &*itFind << "]:" << *itFind << endl;*/

	container.erase(itInsert);
	cout << "6.erase(" << container.size() << ")" << endl;
	for (int i = 0; i < container.size(); i++)
		cout << &container[i] << "[" << i << "]" << container[i] << ",";
	cout << endl;

	deque<int>::iterator it = container.begin() + 3;
	if (it != container.end())
		cout << "7.1.begin+3[" << &*it << "]:" << *it << endl;

	it = container.end() - 3;
	if (it != container.end())
		cout << "7.1.end+3[" << &*it << "]:" << *it << endl;

	reverse(container.begin(), container.end());
	cout << "8-1.reverse(" << container.size() << ")" << endl;
	for (int i = 0; i < container.size(); i++)
		cout << &container[i] << "[" << i << "]" << container[i] << ",";
	cout << endl;

	container.clear();
	cout << "8-2.clear(" << container.size() << ")" << endl;
	for (int i = 0; i < container.size(); i++)
		cout << &container[i] << "[" << i << "]" << container[i] << ",";
	cout << endl;
}
//����: �ڿ��� �߰��ǰ� �ڿ��� ����.
//����Լ����� ���� �Լ��� ȣ���Ҷ����� ���ÿ� ����.
//���ڿ������� -> ���ڹ迭 -> apple -> elppa
//������: ���ڿ� = "apple", ����<>
//�˰���: ���ڿ��� ������ -> ������ �̿��Ұ�.
void StackMain()
{
	char strWord[] = "apple";
	stack<char> cStack;
	int idx = 0;
	while (strWord[idx] != '\0')
	{
		cStack.push(strWord[idx]);
		idx++;
	}
	idx = 0;
	while (strWord[idx] != '\0')
	{
		strWord[idx] = cStack.top();
		cStack.pop();
		idx++;
	}
	cout << strWord << endl;
}
//ť: �ڿ��� �߰��ϰ� �տ��� ����.
//�޼���ť: �̺�Ʈ�� �߻��� ������� �����ϴ� ����.
//�Էµ� ������� ��ɾ� ó���ϱ�
//A,B,C,D -> A,B,C,D
//B,C,D,A -> B,C,D,A
//(�Էµ� ����)�� (ť)�� �����ϰ�, �Ϸ�Ǹ�, ť�� ����Ȱ��� 1�������� Ȯ���Ѵ�.
//������: �Է¹���, ť
//�˰���: ť�� �Էµ� ���ڸ� �����Ѵ�, ������ �Ϸ�Ǹ� 1���� ���� Ȯ���Ѵ�.
void QueueMain()
{
	queue<char> cQueue;
	char cInput = '\0';
	while (cInput != 'x')
	{
		cin >> cInput;
		cQueue.push(cInput);
	}
	while (cQueue.empty() == false)
	{
		cout << cQueue.front() << endl;
		cQueue.pop();
	}
}
//�켱����ť: �켱������ ���� ���Ұ� ��������(��)
//�������� �����͸� �־����� � ������� �����Ͱ� �����°�? ū������ ���´�.
//10,20,30 -> 30,20,10
//30,20,10 -> 30,20,10
//20,30,10 -> 30,20,10
void PriorytyQueueMain()
{
	priority_queue<char> cQueue;
	char cInput = '\0';
	while (cInput != 'x')
	{
		cin >> cInput;
		cQueue.push(cInput);
	}
	while (cQueue.empty() == false)
	{
		cout << cQueue.top() << endl;
		cQueue.pop();
	}
}
//��: ���������� �����͸� ã�����ִ�.
//�ش翵��ܾ ������ �ѱ��� ����� ���´�.
void MapMain()
{
	map<string, string> mapDic;

	mapDic["test"] = "����";
	mapDic["pratice"] = "����";
	mapDic["try"] = "����";
	mapDic["note"] = "���";

	cout << mapDic["try"] << endl;
	cout << mapDic["note"] << endl;
}
//��: �������� �����͸� �ִ´�. �����ʹ� ������ ������� �����͸� ã�´�.
void SetMain()
{
	set<int> setData;
	
	for (int i = 0; i < 4; i++)
		setData.insert(50 - (i * 10));
	/*setData.insert(10);
	setData.insert(20);
	setData.insert(30);
	setData.insert(40);*/

	set<int>::iterator it = setData.find(10);

	if (it != setData.end()) it;
	for (it = setData.begin(); it != setData.end(); it++)
		cout << *it << ",";
	cout << endl;
}
//�ؽø�: �ؽ����̺�
void HashMapMain()
{
	unordered_map<string, string> mapDic;

	mapDic["test"] = "����";
	mapDic["pratice"] = "����";
	mapDic["try"] = "����";
	mapDic["note"] = "���";

	cout << mapDic["try"] << endl;
	cout << mapDic["note"] << endl;
}

void main()
{
	//VectorMain();
	//VectorTestMain();
	//ListMain();
	//DequeMain();
	//StackMain();
	//QueueMain();
	//PriorytyQueueMain();
	//MapMain();
	SetMain();
}