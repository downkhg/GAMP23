#include <stdio.h>

int g_nDataC;

void PrintDataC()
{
	printf("PrintDataC: %d\n",g_nDataC);
}

static int g_nDataD;//������������: �����Ͽ����� ���ٰ����� ��������

static void PrintDataD() //�����Լ�: �����Ͽ����� ���ٰ����� �Լ�
{
	printf("PrintDataD: %d\n", g_nDataD);
}

void ExternVarFuncTestMain()
{
	g_nDataC = 100;
	PrintDataC();
}

void StaticVarFuncTestMain()
{
	g_nDataD = 200;
	PrintDataD();
}

//main�Լ��� os���� ȣ���ϴµ�,
//1���̻��ΰ�� ������ �ҷ������� �˼������Ƿ� �����߻�
//void main()
//{
//
//}