/*##################################
이진트리(C언어 수업용)
파일명: BinaryTree.cpp
작성자 : 김홍규(downkhg@gmail.com)
마지막수정날짜 : 2022.03.04
버전 : 1.01
###################################*/
#include <stdio.h>
#include <list>
#include <vector>
using namespace std;
namespace LinkedList
{
	//필요하다면 멤버를 추가해야한다.
	struct SNode {
		char cData;
		list<SNode*> listAdj;
		bool bVisit;
	};

	SNode* CreateNode(char data)
	{
		SNode* pTemp = new SNode;
		pTemp->cData = data;
		pTemp->bVisit = false;
		return pTemp;
	};
	bool MakeAdjacency(SNode* pParent, SNode* pChilde)
	{
		if (pParent == NULL)//0x01 == N -> F
			return false;
		pParent->listAdj.push_back(pChilde);
		return true;
	};
	//이것은 DFS도 BFS도 아니다.
	void Traverse(SNode* pNode)
	{
		if (pNode == NULL) return; //0x05 == NULL -> F
		if (pNode->bVisit == false)
		{
			printf("%c", pNode->cData); //전위
			list<SNode*>::iterator it;
			for (it = pNode->listAdj.begin(); it != pNode->listAdj.end(); it++)
			{
				SNode* pAdj = *it;
				Traverse(pAdj);
			}
			pNode->bVisit = true;
		}
	}

	void Print(SNode* pSeed)
	{
		Traverse(pSeed);
	}

	enum  E_NODE { A, B, C, D, E, F, G, H, MAX };
	void main()
	{
		SNode* pNodes[MAX];
		char cNodeData = 'A';
		for (int i = 0; i < MAX; i++)
		{
			pNodes[i] = CreateNode(cNodeData);
			cNodeData++;
		}

		MakeAdjacency(pNodes[A], pNodes[B]);
		MakeAdjacency(pNodes[B], pNodes[D]);
		MakeAdjacency(pNodes[B], pNodes[F]);
		MakeAdjacency(pNodes[C], pNodes[B]);
		MakeAdjacency(pNodes[D], pNodes[H]);
		MakeAdjacency(pNodes[E], pNodes[C]);
		MakeAdjacency(pNodes[E], pNodes[H]);
		MakeAdjacency(pNodes[F], pNodes[D]);
		MakeAdjacency(pNodes[F], pNodes[G]);
		MakeAdjacency(pNodes[F], pNodes[H]);
		MakeAdjacency(pNodes[G], pNodes[E]);
		MakeAdjacency(pNodes[G], pNodes[F]);
		MakeAdjacency(pNodes[G], pNodes[H]);


		Print(pNodes[0]);
	}
}

namespace Array
{
	//필요하다면 멤버를 추가해야한다.
	struct SNode {
		char cData;
		vector<SNode*> listAdj;
		bool bVisit;
		SNode(int adjSize)
		{
			listAdj.resize(adjSize);
		}
	};

	SNode* CreateNode(char data, int adjSize = 0)
	{
		SNode* pTemp = new SNode(adjSize);
		pTemp->cData = data;
		pTemp->bVisit = false;
		return pTemp;
	};
	bool MakeAdjacency(SNode* pParent, SNode* pChilde)
	{
		if (pParent == NULL)//0x01 == N -> F
			return false;
		pParent->listAdj.push_back(pChilde);
		return true;
	};
	//이것은 DFS도 BFS도 아니다.
	void Traverse(SNode* pNode)
	{
		if (pNode == NULL) return; //0x05 == NULL -> F
		if (pNode->bVisit == false)
		{
			printf("%c", pNode->cData); //전위
			for (int i = 0; i < pNode->listAdj.size(); i++)
			{
				Traverse(pNode->listAdj[i]);
			}
			pNode->bVisit = true;
		}
	}

	void Print(SNode* pSeed)
	{
		Traverse(pSeed);
	}

	enum  E_NODE { A, B, C, D, E, F, G, H, MAX };
	void main()
	{
		SNode* pNodes[MAX];
		char cNodeData = 'A';
		for (int i = 0; i < MAX; i++)
		{
			pNodes[i] = CreateNode(cNodeData);
			cNodeData++;
		}

		MakeAdjacency(pNodes[A], pNodes[B]);
		MakeAdjacency(pNodes[B], pNodes[D]);
		MakeAdjacency(pNodes[B], pNodes[F]);
		MakeAdjacency(pNodes[C], pNodes[B]);
		MakeAdjacency(pNodes[D], pNodes[H]);
		MakeAdjacency(pNodes[E], pNodes[C]);
		MakeAdjacency(pNodes[E], pNodes[H]);
		MakeAdjacency(pNodes[F], pNodes[D]);
		MakeAdjacency(pNodes[F], pNodes[G]);
		MakeAdjacency(pNodes[F], pNodes[H]);
		MakeAdjacency(pNodes[G], pNodes[E]);
		MakeAdjacency(pNodes[G], pNodes[F]);
		MakeAdjacency(pNodes[G], pNodes[H]);


		Print(pNodes[0]);
	}
}

void main()
{
	//LinkedList::main();
	Array::main(); //연결리스트가 다루기 어렵다면 벡터를 이용할것.
}