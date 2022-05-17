#include <stdio.h>
#include <stdlib.h>
//�����Ҵ�: ������ ������ ���� ������ ��� �������� �����Ǵ� ��. -> �̸���밡��. �����Ϸ��� �����ֱ⸦ �����층�����ϴ�.
//�����Ҵ�: ���α׷��� �����߿� �޸𸮰� �Ҵ�Ǵ� ��. -> ���������� �̸����Ұ�. �ּҰ��� �̿��Ͽ� �����ؾ��ϹǷ�, �����Ͱ� �ʿ��ϴ�. ���ʿ��Ҷ� ���α׷��Ӱ� ���� ����.
//���α׷� �����߿� �޸𸮸� �Ҵ��Ҽ��ִ� -> ����Ƽ���� ���ӿ�����Ʈ�� ���α׷� �����߿� ���� �����ϴ�.
void MemallocTestMain()
{
	int nSize;
	int* pArray = NULL;

	printf("nSize:");
	scanf_s("%d",&nSize);//3

	pArray = (int*)malloc(nSize * sizeof(int));

	if (pArray != NULL)
	{
		for (int i = 0; i < nSize; i++)
		{
			pArray[i] = i * 10;
			printf("[%d]%d,",i,pArray[i]);
		}
	}
	printf("\n");
	//�����Ҵ�� ���α׷��Ӱ� �޸𸮴� ������ �ؾ��Ѵ�.
	free(pArray);
}

void RemallocTestMain()
{
	int nSize;
	int* pArray = NULL;

	printf("nSize:");
	scanf_s("%d", &nSize);//3
	
	pArray = (int*)malloc(nSize * sizeof(int));
	printf("pArray:%d\n",pArray);
	if (pArray != NULL)
	{
		for (int i = 0; i < nSize; i++)
		{
			pArray[i] = i * 10;
			printf("[%d]%d,", i, pArray[i]);
		}
	}
	printf("\n");

	int nResize;
	printf("nResize:");
	scanf_s("%d", &nResize);//3
	nSize += nResize;
	pArray = (int*)realloc(pArray,nSize * sizeof(int));
	printf("pArray:%d\n", pArray);
	if (pArray != NULL)
	{
		for (int i = 0; i < nSize; i++)
		{
			printf("[%d]%d,", i, pArray[i]);
		}
	}
	printf("\n");

	//�����Ҵ�� ���α׷��Ӱ� �޸𸮴� ������ �ؾ��Ѵ�.
	free(pArray);
}

void NewDeleteTestMain()
{
	int nSize = 3;
	int* pArray = new int[nSize];
	int* pIntData = new int;

	printf("pArray:%d\n", pArray);
	if (pArray != NULL)
	{
		for (int i = 0; i < nSize; i++)
		{
			printf("[%d]%d,", i, pArray[i]);
		}
	}
	printf("\n");

	delete[] pArray;
	delete pIntData;
}

void main()
{
	//MemallocTestMain();
	RemallocTestMain();
}