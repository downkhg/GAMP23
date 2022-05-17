#include <stdio.h>

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int FindMinIdx(int nStartIdx, int arrData[], int nSize)
{
	int nMinIdx = nStartIdx;
	for (int i = nStartIdx; i < nSize; i++)
	{
		if (arrData[nMinIdx] > arrData[i])
			nMinIdx = i;
	}
	return nMinIdx;
}

void InsertSortMain()
{
	int arrData[] = { 8,1,7,4,2,3,9,5,6 };
	int nSize = sizeof(arrData) / sizeof(int);

	int nSelIdx = 0;
	
	while (nSelIdx < nSize-1)
	{
		int nStartIdx = nSelIdx;//선택된 값부터 찾기를 해야 최소값이 1개라 최대값이 되는 경우를 막을수있다.
		int nMinIdx = FindMinIdx(nStartIdx, arrData, nSize);
		/*int nMinIdx = nSelIdx;

		for (int i = nStartIdx; i < nSize; i++)
		{
			if (arrData[nMinIdx] > arrData[i])
				nMinIdx = i;
		}*/
		if (nSelIdx != nMinIdx)
		{
			Swap(arrData[nSelIdx], arrData[nMinIdx]);
		}
		else
			printf("Select == Min\n");

		for (int i = 0; i < nSize; i++)
		{
			if (i == nSelIdx || i == nMinIdx)
				printf("[%d],", arrData[i]);
			else
				printf(" %d ,", arrData[i]);
		}
		printf("\n");
		nSelIdx++;
	}
	for (int i = 0; i < nSize; i++)
		printf("%d,",arrData[i]);
	printf("\n");
}

void main()
{
	InsertSortMain();
}