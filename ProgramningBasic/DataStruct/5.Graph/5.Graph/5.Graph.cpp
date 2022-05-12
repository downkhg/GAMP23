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
#include <queue>
#include <stack>
using namespace std;
namespace LinkedList
{
	//필요하다면 멤버를 추가해야한다.
	struct SNode {
		char cData;
		list<SNode*> listAdj;
		bool bVisit;
		list<SNode*>::iterator itAdj;
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

	void TraverseDFS(SNode* pNode, bool bPrint = true)
	{
		if (pNode->bVisit == false)
		{
			if (bPrint) printf("%c,", pNode->cData);//A//B
			if (pNode->bVisit == false)
			{
				pNode->bVisit = true;

				if (!pNode->listAdj.empty())
				{
					list<SNode*>::iterator  it;
					for (it = pNode->listAdj.begin(); it != pNode->listAdj.end(); it++)
					{
						TraverseDFS(*it);//F
					}
				}
			}
		}
	}

	SNode* VisitStackDFS(SNode* pNode, stack<SNode*>& visit)
	{
		SNode* pNext = NULL;
		if (pNode)
		{
			if (pNode->bVisit == false)
			{
				//cout << "Visit:" << pNode->cData << endl;
				printf("%c,", pNode->cData);
				visit.push(pNode);
				pNode->bVisit = true;
			}
			else
			{
				//cout << "Revisit:" << pNode->cData << endl;
			}
			//list<SNode*>::iterator it = pNode->itChild;
			if (pNode->listAdj.size() > 0)
			{
				if (pNode->itAdj != pNode->listAdj.end())
				{
					pNext = *pNode->itAdj;
					while (pNext != NULL && pNext->bVisit == true)
					{
						if (pNode->itAdj != pNode->listAdj.end())
						{
							//cout << "Revisit!" << (*pNode->itChild)->cData << endl;
							pNext = *pNode->itAdj;
							pNode->itAdj++;
						}
						else
						{
							//cout << "Visit Complete!" << pNode->cData << endl;
							pNext = NULL;
						}
					}
				}
			}
		}
		else
		{
			//cout << "Visit Complete! " << visit.top()->cData << endl;
			visit.pop();
			if (!visit.empty())
				pNext = visit.top();
		}
		return pNext;
	}

	void TraverDFSStack(SNode* pNode)
	{
		printf("DFS(Stack):");
		stack<SNode*> visit;
		do
		{
			pNode = VisitStackDFS(pNode, visit);
		} while (!visit.empty());
		printf("\n");
	}

	bool VisitBFS(SNode* pNode, queue<SNode*>& visit)
	{
		if (pNode)
		{
			if (pNode->bVisit == false)
			{
				printf("%c.", pNode->cData);
				//cout << "Visit:" << pNode->cData << endl;
				pNode->bVisit = true;
				visit.push(pNode);
				return true;
			}
			else
			{
				//cout << "Revisit! " << visit.front()->cData << endl;
			}
		}
		return false;
	}

	void TraverBFS(SNode* pNode)
	{
		printf("BFS:");
		queue<SNode*> visit;
		do
		{
			if (!visit.empty())//B
				pNode = visit.front();//B
			VisitBFS(pNode, visit);//B

			list<SNode*>::iterator it = pNode->listAdj.begin();
			for (; it != pNode->listAdj.end(); it++)
			{
				SNode* pNode = *it;
				VisitBFS(pNode, visit);//D,F
			}
			visit.pop();//B

		} while (!visit.empty());
		printf("\n");
	}

	void TraverDFS(SNode* pNode, bool bPrint = true)
	{
		printf("DFS:");
		TraverseDFS(pNode, bPrint);
		printf("\n");
	}

	void TraverReset(SNode* pNodes[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			pNodes[i]->bVisit = false;
			pNodes[i]->itAdj = pNodes[i]->listAdj.begin();
		}
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

		TraverDFS(pNodes[A]);
		TraverReset(pNodes,MAX);
		TraverDFSStack(pNodes[A]);
		TraverReset(pNodes, MAX);
		TraverBFS(pNodes[A]);
		TraverReset(pNodes, MAX);
	}
}

namespace Array
{
	//필요하다면 멤버를 추가해야한다.
	struct SNode {
		char cData;
		vector<SNode*> listAdj;
		bool bVisit;
		int nLastAdjIdx;
		bool bAdjVitit;
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
		pTemp->bAdjVitit = false;
		pTemp->nLastAdjIdx = 0;
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

	bool VisitNode(SNode* pVisit, bool bPrint = false)
	{
		if (pVisit->bVisit == false)
		{
			if(bPrint) printf("%c,",pVisit->cData);
			pVisit->bVisit = true;
			return true;
		}
		return false;
	}

	void TraverseDFS(SNode* pNode, bool bPrint = true)
	{
		if (pNode->bVisit == false)
		{
			if (bPrint) printf("%c,", pNode->cData);
			pNode->bVisit = true;

			for (int i = 0; i < pNode->listAdj.size(); i++)
			{
				if (!pNode->listAdj.empty())
				{
					TraverseDFS(pNode->listAdj[i]);
				}
			}
		}	
	}

	void DFS(SNode* pNode, bool bPrint = true)
	{
		TraverseDFS(pNode, bPrint);
	}

	void BFS(SNode* pNode, bool bPrint = true)
	{
		queue<SNode*> queVists;
		VisitNode(pNode, bPrint);
		queVists.push(pNode);

		for (int i = 0; i < pNode->listAdj.size(); i++)
		{
			VisitNode(pNode->listAdj[i], bPrint);
			if(pNode->listAdj[i])
				queVists.push(pNode->listAdj[i]);
		}

		queVists.pop();
		pNode = queVists.front();

		VisitNode(pNode, bPrint);
		queVists.push(pNode);

		for (int i = 0; i < pNode->listAdj.size(); i++)
		{
			if (VisitNode(pNode->listAdj[i], bPrint))
				queVists.push(pNode);
		}

		queVists.pop();
		pNode = queVists.front();

		VisitNode(pNode, bPrint);
		queVists.push(pNode);

		for (int i = 0; i < pNode->listAdj.size(); i++)
		{
			if (VisitNode(pNode->listAdj[i], bPrint))
				queVists.push(pNode);
		}

		printf("");
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


		//Print(pNodes[0]);
		DFS(pNodes[0], true);
		//BFS(pNodes[0], true);
	}
}

void main()
{
	LinkedList::main();
	//Array::main(); //연결리스트가 다루기 어렵다면 벡터를 이용할것.
}