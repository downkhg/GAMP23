#include <iostream>
#include <vector>

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
//3.0,-10추가
//4.찾기 70
//5.삽입 70에 -20삽입 -> 80은 위에서 찾기를 했을때 70이므로 80이 될수는 없다.
//6.지우기 삽입된 노드(반복자:이터레이터) 삭제
//7.뒤집기,모두 삭제
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

	reverse(container.begin(), container.end());
	cout << "7-1.reverse(" << container.size() << ")" << endl;
	for (int i = 0; i < container.size(); i++)
		cout << &container[i] << "[" << i << "]" << container[i] << ",";
	cout << endl;

	container.clear();
	cout << "7-2.clear(" << container.size() << ")" << endl;
	for (int i = 0; i < container.size(); i++)
		cout << &container[i] << "[" << i << "]" << container[i] << ",";
	cout << endl;
}

void main()
{
	//VectorMain();
	VectorTestMain();
}