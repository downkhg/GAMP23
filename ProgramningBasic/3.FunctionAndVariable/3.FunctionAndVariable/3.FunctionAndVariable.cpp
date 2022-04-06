#include <stdio.h>
//전역변수와 지역변수
//(함수)에 (지역변수)는 함수 내부에서만 사용가능하지만 (전역변수)는 (어떤 함수)에서도 사용가능하다.
//(집)에 (집밥)은 집에서만 먹을 수 있지만 (배달음식)은 (어느 집)에서나 시켜먹을수있다.

//전역변수: 모든함수에서 접근이 가능한 변수. 프로그램이 종료될때 삭제.
int g_nDataA = 10;
int g_nDataB = 20;

//매개변수를 활용하여 함수 안에 값을 전달하고, 
//그 값으로 계산된 결과를 리턴을 이용하여 함수 밖으로 내보낸다.
//리턴되면 함수가 종료되므로 1개이상의 값을 함수외부로 내보낼 수 없다.
//변수는 메모리에 생성된다.
//매개변수도 일종의 지역변수다.

//기초
//1. 지역변수와 전역변수의 차이점은 무엇인가?
//2. 지역변수와 전역변수는 언제 생성되고 언제 소멸되는가?
//3. 전역변수와 지역변수를 사용하는 이유는 무엇인가?
//심화
//4. 전역변수는 어떻게 모든 함수에서 접근이 가능한가?
//5. 지역변수는 왜 함수가 소멸하면 삭제가되는가?

int Sum(int a, int b)//매개변수: 함수내부에 데이터를 전달하는 변수 //매개변수 a,b가 생성된다. //생성된 a,b에 인수로 전달된 값이 복사된다.
{
	printf("Sum - g_nDataA/B[%d/%d]%d/%d\n", &g_nDataA, &g_nDataB, g_nDataA, g_nDataB); //9

	printf("Sum-a:%d,b:%d\n", &a, &b); //10
	int c = a + b; //11 //변수c를 생성하고, a와 b의 계산 결과를 대입한다.
	return c; //12 //변수c가 가진값을 함수 밖으로 내보낸다. //함수가 종료되어 매개변수(a,b)와 지역변수(c)가 소멸한다.
}

void SumParametarTestMain()
{
	printf("SumParametarTestMain - g_nDataA/B[%d/%d]%d/%d\n", &g_nDataA, &g_nDataB, g_nDataA, g_nDataB); //4

	//지역변수: 함수내부에서만 존재하는 함수. 함수가 종료될때({}가 끝날때) 삭제된다.
	int nDataA = 10; //5 //nDataA라는 변수가 생성된다.
	int nDataB = 20; //6 //nDataB라는 변수가 생성된다.
	printf("nDataA:%d, nDataB:%d\n", &nDataA, &nDataB); //7
	//nDataA와 a, nDataB 와 b는 같은 변수인가? X
	//nDataA와 a, nDataB 와 b는 같은 값인가? O
	//아파트1동과 2동에 집은 모양(데이터)같다. O
	//아파트1동과 2동은 주소(변수)가 같은가? X
	int nResult = Sum(nDataA, nDataB); //8 //함수 c가 가진값을 nResult변수를 만들고 값을 복사한다.

	printf("%d + %d = %d\n", nDataA, nDataB, nResult);//13
}//함수가 종료되면 nDataA, nDataB, nResult가 소멸한다.

void StaticLocalVarCount()
{
	static int nStaticLocalVar = 0; //정적지역변수: 변수의 호출이 끝난뒤에도 값이 유지가되는 변수.
	int nLocalVar = 0; //지역변수

	nStaticLocalVar++;
	nLocalVar++;

	printf("nStaticLocalVar:%d\n",nStaticLocalVar); //1 //2 //3
	printf("nLocalVar:%d\n", nLocalVar); //1 //1 //1
}

void StaticLocalVarTestMain()
{
	printf("##### StaticLocalVarTestMain #####\n");
	for (int i = 0; i < 3; i++) // 0,1,2
		StaticLocalVarCount(); //
	printf("##################################\n");
}

extern int g_nDataC; //전역변수는 다른파일에 있다.
extern void PrintDataC(); //이 함수는 다른파일에 정의되어있다.
extern void ExternVarFuncTestMain();

////정적지역변수/함수는 extern을 하더라도 다른파일에서는 사용이 불가능하다. 
//extern int g_nDataD; 
//extern void PrintDataD(); 
//정적지역변수/함수를 접근할때는 일반 함수를 외부에서 접근하여 사용해야한다.
extern void StaticVarFuncTestMain();

void ExternFileTestMain()
{
	printf("##### ExternFileTestMain #####\n");
	g_nDataC = 110;
	PrintDataC();

	ExternVarFuncTestMain();

	//g_nDataD = 220;
	//PrintDataD();

	StaticVarFuncTestMain();
	printf("##################################\n");
}

void main()//1
{
	printf("main - g_nDataA/B[%d/%d]%d/%d\n", &g_nDataA, &g_nDataB, g_nDataA, g_nDataB); //2
	//SumParametarTestMain(); //3
	StaticLocalVarTestMain();
	ExternFileTestMain();
	////컴파일오류 - SumParametarTestMain의 변수다. main에서는 접근이 불가능하다.
	//nDataA = 10; 
}//14 main함수가 종료되면 프로그램이 종료되므로 전역변수인 g_nDataA, g_nDataB가 소멸한다.