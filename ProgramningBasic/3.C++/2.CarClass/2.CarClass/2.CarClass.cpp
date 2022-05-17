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

void StructCarTestMain()
{
	SCar sCar;
	CarInit(sCar, "red");
	CarDashBoard(sCar);
	CarSetGear(sCar, SCar::E_GEAR::D);
	CarDashBoard(sCar);
	CarAccel(sCar);
	CarDashBoard(sCar);
	CarBreak(sCar);
	CarDashBoard(sCar);
}

class CCar //클래스: 함수와 변수를 묶어서 나타낸것(캡슐화)
{
public://클래스외부에서 함수의 접근을 허용한다.
	//자동차의 조작은 도둑이 타서도 조작하면 자동차는 움직일수있다.
	//멤버함수: 멤버함수는 외부에서 변수를 변경하기 위해서 사용하는 메세지.
	enum E_GEAR { P, R, N, D };

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
	CCar cCar;
	cCar.Init("red");
	//은닉: 멤버변수를 외부에서 함부로 변경할수 없도록 만드는것.
	//cCar.strColor = "blue"; //길을 지나가던 누군가가 내차의 페인트칠을 했다. -> 범법행위
	cCar.SetColor("blue"); //내 허락을 받아 자동차 색상을 변경한다 -> 불법아님.
	cCar.SetGear(CCar::E_GEAR::D);
	cCar.DashBoard();
	cCar.Accel();
	cCar.DashBoard();
	cCar.Break();
	cCar.DashBoard();
}


void main()
{
	StructCarTestMain();
}