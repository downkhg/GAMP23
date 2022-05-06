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
//3.0,-10�߰�
//4.ã�� 70
//5.���� 70�� -20���� -> 80�� ������ ã�⸦ ������ 70�̹Ƿ� 80�� �ɼ��� ����.
//6.����� ���Ե� ���(�ݺ���:���ͷ�����) ����
//7.������,��� ����
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