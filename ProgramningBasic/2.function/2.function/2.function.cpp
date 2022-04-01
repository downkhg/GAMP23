#include <stdio.h>

//사용자 정의함수: 사용자가 함수의 내용을 만들어서 제공하는 함수.
//함수의 선언: 컴파일러에게 이러한 함수가 있다는 것을 알림.
void FunctionTestMain();
void CaculatorLoofMain();

//리턴타입 함수명(매개변수...)
int Sum(int a, int b);
float CircleArea(int rad);
void ASCIICodeCheck(); //정의로 이동:F12
float ArrivalTimeSec(float dist, float speed);
char GradeCheck(int nScore);
float Caculator(float fDataA, float fDataB, char cOp);

void main()
{
	FunctionTestMain();//함수의 호출
	CaculatorLoofMain();
}

//함수의 정의: 선언된함수의 내용을 만드는 것.
//두수를 더하는 함수
int Sum(int a, int b)
{
	int c = a + b;
	return c;
}
//원의 면적구하기.(단, 면적은 반지름제곱*원주율(3.141592)이다.)
float CircleArea(int rad)
{
	const float pi = 3.141592;//상수변수: 초기화된 값을 변경할 수 없는 변수.
	float area;
	area = rad * rad * pi; //area = rad * rad * 3.141592; //컴파일될때 이런식으로 치환된다.
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

//거리와 속도를 입력하면 도착시간을 계산하는 함수.
float ArrivalTimeSec(float dist, float speed)
{
	float time = dist / speed;
	return time;
}

//점수를 입력받아서 학점을 돌려주는 함수
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

//계산기 만들기
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
		return -1.0f; //리턴을 만나면 함수는 종료된다.
	}

	return fResult;
}

//계산기 만들기
//1. 계산기 -> (숫자:변수:정수?실수!)와 (연산자:변수:문자)를 (입력:scanf)하면 그(결과:변수:실수)를 출력하는 기계.
//2. 연산자는 사칙연산만 가능하다(+,-,*,/)
//3. 연산을 하기위해서 최소 2개의 변수가 필요하므로 2개만 사용한다.
//4. 계산을 종료할때까지 (반복)해서 결과를 입력하고, 확인할수있다.
//데이터: 숫자A, 숫자B, 연산자, 결과
//알고리즘: 숫자와 연산자를 입력받고, 
//		    두수를 사칙연산하는 함수를 호출하고 그결과를 출력한다.
void CaculatorLoofMain()
{
	float fDataA, fDataB, fResult; //두값을 입력하는 실수형변수와 정답을 입력하는 변수를 만들었다. 초기화 되지않았으므로 모든 변수의 값은 알수없다.
	char cOp = 0; //연산자를 입력받기위해서 정수형변수를 선언하고 초기화지 않았다.

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
	//특정연산을 하고 결과값을 반환하는 함수.
	printf("10+20 = %d\n", Sum(10, 20));
	printf("radius:5 Area:%f\n", CircleArea(5));
	printf("Distacne:100 Speed:10 Sec:%f\n", ArrivalTimeSec(100, 10));
	printf("Score:100 Gread:%c\n", GradeCheck(100));
	//특정 내용을 출력해주고 끝나는 함수.
	ASCIICodeCheck();
}