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
	vector<int> contair(1);
	contair[0] = 10;
	cout << "Print:";
	for (int i = 0; i < contair.size(); i++)
		printf("[%d]%d,",i,contair[i]);//cout << "[" << i << "]" << contair[i] << ",";
	printf("\n");//cout << endl;
	contair.resize(3);
	cout << "Print:";
	for (int i = 0; i < contair.size(); i++)
		printf("[%d]%d,", i, contair[i]);//cout << "[" << i << "]" << contair[i] << ",";
	printf("\n");//cout << endl;
	//1.추가 2.삽입 3.삭제
	contair.push_back(100);//추가
	vector<int>::iterator it;//반복자
	for (it = contair.begin(); it != contair.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
	it = contair.begin();
	contair.insert(it, 110);//삽입
	for (it = contair.begin(); it != contair.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
	it = find(contair.begin(), contair.end(), 10);
	if (it != contair.end())
		cout << "Find:" << *it << endl;
	contair.erase(it);//삭제
	for (it = contair.begin(); it != contair.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
	contair.clear();
	for (it = contair.begin(); it != contair.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
}

void VectorTestMain()
{
	//슬라이드6~10까지 그림과 같도록 만들어보기.
}

void main()
{
	VectorMain();
}