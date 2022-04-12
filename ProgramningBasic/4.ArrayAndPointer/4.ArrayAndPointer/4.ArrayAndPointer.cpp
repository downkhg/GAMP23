#include <stdio.h>
#include <string.h>
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
//����(������)������ ȣ��: �Ű������� ���� ���޹޾� �ܺο� ������ ���ٰ����ϴ�.
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
//�����ڿ�����ȣ��: �Ű������� ��� �����ڷ� ������ ������ �������� ���氡���ϴ�.
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
	SwapVar(nDataA, nDataB);//�Ű������� ���� ����Ǿ� ���� ��������ʴ´�.
	FunctionAndPointerMain();
	printf("2. nDataA[%d]:%d\n", &nDataA, nDataA);
	printf("2. nDataB[%d]:%d\n", &nDataB, nDataB);
	SwapPtr(&nDataA, &nDataB);//�Ű������� �ּҸ� ���������Ƿ�. �����Ͱ���Ű�� ������ ���� ���� �� �� �ִ�.
	printf("3. nDataA[%d]:%d\n", &nDataA, nDataA);
	printf("3. nDataB[%d]:%d\n", &nDataB, nDataB);
	SwapRef(nDataA, nDataB);//�Ű������� �����ڸ� �̿��ϸ�, ������ ���� ������ �� �ִ�.
	printf("4. nDataA[%d]:%d\n", &nDataA, nDataA);
	printf("4. nDataB[%d]:%d\n", &nDataB, nDataB);
}
//�迭�� �������� ������ �����ǰ� ��� �� �� �ִ�.
void ArrayAndPointerMain()
{
	const int nSize = 3;//�迭�� ũ��� ������ �Ұ����ϴ�. 
	int arrScore[nSize];//�׷��Ƿ� ũ�⸦ �����Ҷ� ����� �̿��ؾ��Ѵ�.
	for (int i = 0; i < 3; i++)
		arrScore[i] = 100 - i * 10;
	int arrSize = sizeof(arrScore) / sizeof(int);//12/4 = 3
	//arrScore = &arrScore[1]; //�迭�� �̸��� ������ �ƴϹǷ� �����ʹ� �ƴϴ�.
	printf("arrScore:%d/%d\n",&arrScore, arrScore);//�迭�� �̸��� �����ּҰ��� ������.
	for (int i = 0; i < 3; i++)
		printf("[%d/%d]%d,",&arrScore[i],i, arrScore[i]);
	printf("\n");
	//�����Ϳ���: �������� ���� �������� Ÿ���� ũ�⸸ŭ �����ϴ� ��. ex)char +1, double +8, float/int +4
	//�迭���̸��� �����ּҰ��� �����Ƿ�. 0�� ���ؾ� ���� ũ�Ⱑ ���´�. 
	for (int i = 0; i < 3; i++)
		printf("[%d/%d]%d,", arrScore+i, i, *(arrScore+i));
	printf("\n");
	int* pScore = arrScore;
	for (int i = 0; i < 3; i++)
	{
		printf("[%d/%d]%d,", pScore + i, i, *(pScore + i));
		pScore++;
	}
	printf("\n");
	int arrCopyScore[nSize];
	for (int i = 0; i < 3; i++)
		arrCopyScore[i] = arrScore[i];
	memcpy(arrCopyScore, arrScore, sizeof(arrCopyScore));
}
//4x3�� ũ���� 2�����迭�� 12ũ���� 1�����迭�� ���� �����, ����for���� �̿��Ͽ� �ʱ�ȭ�ϰ�,
//�迭�� �ּҰ�, �ε���, ������ ���� ����ϴ� ���α׷��� ������.
void Array2DTestMain()
{
	const int nSizeX = 4;
	const int nSizeY = 3;
	const int nSize = nSizeX * nSizeY;
	int arr2DArray[nSizeY][nSizeX];
	int arr2DFakeArray[nSize];
	printf("######## 2DArray #########\n");
	for (int y = 0; y < nSizeY; y++)//0,1,2
	{
		for (int x = 0; x < nSizeX; x++)//0,1,2,4
		{
			arr2DArray[y][x] = y * nSizeX + x;
			printf("%d[%d,%d]:%d,", &arr2DArray[y][x],y,x,arr2DArray[y][x]);//[0][0]:0 //[0][1]:1 //[0][2]:2 //[0][3]:3\n // //[1][0]:4 //[1][1]:5 //[1][2]:6 //[1][3]:7\n....
		}
		printf("\n");
	}
	printf("######## 2DFakeArray #########\n");
	for (int y = 0; y < nSizeY; y++)
	{
		for (int x = 0; x < nSizeX; x++)
		{
			int idx = y * nSizeX + x;
			arr2DFakeArray[idx] = idx;
			printf("%d[%d,%d]:%d,", &arr2DFakeArray[idx], y, x, arr2DFakeArray[idx]);
		}
		printf("\n");
	}
}

void PrintString(const char* msg, const char* str, bool isIdx)
{
	printf("%s",msg);
	int idx = 0;
	while (str[idx] != '\0')//t != 0 -> T 
	{
		if (isIdx == false) printf("%c", str[idx]);
		else  printf("[%d]%c,", idx, str[idx]);
		idx++;
	}
	printf("\n");
}

void StringTestMain()
{
	//"���ڿ�" ���ڿ����� �ִ´�. ������ ���ҿ��� 0(=='\0')���� �ʱ�ȭ�ȴ�.
	char strWord[24] = "gameprograming";//24 - 14= 10?
	strWord[0] = 't';
	strWord[1] = 'e';
	strWord[2] = 's';
	strWord[3] = 't';
	//strWord[4] = '\0';//���ڿ���: ���ڿ��� ������ �˸��� ����.(== 0)
	printf("for:");
	for (int i = 0; i < 24; i++)
		printf("%c",strWord[i]);
	printf("\n");
	printf("stirng:%s\n",strWord);
	PrintString("while:", strWord, false);
	printf("\n");
}

void FullNameMakerMain()
{
	char strLastName[8] = "k";
	char strFistName[8] = "hg";
	char strFullNameKr[16];
	char strFullNameEn[16];

	strcpy(strFullNameKr, strLastName);
	strcat(strFullNameKr, strFistName);
	PrintString("kr:", strFullNameKr,true);
	printf("kr[%d]:%s\n", strlen(strFullNameKr), strFullNameKr);

	sprintf(strFullNameEn, "%s%s", strFistName, strLastName);
	PrintString("en:", strFullNameEn, true);
	printf("en[%d]:%s\n",strlen(strFullNameEn),strFullNameEn);

	int nResult = strcmp(strLastName, strFistName);

	if (nResult)
		printf("%d: %s != %s\n", nResult, strFistName, strLastName);
	else
		printf("%d: %s == %s\n", nResult, strFistName, strLastName);

}
/*
* ���α׷���¿���
����:GAME
Q: _ _ _ _
A: G
Q: G _ _ _
......
A:GA_E
Q:M
A:GAME

1.��Ե� Ǯ���.
2.�Լ��� �̿��Ͽ� ����Ǯ��(�ݺ���������)
3.����ó�� ������
*/
void HangMainGameMain()
{

}

void main()
{
	//VarAndPointerMain();
	//FunctionAndPointerMain();
	//ArrayAndPointerMain();
	//Array2DTestMain();
	FullNameMakerMain();
	//StringTestMain();
}