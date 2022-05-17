#include <iostream>

using namespace std;

//�߻�ȭ
//�Ӽ�(����): �ӵ�, ���, ����
//����(�˰��� - ����): ����, �극��ũ, ����

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

class CCar //Ŭ����: �Լ��� ������ ��� ��Ÿ����(ĸ��ȭ)
{
public://Ŭ�����ܺο��� �Լ��� ������ ����Ѵ�.
	//�ڵ����� ������ ������ Ÿ���� �����ϸ� �ڵ����� �����ϼ��ִ�.
	//����Լ�: ����Լ��� �ܺο��� ������ �����ϱ� ���ؼ� ����ϴ� �޼���.
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
private: //�Լ��� �ܺο��� ������ �����Ѵ�.
	//�������: �Ϲ������� private�Ѵ�.
	int nSpeed; //�ӵ��� �������� �������� 0���� ������ ������ �����ϰ�, �극��ũ�� ������ �ӵ��� �����Ѵ�.
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
	//����: ��������� �ܺο��� �Ժη� �����Ҽ� ������ ����°�.
	//cCar.strColor = "blue"; //���� �������� �������� ������ ����Ʈĥ�� �ߴ�. -> ��������
	cCar.SetColor("blue"); //�� ����� �޾� �ڵ��� ������ �����Ѵ� -> �ҹ��ƴ�.
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