#include <iostream>
#include <vector>

using namespace std;
//����: �����迭
//0.�迭�� �����Ͱ� ����ɰ����� �̸� Ȯ���Ǿ��ִ�.
//1.�ε����� ���������� �����ϴ�.
//2.�� �ڷ�� �����Ϳ���(�ε���)�� ���� ����/���������� �����ϴ�.
//3.�迭�� ũ�⸦ ��Ÿ���߿� ���氡���ϴ�.
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
	//1.�߰� 2.���� 3.����
	contair.push_back(100);//�߰�
	vector<int>::iterator it;//�ݺ���
	for (it = contair.begin(); it != contair.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
	it = contair.begin();
	contair.insert(it, 110);//����
	for (it = contair.begin(); it != contair.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
	it = find(contair.begin(), contair.end(), 10);
	if (it != contair.end())
		cout << "Find:" << *it << endl;
	contair.erase(it);//����
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
	//�����̵�6~10���� �׸��� ������ ������.
}

void main()
{
	VectorMain();
}