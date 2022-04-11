#include <stdio.h>
#include <string.h>
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
//참조(포인터)에의한 호출: 매개변수의 값을 전달받아 외부에 변수에 접근가능하다.
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
//참조자에의한호출: 매개변수를 모두 참조자로 받으면 원본의 변수값을 변경가능하다.
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
	SwapVar(nDataA, nDataB);//매개변수의 값이 변경되어 값이 변경되지않는다.
	FunctionAndPointerMain();
	printf("2. nDataA[%d]:%d\n", &nDataA, nDataA);
	printf("2. nDataB[%d]:%d\n", &nDataB, nDataB);
	SwapPtr(&nDataA, &nDataB);//매개변수에 주소를 전달했으므로. 포인터가르키는 변수의 값을 변경 할 수 있다.
	printf("3. nDataA[%d]:%d\n", &nDataA, nDataA);
	printf("3. nDataB[%d]:%d\n", &nDataB, nDataB);
	SwapRef(nDataA, nDataB);//매개변수를 참조자를 이용하면, 변수의 값을 변경할 수 있다.
	printf("4. nDataA[%d]:%d\n", &nDataA, nDataA);
	printf("4. nDataB[%d]:%d\n", &nDataB, nDataB);
}
//배열은 포인터의 원리로 구현되고 사용 할 수 있다.
void ArrayAndPointerMain()
{
	const int nSize = 3;//배열의 크기는 변경이 불가능하다. 
	int arrScore[nSize];//그러므로 크기를 지정할땐 상수를 이용해야한다.
	for (int i = 0; i < 3; i++)
		arrScore[i] = 100 - i * 10;
	int arrSize = sizeof(arrScore) / sizeof(int);//12/4 = 3
	//arrScore = &arrScore[1]; //배열의 이름은 변수가 아니므로 포인터는 아니다.
	printf("arrScore:%d/%d\n",&arrScore, arrScore);//배열의 이름은 시작주소값을 가진다.
	for (int i = 0; i < 3; i++)
		printf("[%d/%d]%d,",&arrScore[i],i, arrScore[i]);
	printf("\n");
	//포인터연산: 포인터의 값이 포인터의 타입의 크기만큼 증가하는 것. ex)char +1, double +8, float/int +4
	//배열의이름은 시작주소값을 가지므로. 0을 더해야 원래 크기가 나온다. 
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
//4x3의 크기의 2차원배열과 12크기의 1차원배열을 각각 만들어, 이중for문을 이용하여 초기화하고,
//배열의 주소값, 인덱스, 원소의 값을 출력하는 프로그램을 만들어라.
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

void StringTestMain()
{
	//"문자열" 문자열끝을 넣는다.
	char strWord[24] = "gameprograming";//24 - 14= 10?
	strWord[0] = 't';
	strWord[1] = 'e';
	strWord[2] = 's';
	strWord[3] = 't';
	//strWord[4] = '\0';//문자열끝: 문자열의 끝임을 알리는 문자.(== 0)
	printf("for:");
	for (int i = 0; i < 24; i++)
		printf("%c",strWord[i]);
	printf("\n");
	printf("stirng:%s\n",strWord);
	printf("while:");
	int idx = 0;
	while (strWord[idx] != '\0')//t != 0 -> T 
	{
		printf("%c",strWord[idx]);
		idx++;
	}
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
	printf("kr:%s\n",strFullNameKr);

	sprintf(strFullNameEn, "%s%s", strFistName, strLastName);
	printf("en:%s\n",strFullNameEn);

}

void main()
{
	//VarAndPointerMain();
	//FunctionAndPointerMain();
	//ArrayAndPointerMain();
	//Array2DTestMain();
	//FullNameMakerMain();
	StringTestMain();
}