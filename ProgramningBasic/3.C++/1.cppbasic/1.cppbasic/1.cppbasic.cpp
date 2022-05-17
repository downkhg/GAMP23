#include <iostream>

using namespace std; //ǥ���Լ��� ���ӽ����̽��� ����Ѵ�.
//�̸�����: ������ �ִ� ������ �Լ��� ���Խ��� ������ ����Ҽ�����.
namespace A
{
	int g_nData;
	void PrintData()
	{
		cout << "A::Data[" << &g_nData << "]:" << g_nData << endl;
	}
}

namespace B
{
	int g_nData;
	void PrintData()
	{
		cout << "B::Data["<<&g_nData<<"]:" << g_nData << endl;
	}
}

using namespace A;
//using namespace B;

void NamespaceTestMain()
{
	A::g_nData = 10;
	B::g_nData = 20;
	g_nData = 30; //���� �ϳ��� ���ӽ����̽��� ����ؾ� ������ �۵��Ѵ�.

	A::PrintData();
	B::PrintData();
	PrintData();
}

void HelloWorldMain()
{
	int nData = 100;
	printf("Hello World !!\nData:%d\n", nData);
	std::cout << "Hello World !!\nData:" << nData << std::endl; 
	//printf("Hello World !!\nData:%c\n",nData);//���α׷��Ӱ� ����Ҷ� Ÿ�Կ� �°� ����ؾ���.
	//cout << "Hello World !!\nData:"<< (char)nData << endl; //Ÿ�Կ� ���缭 �˾Ƽ� �����.
}
//�����ε�: �����̸��� �Լ��� �Ű������� ������, Ÿ���� �ٸ����Ͽ� ������ �����ϴ°�.
namespace Overloading
{
	int Sum(int a, int b, int c) { return a + b + c; }
	int Sum(int a, int b) { return a + b; }
	int Sum(int a) { return a; }
	int Sum() { return 0; }

	void FunctionTestMain()
	{
		cout << "Sum(3):"<<Sum(10,20,30) << endl;
		cout << "Sum(2):" << Sum(10, 20) << endl;
		cout << "Sum(1):" <<Sum(10) << endl;
		cout << "Sum(0):" <<Sum() << endl;
	}
}
//����Ʈ�Ű�����: �Ű������� ���� ��������������. �⺻ �ʱ�ȭ ���� �����ȴ�.
namespace DefaultPrameta
{
	//�ζ����Լ�: �����Ϸ����� �Լ��� ȣ�� ��ſ� ������ �ִ°�.
	inline int Sum(int a = 10, int b = 20, int c = 30) { return a + b + c; }

	void FunctionTestMain()
	{
		cout << "Sum(3):" << Sum(10, 20, 30) << endl;
		cout << "Sum(2):" << Sum(10, 20) << endl;
		cout << "Sum(1):" << Sum(10) << endl;
		cout << "Sum(0):" << Sum() << endl;
	}
	//��, 1���̿����Ѵ�. �����Ϸ��ܰ迡�� ����ȭ �Ǵ°��̱� ������ ���δٰ��ؼ��ݵ�� inline�Լ��� �Ǵ°��� �ƴϴ�.
	//�Լ��� ȣ���� �ٿ� ������ ����Ų��.
	void InlineFunctionTestMain()
	{
		//�ζ����Լ��� �����Ϸ����� ����ȭ �Ǹ� ������ ���� �Լ� ȣ���ſ� �ڵ带 �־��ش�.
		cout << "Sum(3):" << 10+20+30 << endl;
		cout << "Sum(2):" << 10+20+30 << endl;
		cout << "Sum(1):" << 10+20+30 << endl;
		cout << "Sum(0):" << 10+20+30 << endl;
	}
}

void main()
{
	//HelloWorldMain();
	//NamespaceTestMain();
	Overloading::FunctionTestMain();
	//DefaultPrameta::FunctionTestMain();
	DefaultPrameta::InlineFunctionTestMain();
}