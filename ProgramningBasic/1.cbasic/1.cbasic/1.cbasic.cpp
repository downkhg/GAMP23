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
//전위연산자:++data,후위연산자:data++ 
//데이터의 값이 전위연산자와 후위 연산자의 차이점을 확인하는 프로그램
//데이터: 데이터2개가 필요하다 -> nDataA,nDataB -> 정수
//알고리즘: nDataB = ++nDataA, nDataB = nDataA++, ?
void IncDecTestMain()
{
	int nDataA = 10, nDataB; //10, ?
	nDataB = nDataA; //10
	printf("1.nDataA/B:%d/%d\n",nDataA,nDataB);
	nDataB = ++nDataA; //11/11 ->  전위연산자: 대입연산자보다 우선순위가 높으므로, 증감하고, 값이 변수에 대입된다.
	printf("2.nDataA/B:%d/%d\n", nDataA, nDataB);
	nDataB = nDataA++; //12/12 -> 12/11 -> 후위연산자는 대입연산자보다 우선순위가 낮으므로, 증감전 값이 변수에 대입된다.
	printf("3.nDataA/B:%d/%d\n", nDataA, nDataB);
}
//점수를 입력받아서 학점을 출력하는 프로그램
//(A: 90이상 B: 80점이상 C: 70점이상 D: 60점이상 F: 60점미만)
//데이터: 점수->정수, 학점->문자
//알고리즘: 입력받은 점수가 (A: 90이상 B: 80점이상 C: 70점이상 D: 60점이상 F: 60점미만) 에 해당되면 학점을 출력하기
void GradeTestMain()
{
	int nScore;
	char cGrade;

	printf("Score:");
	scanf("%d", &nScore);

	if (nScore >= 90)
	{
		cGrade = 'A';
	}
	else
	{
		if (nScore >= 80)
		{
			cGrade = 'B';
		}
		else
		{
			if (nScore >= 70)
			{
				cGrade = 'C';
			}
			else
			{
				if (nScore >= 60)
				{
					cGrade = 'D';
				}
				else
				{
					cGrade = 'F';
				}
			}
		}
	}

	printf("Score/Grade:%d/%c",nScore,cGrade);
}

void GradeTestMain2()
{
	int nScore;
	char cGrade;

	printf("Score:");
	scanf("%d", &nScore);

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

	printf("Score/Grade:%d/%c", nScore, cGrade);
}
//계산기 만들기
//1. 계산기 -> (숫자:변수:정수?실수!)와 (연산자:변수:문자)를 (입력:scanf)하면 그(결과:변수:실수)를 출력하는 기계.
//2. 연산자는 사칙연산만 가능하다(+,-,*,/)
//3. 연산을 하기위해서 최소 2개의 변수가 필요하므로 2개만 사용한다.
//데이터: 숫자A, 숫자B, 연산자, 결과
//알고리즘: 숫자와 연산자를 입력받고, 
//		    입력받은 연산자가 +면 두수를 더하여 결과에 넣는다.
//		    입력받은 연산자가 -면 두수를 빼고 결과에 넣는다.
//		    입력받은 연산자가 *면 두수를 곱하고 결과에 넣는다.
//		    입력받은 연산자가 /면 두수를 나누고 결과에 넣는다.
void CaculatorMain()
{
	float fDataA, fDataB, fResult;
	char cOp;
	//scanf("%f", &fDataA);
	//scanf("%f", &fDataB);
	//scanf("%c", &cOp);
	printf("ex) 1+1 >> ");
	scanf("%f%c%f",&fDataA,&cOp,&fDataB);

	if(cOp == '+')
		fResult = fDataA + fDataB;
	else if (cOp == '-')
		fResult = fDataA - fDataB;
	else if (cOp == '*')
		fResult = fDataA * fDataB;
	else if (cOp == '/')
		fResult = fDataA / fDataB;
	else
	{
		printf("%c is not Support!\n",cOp);
		return; //리턴을 만나면 함수는 종료된다.
	}

	printf("%f%c%f=%f",fDataA,cOp, fDataB, fResult);
}

void CaculatorSwitchMain()
{
	float fDataA, fDataB, fResult;
	char cOp;
	//scanf("%f", &fDataA);
	//scanf("%f", &fDataB);
	//scanf("%c", &cOp);
	printf("ex) 1+1 >> ");
	scanf("%f%c%f", &fDataA, &cOp, &fDataB);

	switch (cOp)
	{
	case '+':
		fResult = fDataA + fDataB;
		break;
	case '-':
		fResult = fDataA - fDataB;
		break;
	case '*':
		fResult = fDataA * fDataB;
		break;
	case '/':
		fResult = fDataA / fDataB;
		break;
	default:
		printf("%c is not Support!\n", cOp);
		return; //리턴을 만나면 함수는 종료된다.
		break;
	}
	
	printf("%f%c%f=%f", fDataA, cOp, fDataB, fResult);
}

//계산기 만들기
//1. 계산기 -> (숫자:변수:정수?실수!)와 (연산자:변수:문자)를 (입력:scanf)하면 그(결과:변수:실수)를 출력하는 기계.
//2. 연산자는 사칙연산만 가능하다(+,-,*,/)
//3. 연산을 하기위해서 최소 2개의 변수가 필요하므로 2개만 사용한다.
//4. 계산을 종료할때까지 (반복)해서 결과를 입력하고, 확인할수있다.
//데이터: 숫자A, 숫자B, 연산자, 결과
//알고리즘: 숫자와 연산자를 입력받고, 
//		    입력받은 연산자가 +면 두수를 더하여 결과에 넣는다.
//		    입력받은 연산자가 -면 두수를 빼고 결과에 넣는다.
//		    입력받은 연산자가 *면 두수를 곱하고 결과에 넣는다.
//		    입력받은 연산자가 /면 두수를 나누고 결과에 넣는다.
void CaculatorLoofMain()
{
	float fDataA, fDataB, fResult; //두값을 입력하는 실수형변수와 정답을 입력하는 변수를 만들었다. 초기화 되지않았으므로 모든 변수의 값은 알수없다.
	char cOp = 0; //연산자를 입력받기위해서 정수형변수를 선언하고 초기화지 않았다.

	//while (true) //참인 동안
	//while(cOp == 'x')// 0 == 'x' -> F
	//while (!(cOp == 'x'))// 0 == 'x' -> F //종료조건의 반대 결과를 반복문에 조건으로 만든다.
	while (cOp != 'x')
	{
		printf("ex) 1+1 exit)?x?>> "); //
		scanf("%f%c%f", &fDataA, &cOp, &fDataB); //
		//if (cOp == 'x') break; //인간은 다음과 같이 끝나는 조건을 생각하기 쉬우므로, 조건문으로 종료한다.
		switch (cOp)
		{
		case '+':
			fResult = fDataA + fDataB;
			break;
		case '-':
			fResult = fDataA - fDataB;
			break;
		case '*':
			fResult = fDataA * fDataB;
			break;
		case '/':
			fResult = fDataA / fDataB;
			break;
		default:
			printf("%c is not Support!\n", cOp);
			return; //리턴을 만나면 함수는 종료된다.
			break;
		}

		printf("%f%c%f=%f\n", fDataA, cOp, fDataB, fResult);
	}
}

//세균은 10마리를 배양하고 100마리 이상일때 시간은?
//세균은 1시간마다 2배씩 증가한다.
//데이터: 세균수,시간 -> 정수! 실수?
//알고리즘: 1시간마다, 세균수*2,  100마리 이상이될때까지
//1.데이터와 알고리즘을 분리한다.
//2.데이터는 변수 알고리즘은 연산,반복,조건 등이 조합된다.
//3.반복되는 경우는 먼저 반복하고 정답을 출력한다.
void BateriaMain()
{
	int nBater = 10;
	int nTime = 0;

	while (true)
	{
		nTime = nTime + 1; //1
		nBater = nBater * 2; //10 * 2 = 20
		printf("Batera/Time: %d/%d\n", nBater, nTime);
		if (nBater >= 100) break;
	}
	//nTime = 1; //1
	//nBater = nBater * 2; //10 * 2 = 20

	//nTime = 2; //2
	//nBater = nBater * 2; //20 * 2 = 40

	//nTime = 3; //3
	//nBater = nBater * 2; //40 * 2 = 80

	//nTime = 4; //4
	//nBater = nBater * 2; //80 * 2 = 160

	printf("Batera/Time: %d/%d\n",nBater,nTime);
}

//(세균:변수) 10마리를 배양하여 (10시간후:조건)의 세균수를 구하여라.
//이때, 세균이 (1시간 마다 4배)찍 증가한다 
//세균수:10 //시간:0  //세균수*=4
void BateriaCountMain()
{
	int nBater = 10;
	int nTime = 0;

	////일반적으로 로직을 생각하기엔 while문이 적절하다.
	//while (true)
	//{
	//	nTime = nTime + 1; //1
	//	nBater = nBater * 4; //10 * 4 = 40
	//	printf("Batera/Time: %d/%d\n", nBater, nTime);
	//	if (nTime == 10) break;
	//}
	
	////프로그래밍에 익숙하지않다면 이렇게 사용하기 쉽지않다.
	//for (nTime = 0; nTime <= 10; nTime++)
	//{
	//	nBater = nBater * 4; //10 * 4 = 40
	//	printf("Batera/Time: %d/%d\n", nBater, nTime);
	//}
}

void main()
{
	//Ctrl+F5
	printf("Hello World!!!\n");//출력함수 //\n:줄바꿈문자
	//SumMain();//세미콜론: 문장의 끝에 들어가는 기호
	//CircleAreaMain();
	//ValSizeMain();
	//ASCIICodeTestMain();
	//LightSpeedMain();
	//IncDecTestMain();
	//GradeTestMain();
	//CaculatorMain();
	//CaculatorLoofMain();
	//BateriaMain();
	BateriaCountMain();
}