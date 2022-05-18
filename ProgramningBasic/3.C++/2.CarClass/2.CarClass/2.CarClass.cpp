#include <iostream>

using namespace std;

//추상화
//속성(변수): 속도, 기어, 색상
//동작(알고리즘 - 동작): 엑셀, 브레이크, 기어변경

struct SCar
{
	int nSpeed;
	string strColor;
	enum E_GEAR { P, R, N, D};
	E_GEAR eGear;
};

void CarInit(SCar& cCar, string color)
{
	cCar.eGear = SCar::E_GEAR::N;
	cCar.nSpeed = 0;
	cCar.strColor = color;
}

void CarAccel(SCar& cCar)
{
	cCar.nSpeed++;
}

void CarBreak(SCar& cCar)
{
	cCar.nSpeed--;
}

void CarSetGear(SCar& cCar, SCar::E_GEAR gear)
{
	cCar.eGear = gear;
}

void CarDashBoard(SCar& cCar)
{
	cout << "Color:" << cCar.strColor << endl;
	cout << "Speed:" << cCar.nSpeed << endl;
	cout << "Gear:" << cCar.eGear << endl;
}

class CCar //클래스: 함수와 변수를 묶어서 나타낸것(캡슐화)
{
public://클래스외부에서 함수의 접근을 허용한다.
	//자동차의 조작은 도둑이 타서도 조작하면 자동차는 움직일수있다.
	//멤버함수: 멤버함수는 외부에서 변수를 변경하기 위해서 사용하는 메세지.
	enum E_GEAR { P, R, N, D };
	//생성자: 객체(변수)가 생성될때 호출 되는 함수. 
	//생성자도 함수이므로 매개변수의 갯수나 타입이 다르면 오버로딩 가능하다.
	//CCar()//기본생성자: 기본멤버들을 기본값으로 초기화하는 생성자.
	//{
	//	eGear = E_GEAR::N;
	//	nSpeed = 0;
	//	strColor = "none";
	//	cout << "DefaultCar(" << eGear << "," << nSpeed << "," << strColor <<")" << endl;
	//}
	//CCar(string color)//매개변수를 통해 객체 내부의 값을 생성시 변경 가능한 생성자.
	//{
	//	eGear = E_GEAR::N;
	//	nSpeed = 0;
	//	strColor = color;
	//	cout << "PrameterCar(" << eGear << "," << nSpeed << "," << strColor << ")" << endl;
	//}
	CCar(string color = "gray")//디폴트매개변수를 활용하여 생성자 1개로 기본생성자도 대처함.
	{
		eGear = E_GEAR::N;
		nSpeed = 0;
		strColor = color;
		cout << "DefaultPrameterCar["<<this<<"](" << eGear << "," << nSpeed << "," << strColor << ")" << endl;
	}
	//소멸자: 객체(변수)가 소멸될때 호출되는 함수.
	~CCar()
	{
		cout << "~CCar[" << this << "](" << eGear << "," << nSpeed << "," << strColor << ")" << endl;
	}
	//복사생성자: 객체를 복사할때 호출되는 함수
	CCar(CCar& car)
	{
		*this = car;
		cout << "CopyCCar[" << this << "](" << eGear << "," << nSpeed << "," << strColor << ")" << endl;
	}
	void Init(string color)
	{
		eGear = E_GEAR::N;
		nSpeed = 0;
		strColor = color;
	}

	void Accel()
	{
		nSpeed++;
	}

	void Break()
	{
		nSpeed--;
	}

	void SetGear(CCar::E_GEAR gear)
	{
		eGear = gear;
	}

	void SetColor(string color)
	{
		strColor = color;
	}

	void DashBoard()
	{
		cout << "Color:" << strColor << endl;
		cout << "Speed:" << nSpeed << endl;
		cout << "Gear:" << eGear << endl;
	}
private: //함수의 외부에서 접근을 금지한다.
	//멤버변수: 일반적으로 private한다.
	int nSpeed; //속도는 물리적인 현상으로 0부터 엑셀을 밟으면 증가하고, 브레이크를 밟으면 속도가 감소한다.
	string strColor;
	E_GEAR eGear;
};

void StructCarTestMain()
{
	SCar sCar;
	CarInit(sCar, "red");
	sCar.strColor = "blue";
	CarDashBoard(sCar);
	CarSetGear(sCar, SCar::E_GEAR::D);
	CarDashBoard(sCar);
	CarAccel(sCar);
	CarDashBoard(sCar);
	CarBreak(sCar);
	CarDashBoard(sCar);
}

void ClassCarTestMain()
{
	cout << "ClassCarTestMain Start" << endl;
	CCar cCar;//차량생산시에 도색을 제외하고 작업을 마침.
	cCar.Init("red"); //주문자가 주문한 색상으로 도색을 완료함.
	//은닉: 멤버변수를 외부에서 함부로 변경할수 없도록 만드는것.
	//cCar.strColor = "blue"; //길을 지나가던 누군가가 내차의 페인트칠을 했다. -> 범법행위
	cCar.SetColor("blue"); //내 허락을 받아 자동차 색상을 변경한다 -> 불법아님.
	cCar.SetGear(CCar::E_GEAR::D);
	cCar.DashBoard();
	cCar.Accel();
	cCar.DashBoard();
	cCar.Break();
	cCar.DashBoard();

	CCar cCarA("blue");//자동차를 생산할때 파란색으로 도색을 한다.
	cCarA.SetColor("green"); //내 허락을 받아 자동차 색상을 변경한다 -> 불법아님.
	cCarA.SetGear(CCar::E_GEAR::D);
	cCarA.DashBoard();
	cCarA.Accel();
	cCarA.DashBoard();
	cCarA.Break();
	cCarA.DashBoard();
	cout << "ClassCarTestMain End" << endl;
}

CCar g_cCar;//전역변수와 객체의 생성 및 소멸.

void CarSwapVar(CCar a, CCar b)
{
	cout << "CarSwapVar(" << &a << "," << &b << ")"<<endl;
	CCar temp = a;
	a = b;
	b = temp;
}

void CarSwapRef(CCar& a, CCar& b)
{
	cout << "CarSwapRef(" << &a << "," << &b << ")" << endl;
	CCar temp = a;
	a = b;
	b = temp;
}

void CarSwapPtr(CCar* a, CCar* b)
{
	cout << "CarSwapPtr(" << a << "," << b << ")" << endl;
	CCar temp = *a;
	*a = *b;
	*b = temp;
}

void CarSwapTestMain()
{
	cout << "CarSwapTestMain Start" << endl;
	CCar cCarBlue("blue");
	CCar cCarRed("red");
	cCarBlue.DashBoard();
	cCarRed.DashBoard();
	CarSwapVar(cCarBlue, cCarRed);
	cCarBlue.DashBoard();
	cCarRed.DashBoard();
	CarSwapRef(cCarBlue, cCarRed);
	cCarBlue.DashBoard();
	cCarRed.DashBoard();
	CarSwapPtr(&cCarBlue, &cCarRed);
	cCarBlue.DashBoard();
	cCarRed.DashBoard();
	cout << "CarSwapTestMain End" << endl;
}

void StaticLocalCar()
{
	cout << "StaticLocalCar Start" << endl;
	static CCar cCar;
	cout << "StaticLocalCar End" << endl;
}

void StaticLocalCarTestMain()
{
	cout << "StaticLocalCarTestMain Start" << endl;
	for (int i = 0; i < 3; i++)
		StaticLocalCar();
	cout << "StaticLocalCarTestMain End" << endl;
}

void DynamicAllocateTestMain()
{
	cout << "DynamicAllocateTestMain 1" << endl;
	CCar* pCar = NULL;
	cout << "DynamicAllocateTestMain 2" << endl;
	pCar = new CCar();
	delete pCar;
	cout << "DynamicAllocateTestMain 3" << endl;
	pCar = new CCar[3];
	delete[] pCar;
	cout << "DynamicAllocateTestMain 4" << endl;
}

void main()
{
	cout << "main Start" << endl;
	//StructCarTestMain();
	//ClassCarTestMain(); //지역변수 객체의 생성과 소멸
	//CarSwapTestMain(); //매개변수의 객체 생성 및 소멸, 참조자와 포인터는 객체가 아니다.
	//StaticLocalCarTestMain(); //정적지역 객체의 생성 및 소멸
	DynamicAllocateTestMain(); //동적할당 객체
	cout << "main End" << endl;
}