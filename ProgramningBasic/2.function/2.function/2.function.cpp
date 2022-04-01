#include <stdio.h>

//����� �����Լ�: ����ڰ� �Լ��� ������ ���� �����ϴ� �Լ�.
//�Լ��� ����: �����Ϸ����� �̷��� �Լ��� �ִٴ� ���� �˸�.
void FunctionTestMain();
void CaculatorLoofMain();

//����Ÿ�� �Լ���(�Ű�����...)
int Sum(int a, int b);
float CircleArea(int rad);
void ASCIICodeCheck(); //���Ƿ� �̵�:F12
float ArrivalTimeSec(float dist, float speed);
char GradeCheck(int nScore);
float Caculator(float fDataA, float fDataB, char cOp);

void main()
{
	FunctionTestMain();//�Լ��� ȣ��
	CaculatorLoofMain();
}

//�Լ��� ����: ������Լ��� ������ ����� ��.
//�μ��� ���ϴ� �Լ�
int Sum(int a, int b)
{
	int c = a + b;
	return c;
}
//���� �������ϱ�.(��, ������ ����������*������(3.141592)�̴�.)
float CircleArea(int rad)
{
	const float pi = 3.141592;//�������: �ʱ�ȭ�� ���� ������ �� ���� ����.
	float area;
	area = rad * rad * pi; //area = rad * rad * 3.141592; //�����ϵɶ� �̷������� ġȯ�ȴ�.
	return area;
}
//0~128
void ASCIICodeCheck()
{
	for (int i = 0; i < 128; i++)
	{
		printf("%d:%c,", i, i);
		if (i % 12 == 0) printf("\n");
	}
}

//�Ÿ��� �ӵ��� �Է��ϸ� �����ð��� ����ϴ� �Լ�.
float ArrivalTimeSec(float dist, float speed)
{
	float time = dist / speed;
	return time;
}

//������ �Է¹޾Ƽ� ������ �����ִ� �Լ�
char GradeCheck(int nScore)
{
	char cGrade;

	if (nScore >= 90)
	{
		cGrade = 'A';
	}
	else if (nScore >= 80)
	{
		cGrade = 'B';
	}
	else if (nScore >= 70)
	{
		cGrade = 'C';
	}
	else if (nScore >= 60)
	{
		cGrade = 'D';
	}
	else
	{
		cGrade = 'F';
	}

	return cGrade;
}

//���� �����
float Caculator(float fDataA, float fDataB, char cOp)
{
	float fResult;

	if (cOp == '+')
		fResult = fDataA + fDataB;
	else if (cOp == '-')
		fResult = fDataA - fDataB;
	else if (cOp == '*')
		fResult = fDataA * fDataB;
	else if (cOp == '/')
		fResult = fDataA / fDataB;
	else
	{
		printf("%c is not Support!\n", cOp);
		return -1.0f; //������ ������ �Լ��� ����ȴ�.
	}

	return fResult;
}

//���� �����
//1. ���� -> (����:����:����?�Ǽ�!)�� (������:����:����)�� (�Է�:scanf)�ϸ� ��(���:����:�Ǽ�)�� ����ϴ� ���.
//2. �����ڴ� ��Ģ���길 �����ϴ�(+,-,*,/)
//3. ������ �ϱ����ؼ� �ּ� 2���� ������ �ʿ��ϹǷ� 2���� ����Ѵ�.
//4. ����� �����Ҷ����� (�ݺ�)�ؼ� ����� �Է��ϰ�, Ȯ���Ҽ��ִ�.
//������: ����A, ����B, ������, ���
//�˰���: ���ڿ� �����ڸ� �Է¹ް�, 
//		    �μ��� ��Ģ�����ϴ� �Լ��� ȣ���ϰ� �װ���� ����Ѵ�.
void CaculatorLoofMain()
{
	float fDataA, fDataB, fResult; //�ΰ��� �Է��ϴ� �Ǽ��������� ������ �Է��ϴ� ������ �������. �ʱ�ȭ �����ʾ����Ƿ� ��� ������ ���� �˼�����.
	char cOp = 0; //�����ڸ� �Է¹ޱ����ؼ� ������������ �����ϰ� �ʱ�ȭ�� �ʾҴ�.

	while (cOp != 'x')
	{
		printf("ex) 1+1 exit)?x?>> "); //
		scanf("%f%c%f", &fDataA, &cOp, &fDataB); //

		fResult = Caculator(fDataA, fDataB, cOp);

		printf("%f%c%f=%f\n", fDataA, cOp, fDataB, fResult);
	}
}

void FunctionTestMain()
{
	//Ư�������� �ϰ� ������� ��ȯ�ϴ� �Լ�.
	printf("10+20 = %d\n", Sum(10, 20));
	printf("radius:5 Area:%f\n", CircleArea(5));
	printf("Distacne:100 Speed:10 Sec:%f\n", ArrivalTimeSec(100, 10));
	printf("Score:100 Gread:%c\n", GradeCheck(100));
	//Ư�� ������ ������ְ� ������ �Լ�.
	ASCIICodeCheck();
}