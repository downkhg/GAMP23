#include <stdio.h>
//������: �ּҰ��� �����ϴ� ����
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
//��������ȣ��
//�Ű��������� �ܺ��� �������� ���� ���� �Ǿ����Ƿ�,
//�Ű����� a��  b�� �����Ѵٰ� �ܺ� ������ ���� ��������� �ʴ´�.
void SwapVar(int a, int b)
{
	printf("SwapVar(%d,%d)\n", &a, &b);
	int temp = a;
	a = b;
	b = temp;
}
//�����Ϳ����� ȣ��: �Ű������� ���� ���޹޾� �ܺο� ������ ���ٰ����ϴ�.
// ex) �Ű������� ���� ������/�ΰ��̻��� �����͸� �����Ҷ�, 
//�Ű������� �ּҰ����� ������ �Լ� �ܺ� ������ ������ �����ϴ�.
//�׷��Ƿ� ������ ���� ���氡���ϴ�.
void SwapPtr(int* pA, int* pB)
{
	printf("SwapPtr(%d,%d)\n", pA, pB);
	int temp = *pA;
	*pA = *pB;
	*pB = temp;
}
//����������ȣ��: �Ű������� ��� �����ڷ� ������ ������ �������� ���氡���ϴ�.
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