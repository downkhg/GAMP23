#include <stdio.h> //���̺귯��: �ʿ��� ���(�Լ�)�� �����ϴ� ��. 
//1.�Լ��� �����ϱ�? �� �ʿ��ұ�? 
//1)������ ����� ��Ȱ���Ѵ�. 
//2)�ݺ����� �ڵ带 ��Ÿ�鼭 ���������� ���� �� �� �ִ�.
//3)�Ű������� Ȱ���Ͽ� �Լ� �ȿ� ���� �����ϰ�, 
//4)�� ������ ���� ����� ������ �̿��Ͽ� �Լ� ������ ��������.
//2.�Լ��� ������ �� �ʿ��Ѱ�?
//��������. �����Ϸ��� ������ ���� ����Ǳ⶧���� ���Լ��� �⺻���� ������ �˾ƾ߸� �Ʒ� �Լ����� ȣ�Ⱑ���ϱ⶧���Դϴ�.

//���̺귯���Լ�: ����ڰ� ���������ʰ� �⺻���� �����Ǵ� �Լ� 
// ex) stdio.h -> scanf,printf stdlib.h -> srand, rand
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

void main() //1
{
	//F9: �극��ŷ ����Ʈ ����
	//F5: ����Ÿ��� ���� //shift+F5: ����� �ߴ�
	//F11: �Լ������� �̵� //F10: �Լ��������� 1�� �� �̵�
	FunctionTestMain();//�Լ��� ȣ�� //2
	CaculatorLoofMain();//101
}//109

//�Լ��� ����: ������Լ��� ������ ����� ��.
//�μ��� ���ϴ� �Լ�
int Sum(int a, int b)
{
	int c = a + b;//4
	return c;//5
}
//���� �������ϱ�.(��, ������ ����������*������(3.141592)�̴�.)
float CircleArea(int rad)
{
	const float pi = 3.141592;//�������: �ʱ�ȭ�� ���� ������ �� ���� ����. //7
	float area; //8
	area = rad * rad * pi; //area = rad * rad * 3.141592; //9 //�����ϵɶ� �̷������� ġȯ�ȴ�.
	return area; //10
}
//0~128
void ASCIICodeCheck()
{
	for (int i = 0; i <= 128; i++) //19 //23
	{
		printf("%d:%c,", i, i); //20 //24
		if (i % 12 == 0) //21 //25 
			printf("\n"); //22
	} //100
}

//�Ÿ��� �ӵ��� �Է��ϸ� �����ð��� ����ϴ� �Լ�.
float ArrivalTimeSec(float dist, float speed)
{
	float time = dist / speed; //12
	return time; //13
}

//������ �Է¹޾Ƽ� ������ �����ִ� �Լ�
char GradeCheck(int nScore)
{
	char cGrade;//15

	if (nScore >= 90)//16
	{
		cGrade = 'A';//17
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

	return cGrade;//18
}

//���� �����
float Caculator(float fDataA, float fDataB, char cOp)
{
	float fResult; //108

	if (cOp == '+')//+ //109 //x
		fResult = fDataA + fDataB;// 1+1 = 2 //110
	else if (cOp == '-') //110
		fResult = fDataA - fDataB;
	else if (cOp == '*') //111
		fResult = fDataA * fDataB;
	else if (cOp == '/') //112
		fResult = fDataA / fDataB;
	else //113
	{
		printf("%c is not Support!\n", cOp); //x is not support!
		return -1.0f; //������ ������ �Լ��� ����ȴ�.
	}

	return fResult; //111
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
	float fDataA, fDataB, fResult; //�ΰ��� �Է��ϴ� �Ǽ��������� ������ �Է��ϴ� ������ �������. �ʱ�ȭ �����ʾ����Ƿ� ��� ������ ���� �˼�����. //102
	char cOp = 0; //�����ڸ� �Է¹ޱ����ؼ� ������������ �����ϰ� �ʱ�ȭ�� �ʾҴ�. //103

	while (cOp != 'x') //104
	{
		printf("ex) 1+1 exit)?x?>> "); //105
		scanf("%f%c%f", &fDataA, &cOp, &fDataB); //106 //1+1

		fResult = Caculator(fDataA, fDataB, cOp); //107 

		printf("%f%c%f=%f\n", fDataA, cOp, fDataB, fResult); //108 
	}
}

void FunctionTestMain()
{
	//Ư�������� �ϰ� ������� ��ȯ�ϴ� �Լ�.
	printf("10+20 = %d\n", Sum(10, 20));//3
	printf("radius:5 Area:%f\n", CircleArea(5));//6
	printf("Distacne:100 Speed:10 Sec:%f\n", ArrivalTimeSec(100, 10));//11
	printf("Score:100 Gread:%c\n", GradeCheck(100));//14
	//Ư�� ������ ������ְ� ������ �Լ�.
	ASCIICodeCheck(); //17
} 