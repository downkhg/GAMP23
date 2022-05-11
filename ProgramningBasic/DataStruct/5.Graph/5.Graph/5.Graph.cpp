/*##################################
����Ʈ��(C��� ������)
���ϸ�: BinaryTree.cpp
�ۼ��� : ��ȫ��(downkhg@gmail.com)
������������¥ : 2022.03.04
���� : 1.01
###################################*/
#include <stdio.h>
#include <list>
#include <vector>
using namespace std;
namespace LinkedList
{
	//�ʿ��ϴٸ� ����� �߰��ؾ��Ѵ�.
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
	//�̰��� DFS�� BFS�� �ƴϴ�.
	void Traverse(SNode* pNode)
	{
		if (pNode == NULL) return; //0x05 == NULL -> F
		if (pNode->bVisit == false)
		{
			printf("%c", pNode->cData); //����
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
	//�ʿ��ϴٸ� ����� �߰��ؾ��Ѵ�.
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
	//�̰��� DFS�� BFS�� �ƴϴ�.
	void Traverse(SNode* pNode)
	{
		if (pNode == NULL) return; //0x05 == NULL -> F
		if (pNode->bVisit == false)
		{
			printf("%c", pNode->cData); //����
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
	Array::main(); //���Ḯ��Ʈ�� �ٷ�� ��ƴٸ� ���͸� �̿��Ұ�.
}