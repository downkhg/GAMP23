/*##################################
���Ͽ��Ḯ��Ʈ(������)
���ϸ�: LinkedList_empty.cpp
�ۼ���: ��ȫ�� (downkhg@gmail.com)
������������¥: 2019.04.12
����: 1.10
###################################*/

#include <stdio.h>
#include <stdlib.h> //�޸� �����Ҵ� ���
#include <crtdbg.h> //�޸� ���� Ž�� ���
//#include  "linkedlistClass.h"

struct SNode {
	int nData;
	SNode* pNext;
};

SNode* CreateNode(SNode* pNode, int data); //��带 �����Ͽ� �����Ѵ�.
SNode* FindNodeData(SNode* pStart, int data); //�ش� �����͸� ���� ��带 ã�´�.
SNode* InsertNodeData(SNode* pStart, int data, int insert); //�ش� �����͸� ���� ��� �ڿ� ��带 �߰��Ѵ�.
void DeleteNodeData(SNode* pStart, int del); //�ش絥���͸� ���� ��带 �����Ѵ�.
void PrintLinkedList(SNode* pStart); //��带 ��ȸ�ϸ� ���������� ����Ѵ�.
void DeleteLinkedList(SNode* *pStart); //��带 ��ȸ�ϸ� ��絥���͸� �����Ѵ�.
void ReverseLinkedList(SNode* pStart); //

									   //���Ḯ��Ʈ �������� �Է¹ޱ�.(�����Ҵ� �����)
void InputAdd();

//�����۵� �׽�Ʈ�� ���ؼ�, ������ ���� �⺻���� ������ ������ Ȯ���Ѵ�.
//�� �ҽ��� ��� ���װ� �����Ѵ�.
//�� �ڵ尡 �����۵� �� �� �߰��غ���!
//main()�Լ� �� �ڵ�� �߰��� ���������� ������ ��������!
void main()
{
	//_CrtSetBreakAlloc(85); //�޸� ������ ��ȣ�� ������ �Ҵ��ϴ� ��ġ�� �극��ũ ����Ʈ�� �Ǵ�.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //�޸� ���� �˻� 

	SNode* pBegin = NULL;
	SNode* pEnd = NULL;

	//��� �߰� �׽�Ʈ
	pEnd = CreateNode(pEnd, 10);
	pBegin = pEnd; //������ ��带 �˾ƾ� �˻��� �����ϹǷ� �����صд�.

	pEnd = CreateNode(pEnd, 20);
	pEnd = CreateNode(pEnd, 30);
	pEnd = CreateNode(pEnd, 40);
	pEnd = CreateNode(pEnd, 50);

	PrintLinkedList(pBegin);

	SNode* pFind = FindNodeData(pBegin, 40);
	if (pFind != NULL)//0x04 != NULL -> T
		printf("Find:%d\n", pFind->nData);//Find:40

	SNode* pInsert = InsertNodeData(pBegin, 30, 60);//��� ����//
	//pInsert = InsertNodeData(pBegin, 70, 80);//��� ����//

	if (pInsert != NULL)//0x06 != NULL -> T
		printf("Insert:%d\n", pInsert->nData);//Insert:60

	PrintLinkedList(pBegin);

	DeleteNodeData(pBegin, 60);//��� ����
	//DeleteNodeData(pBegin, 10);//��� ����
	//DeleteNodeData(pBegin, 50);//��� ����
	//DeleteNodeData(pBegin, -10);//��� ����

	PrintLinkedList(pBegin);

	DeleteLinkedList(&pBegin); //�������� - �� �Լ��� ȣ������������ �޸𸮰� ������.

	PrintLinkedList(pBegin);
}

//���⼭ ���� ����� �����Ѵ�.
//�����ڵ�� �մ�������, �߰��� �Ͽ� �� ���α׷� ���� �۵��ϵ����Ұ�.
SNode* CreateNode(SNode* pNode, int data)
{
	SNode* pTemp = NULL;

	pTemp = new SNode();
	pTemp->nData = data;
	pTemp->pNext = NULL;
	if(pNode != NULL)//pNode != 0x04 -> T
		pNode->pNext = pTemp;
	//pTemp->pNext = pNode;

	return  pTemp;
}

SNode* FindNodeData(SNode* pStart, int data)//
{
	SNode* pNode = pStart;//
	while (true)
	{
		if (pNode->nData != data) //30 != 30 -> F
			pNode = pNode->pNext;//
		else//if (pNode->nData == data) //40 != 40
			break;
		//if (pNode->nData != data) //30 != 40
		//	pNode = pNode->pNext;
	}
	return pNode;
}

SNode* InsertNodeData(SNode* pStart, int data, int insert)//
{
	SNode* pNode = pStart;//
	SNode* pInsert = NULL;//

	pNode = FindNodeData(pStart, data);//

	if (pNode)
	{
		pInsert = new SNode();
		pInsert->pNext = pNode->pNext;
		pNode->pNext = pInsert;
		pInsert->nData = insert;
	}

	return pInsert;
}

void DeleteNodeData(SNode* pStart, int del)
{
	SNode* pPrev = NULL;
	SNode* pNode = pStart;

	////���ڵ�� pNode�� null�̶�� ���α׷��� �״´�.
	//while (pNode->nData != del)//60 != 60 -> F
	//{
	//	pPrev = pNode;
	//	pNode = pNode->pNext;
	//	//pPrev = pStart;
	//}

	while (pNode)
	{
		if (pNode->nData != del)
		{
			pPrev = pNode;
			pNode = pNode->pNext;
		}
		else break;
	}
	
	////���� ���� ã�´��ص� ��������� �������� �����Ҽ� ����.
	//pNode = FindNodeData(pStart, del);
	if (pPrev != NULL)
	{
		pPrev->pNext = pNode->pNext;
		delete pNode;
	}
}

void PrintLinkedList(SNode* pStart)
{
	SNode* pNode = pStart;
	printf("data:");
	while (pNode)
	{
		printf("%d", pNode->nData);
		pNode = pNode->pNext;

		if (pNode != NULL)
			printf(",");
	}
	printf("\n");
}

void DeleteLinkedList(SNode* *pStart)
{
	SNode* pNode = *pStart;
	SNode* pDel = NULL;

	while (pNode != NULL)
	{
		pDel = pNode;
		pNode = pNode->pNext;
		delete pDel;//
	}

	*pStart = NULL;
}

void InputAdd()
{
	SNode* pStart = NULL;
	SNode* pNode = NULL;
	int nData = 0;

	//�����Ҵ��� �ϸ� ���α׷��� ����ڿ� ���ؼ� ���Ǵ� �޸𸮰� �����ȴ�.
	//���Ը��ؼ�, �����ϴܰ迡�� 100���� ����� ���ٸ�, 
	//��������ʴ��� 100���� �޸𸮸� ����Ҽ��ۿ�����.
	//�׸���, 100�� �̻��� �޸𸮵� ����Ҽ�����.
	//�׷���, �����Ҵ��� �ϸ� ����ڰ� �߰��� �޸𸮸�ŭ�� �޸𸮰� ���ǰ� 
	//�޸𸮿뷮�� ����ϴ� �� �߰��� �ȴ�.
	while (nData != -1)
	{
		scanf_s("%d", &nData);
		pNode = CreateNode(pNode, nData);

		if (pNode == NULL)
		{
			printf("�� �̻� ����Ҽ� �ִ� �޸𸮰� �����ϴ�!");
		}

		if (pStart == NULL)
			pStart = pNode;

		PrintLinkedList(pStart);
	}

	DeleteLinkedList(&pStart); //�������� - �� �Լ��� ȣ������������ �޸𸮰� ������.
}