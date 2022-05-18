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

class CCar //Ŭ����: �Լ��� ������ ��� ��Ÿ����(ĸ��ȭ)
{
public://Ŭ�����ܺο��� �Լ��� ������ ����Ѵ�.
	//�ڵ����� ������ ������ Ÿ���� �����ϸ� �ڵ����� �����ϼ��ִ�.
	//����Լ�: ����Լ��� �ܺο��� ������ �����ϱ� ���ؼ� ����ϴ� �޼���.
	enum E_GEAR { P, R, N, D };
	//������: ��ü(����)�� �����ɶ� ȣ�� �Ǵ� �Լ�. 
	//�����ڵ� �Լ��̹Ƿ� �Ű������� ������ Ÿ���� �ٸ��� �����ε� �����ϴ�.
	//CCar()//�⺻������: �⺻������� �⺻������ �ʱ�ȭ�ϴ� ������.
	//{
	//	eGear = E_GEAR::N;
	//	nSpeed = 0;
	//	strColor = "none";
	//	cout << "DefaultCar(" << eGear << "," << nSpeed << "," << strColor <<")" << endl;
	//}
	//CCar(string color)//�Ű������� ���� ��ü ������ ���� ������ ���� ������ ������.
	//{
	//	eGear = E_GEAR::N;
	//	nSpeed = 0;
	//	strColor = color;
	//	cout << "PrameterCar(" << eGear << "," << nSpeed << "," << strColor << ")" << endl;
	//}
	CCar(string color = "gray")//����Ʈ�Ű������� Ȱ���Ͽ� ������ 1���� �⺻�����ڵ� ��ó��.
	{
		eGear = E_GEAR::N;
		nSpeed = 0;
		strColor = color;
		cout << "DefaultPrameterCar["<<this<<"](" << eGear << "," << nSpeed << "," << strColor << ")" << endl;
	}
	//�Ҹ���: ��ü(����)�� �Ҹ�ɶ� ȣ��Ǵ� �Լ�.
	~CCar()
	{
		cout << "~CCar[" << this << "](" << eGear << "," << nSpeed << "," << strColor << ")" << endl;
	}
	//���������: ��ü�� �����Ҷ� ȣ��Ǵ� �Լ�
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
	cout << "ClassCarTestMain Start" << endl;
	CCar cCar;//��������ÿ� ������ �����ϰ� �۾��� ��ħ.
	cCar.Init("red"); //�ֹ��ڰ� �ֹ��� �������� ������ �Ϸ���.
	//����: ��������� �ܺο��� �Ժη� �����Ҽ� ������ ����°�.
	//cCar.strColor = "blue"; //���� �������� �������� ������ ����Ʈĥ�� �ߴ�. -> ��������
	cCar.SetColor("blue"); //�� ����� �޾� �ڵ��� ������ �����Ѵ� -> �ҹ��ƴ�.
	cCar.SetGear(CCar::E_GEAR::D);
	cCar.DashBoard();
	cCar.Accel();
	cCar.DashBoard();
	cCar.Break();
	cCar.DashBoard();

	CCar cCarA("blue");//�ڵ����� �����Ҷ� �Ķ������� ������ �Ѵ�.
	cCarA.SetColor("green"); //�� ����� �޾� �ڵ��� ������ �����Ѵ� -> �ҹ��ƴ�.
	cCarA.SetGear(CCar::E_GEAR::D);
	cCarA.DashBoard();
	cCarA.Accel();
	cCarA.DashBoard();
	cCarA.Break();
	cCarA.DashBoard();
	cout << "ClassCarTestMain End" << endl;
}

CCar g_cCar;//���������� ��ü�� ���� �� �Ҹ�.

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
	//ClassCarTestMain(); //�������� ��ü�� ������ �Ҹ�
	//CarSwapTestMain(); //�Ű������� ��ü ���� �� �Ҹ�, �����ڿ� �����ʹ� ��ü�� �ƴϴ�.
	//StaticLocalCarTestMain(); //�������� ��ü�� ���� �� �Ҹ�
	DynamicAllocateTestMain(); //�����Ҵ� ��ü
	cout << "main End" << endl;
}