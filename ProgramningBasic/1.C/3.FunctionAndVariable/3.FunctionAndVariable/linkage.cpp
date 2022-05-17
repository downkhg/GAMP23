#include <stdio.h>

int g_nDataC;

void PrintDataC()
{
	printf("PrintDataC: %d\n",g_nDataC);
}

static int g_nDataD;//정적전역변수: 이파일에서만 접근가능한 전역변수

static void PrintDataD() //정적함수: 이파일에서만 접근가능한 함수
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

//main함수는 os에서 호출하는데,
//1개이상인경우 무엇을 불러야할지 알수없으므로 오류발생
//void main()
//{
//
//}