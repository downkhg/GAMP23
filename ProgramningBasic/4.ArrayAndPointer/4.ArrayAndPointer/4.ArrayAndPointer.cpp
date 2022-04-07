#include <stdio.h>
//포인터: 주소값을 저장하는 변수
void VarAndPointerMain()
{
	int nData = 10;
	float fData = 3.14f;
	int* pIntData = &nData;
	float* pFloatData = &fData;

	printf("nData[%d]:%d\n",&nData,nData);
	printf("pIntData[%d]:%d\n", *pIntData, pIntData);

	printf("fData[%d]:%f\n", &fData, fData);
	printf("pFloatData[%f]:%d\n", *pFloatData, pFloatData);
}
//값에의한호출
//매개변수에는 외부의 데이터의 값이 복사 되었으므로,
//매개변수 a와  b를 변경한다고 외부 변수의 값이 변경되지는 않는다.
void SwapVar(int a, int b)
{
	printf("SwapVar(%d,%d)\n", &a, &b);
	int temp = a;
	a = b;
	b = temp;
}
//포인터에의한 호출: 매개변수의 값을 전달받아 외부에 변수에 접근가능하다.
// ex) 매개변수로 받은 데이터/두개이상의 데이터를 저장할때, 
//매개변수를 주소값으로 받으면 함수 외부 변수에 접근이 가능하다.
//그러므로 원본을 서로 변경가능하다.
void SwapPtr(int* pA, int* pB)
{
	printf("SwapPtr(%d,%d)\n", pA, pB);
	int temp = *pA;
	*pA = *pB;
	*pB = temp;
}
//참조에의한호출: 매개변수를 모두 참조자로 받으면 원본의 변수값을 변경가능하다.
void SwapRef(int& a, int& b)
{
	printf("SwapRef(%d,%d)\n", a, b);
	int temp = a;
	a = b;
	b = temp;
}

void FunctionAndPointerMain()
{
	int nDataA = 10;
	int nDataB = 20;
	printf("1. nDataA[%d]:%d\n",&nDataA, nDataA);
	printf("1. nDataB[%d]:%d\n", &nDataB, nDataB);
	SwapVar(nDataA, nDataB);
	FunctionAndPointerMain();
	printf("2. nDataA[%d]:%d\n", &nDataA, nDataA);
	printf("2. nDataB[%d]:%d\n", &nDataB, nDataB);
	SwapPtr(&nDataA, &nDataB);
	printf("3. nDataA[%d]:%d\n", &nDataA, nDataA);
	printf("3. nDataB[%d]:%d\n", &nDataB, nDataB);
	SwapRef(nDataA, nDataB);
	printf("4. nDataA[%d]:%d\n", &nDataA, nDataA);
	printf("4. nDataB[%d]:%d\n", &nDataB, nDataB);
}

void main()
{
	VarAndPointerMain();
	FunctionAndPointerMain();
}