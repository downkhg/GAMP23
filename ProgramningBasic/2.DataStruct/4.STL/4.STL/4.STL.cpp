#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <unordered_map>//hash_map -> unordered_map: vs2019부터 변경

using namespace std;
//벡터: 동적배열
//0.배열은 데이터가 저장될공간이 미리 확보되어있다.
//1.인덱스로 원소접근이 가능하다.
//2.각 자료는 포인터연산(인덱스)을 통한 순차/랜덤접근이 가능하다.
//3.배열의 크기를 런타임중에 변경가능하다.
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
	//1.추가 2.삽입 3.삭제
	container.push_back(100);//추가
	vector<int>::iterator it;//반복자
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
	it = container.begin();
	container.insert(it, 110);//삽입
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
	it = find(container.begin(), container.end(), 10);
	if (it != container.end())
		cout << "Find:" << *it << endl;
	container.erase(it);//삭제
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
	container.clear();
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
}
//1.생성 10개
//2.크기변성 5개
//3.0,-10추가, 
//4.찾기 70
//5.삽입 70에 -20삽입 -> 80은 위에서 찾기를 했을때 70이므로 80이 될수는 없다.
//6.지우기 삽입된 노드(반복자:이터레이터) 삭제
//7.시작+3, 끝+3
//8.뒤집기,모두 삭제
void VectorTestMain()
{
	//슬라이드6~10까지 그림과 같도록 만들어보기.
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

//연결리스트
//1.데이터는 순차접근만 가능하다.(랜덤x)
//2.연결리스트에 추가,삽입,삭제(?)은 O(1)이다.
//3.연결리스트의 종류: 단일, 환형, 이중 stl의 리스트는 어디에 해당되는가?
void ListMain()
{
	//슬라이드6~10까지 그림과 같도록 만들어보기.
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
//데크: 앞뒤로 자료를 추가/삭제가능, 랜덤접근가능.
void DequeMain()
{
	//슬라이드6~10까지 그림과 같도록 만들어보기.
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
//스택: 뒤에서 추가되고 뒤에서 꺼냄.
//재귀함수에서 이전 함수를 호출할때마다 스택에 쌓임.
//문자열뒤집기 -> 문자배열 -> apple -> elppa
//데이터: 문자열 = "apple", 스택<>
//알고리즘: 문자열을 뒤집기 -> 스택을 이용할것.
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
//큐: 뒤에서 추가하고 앞에서 꺼냄.
//메세지큐: 이벤트가 발생한 순서대로 저장하는 공간.
//입력된 순서대로 명령어 처리하기
//A,B,C,D -> A,B,C,D
//B,C,D,A -> B,C,D,A
//(입력된 문자)를 (큐)에 저장하고, 완료되면, 큐에 저장된값을 1개씩빼서 확인한다.
//데이터: 입력문자, 큐
//알고리즘: 큐에 입력된 문자를 저장한다, 저장이 완료되면 1개씩 빼서 확인한다.
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
//우선순위큐: 우선순위가 높은 원소가 먼저나감(힙)
//무작위로 데이터를 넣었을때 어떤 순서대로 데이터가 나오는가? 큰값부터 나온다.
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
//맵: 사전식으로 데이터를 찾을수있다.
//해당영어단어를 넣으면 한국어 결과가 나온다.
void MapMain()
{
	map<string, string> mapDic;

	mapDic["test"] = "시험";
	mapDic["pratice"] = "연습";
	mapDic["try"] = "도전";
	mapDic["note"] = "기록";

	cout << mapDic["try"] << endl;
	cout << mapDic["note"] << endl;
}
//셋: 순서없이 데이터를 넣는다. 데이터는 순서와 상관없이 데이터를 찾는다.
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
//해시맵: 해시테이블
void HashMapMain()
{
	unordered_map<string, string> mapDic;

	mapDic["test"] = "시험";
	mapDic["pratice"] = "연습";
	mapDic["try"] = "도전";
	mapDic["note"] = "기록";

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