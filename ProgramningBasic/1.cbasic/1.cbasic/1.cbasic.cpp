#include <stdio.h>//표준입출력 라이브러리 //주석: 컴파일러가 분석하지않는 문장.
//라이브러리: 필요할때 함수를 가져다쓰기위해 필요한것.

//두수의 값을 구하는 프로그램.
void SumMain()//사용자정의함수: 내가 만든 함수.
{
	//변수: 데이터를 저장하는 상자
	int a = 10;//초기화: 변수생성시 데이터를 넣음.
	int b = 20;
	int c = a + b;
	printf("%d + %d = %d", a, b, c); //라이브러리함수: 라이브러리가 제공하는 함수.
}

void CircleAreaMain()
{

}

void main()
{
	//Ctrl+F5
	printf("Hello World!!!\n");//출력함수 //\n:줄바꿈문자
	SumMain();//세미콜론: 문장의 끝에 들어가는 기호
	CircleAreaMain();
}