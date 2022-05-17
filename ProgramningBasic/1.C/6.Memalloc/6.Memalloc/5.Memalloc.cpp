#include <stdio.h>
#include <stdlib.h>
//정적할당: 컴파일 이전에 변수 생성이 어떻게 관리될지 결정되는 것. -> 이름사용가능. 컴파일러가 생성주기를 스케쥴링가능하다.
//동적할당: 프로그램이 실행중에 메모리가 할당되는 것. -> 컴파일이후 이름사용불가. 주소값을 이용하여 접근해야하므로, 포인터가 필요하다. 불필요할때 프로그래머가 직접 삭제.
//프로그램 실행중에 메모리를 할당할수있다 -> 유니티에서 게임오브젝트를 프로그램 실행중에 생성 가능하다.
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
	//동적할당된 프로그래머가 메모리는 삭제를 해야한다.
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

	//동적할당된 프로그래머가 메모리는 삭제를 해야한다.
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