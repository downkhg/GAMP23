#include <iostream>

using namespace std; //표준함수의 네임스페이스를 사용한다.
//이름공간: 전역에 있는 변수나 함수를 포함시켜 나누어 사용할수있음.
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
	g_nData = 30; //둘중 하나의 네임스페이스만 사용해야 문법이 작동한다.

	A::PrintData();
	B::PrintData();
	PrintData();
}

void HelloWorldMain()
{
	int nData = 100;
	printf("Hello World !!\nData:%d\n", nData);
	std::cout << "Hello World !!\nData:" << nData << std::endl; 
	//printf("Hello World !!\nData:%c\n",nData);//프로그래머가 출력할때 타입에 맞게 출력해야함.
	//cout << "Hello World !!\nData:"<< (char)nData << endl; //타입에 맞춰서 알아서 출력함.
}
//오버로딩: 같은이름의 함수를 매개변수의 개수나, 타입을 다르게하여 여러개 정의하는것.
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
//디폴트매개변수: 매개변수에 값을 지정하지않으면. 기본 초기화 값이 설정된다.
namespace DefaultPrameta
{
	//인라인함수: 컴파일러에서 함수의 호출 대신에 계산식을 넣는것.
	inline int Sum(int a = 10, int b = 20, int c = 30) { return a + b + c; }

	void FunctionTestMain()
	{
		cout << "Sum(3):" << Sum(10, 20, 30) << endl;
		cout << "Sum(2):" << Sum(10, 20) << endl;
		cout << "Sum(1):" << Sum(10) << endl;
		cout << "Sum(0):" << Sum() << endl;
	}
	//단, 1줄이여야한다. 컴파일러단계에서 최적화 되는것이기 때문에 붙인다고해서반드시 inline함수가 되는것은 아니다.
	//함수의 호출을 줄여 성능을 향상시킨다.
	void InlineFunctionTestMain()
	{
		//인라인함수가 컴파일러에서 최적화 되면 다음과 같이 함수 호출대신에 코드를 넣어준다.
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