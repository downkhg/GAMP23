#include <stdio.h>//표준입출력 라이브러리 //주석: 컴파일러가 분석하지않는 문장.
//라이브러리: 필요할때 함수를 가져다쓰기위해 필요한것.
#define PI 3.141592 //기호상수: 컴파일 시에 기호가있는곳에 해당 값을 넣어줌.
//두수의 값을 구하는 프로그램.
void SumMain()//사용자정의함수: 내가 만든 함수.
{
	//변수: 데이터를 저장하는 상자
	//타입: float,double(실수), int(정수),char(문자)
	int a = 10;//초기화: 변수생성시 데이터를 넣음.
	int b = 20;
	int c = a + b;
	printf("%d + %d = %d\n", a, b, c); //라이브러리함수: 라이브러리가 제공하는 함수.
}
//원의 면적구하기.(단, 면적은 반지름제곱*원주율(3.141592)이다.)
//데이터: 반지름(정수:int),원주율(실수:float),원의면적(실수) -> 
//알고리즘: 원의반지름은 입력받는다. 
//원의면적 = 반지름*반지름*원주율. 
//계산공식대로 정상작동하는 지 확인하기위해 모든 변수의 값을 수식으로 출력한다.
void CircleAreaMain()
{
	int rad = 0;
	const float pi = 3.141592;//상수변수: 초기화된 값을 변경할 수 없는 변수.
	//pi = 2; //상수변수를 변경을 시도하면 컴파일오류가 남.
	float area;
	printf("Radius? ");
	scanf("%d", &rad);
	area = rad * rad * PI; //area = rad * rad * 3.141592; //컴파일될때 이런식으로 치환된다.
	//area = rad * rad * pi;
	printf("%d * %d * %f = %f\n", rad, rad, pi, area);
}
//각각 타입과 변수의 크기를 출력하여라
//(단, sizeof()를 이용하면 크기를 젤수있다)
//int x, char, int , short, long, float, double
void ValSizeMain()
{
	int x;
	printf("x: %d\n", sizeof(x));
	printf("char: %d\n", sizeof(char));
	printf("int: %d\n", sizeof(int));
	printf("short: %d\n", sizeof(short));
	printf("long: %d\n", sizeof(long));
	printf("float: %d\n", sizeof(float));
	printf("double: %d\n", sizeof(double));
}
//0~128
void ASCIICodeTestMain()
{
	for (int i = 0; i < 128; i++)
	{
		printf("%d:%c,",i,i);
		if (i % 12 == 0) printf("\n");
	}
}

//태양과 지구사이의 거리가 d이고, 
//빛 속도가 s일때,
//태양에서 지구에 닿는 시간 t를 구하여라.
//s: 30만 km/s
//d: 14960만km
//t: 초단위
//심화: t를 분 초로 나타내보기
//데이터: distance, speed, time -> 변수: int//정수, float//실수, charX //문자x 
//알고리즘: d / s = t
//---------------- //d //- //s
//검증(=결과가 맞는지 확인)을 해야한다. -> 정수x 실수o -> 나누어 떨어지지않으므로 float
void LightSpeedMain()
{
	float dist = 14960;
	float speed = 30;
	float time = dist / speed;
	printf("Time:%f\n", time);
	printf("%f / %f = %f\n",dist,speed,time);
	int min = time / 60;
	//int sec = (int)time % 60;
	int sec = time - (min * 60);
	printf("%d:%d",min, sec);
}

void main()
{
	//Ctrl+F5
	printf("Hello World!!!\n");//출력함수 //\n:줄바꿈문자
	//SumMain();//세미콜론: 문장의 끝에 들어가는 기호
	//CircleAreaMain();
	//ValSizeMain();
	//ASCIICodeTestMain();
	LightSpeedMain();
}