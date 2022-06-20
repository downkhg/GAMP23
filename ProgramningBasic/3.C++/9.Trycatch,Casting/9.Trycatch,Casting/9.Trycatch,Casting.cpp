#include <iostream>
using namespace std;
//������������ ������� �Է¹޾� 
//�ѻ���� �� ������ �������ִ���
//����ϴ� ���α׷�.
//������: ����������, �����, �ѻ���� ����������
//�˰�����: ����������/����� = �ѻ���� ����������
void PizzaSiliceMain()
{
	int nPizzaSlice;
	int nPersons;
	int nSlicePerPerson;

	cout << "����������:";
	cin >> nPizzaSlice;
	cout << "�����:";
	cin >> nPersons;

	try
	{
		if (nPizzaSlice <= 0)
			throw "���ڼ��� �ʹ� �����ϴ�!";
		else if (nPersons <= 0)
			throw "����� �����ϴ�!";

		nSlicePerPerson = nPizzaSlice / nPersons;

		cout << "��������/����� = " << nSlicePerPerson << endl;
	}
	//���ο�� ���Ŀ� ���� ��ġ�� �ȴ�.
	catch (const char* e)
	{
		cout << e;
	}
}

//try catch���� �������� �۵��� �Ұ��ΰ�?
class Parent {
public:
	virtual void Display() { cout << "Parent" << endl; }
};
class ChildA : public Parent
{
public:
	void Display() { cout << "ChildA" << endl; };
};
class ChildB : public Parent
{
public:
	void Display() { cout << "ChildB" << endl; };
};
//����ó�������� �������� �����Ѵ�. 
void PolymorphismExceptionMain()
{
	Parent* pParent = new ChildB();
	ChildA cChildA;
	ChildB cChildB;

	try {
		//throw  pParent;
		throw *pParent;
	}
	//catch������ Ÿ�Կ� �°� ȣ��ȴ�.
	catch (Parent& e)
	{
		cout << "Ref:";
		e.Display();
	}
	catch (Parent* e)
	{
		cout << "Statck:";
		e->Display();
	}

	delete pParent;
}

//�����Ҵ�� ������ ĳ�����ϴµ� �����.
//��ȯ�� �Ұ����� ������ ����ϸ� �����Ͽ�������.
void StaticCastMain()
{
	int nDataCost = (int)3.14f;
	int nDataStaticCast = static_cast<int>(3.14f);

	int* pIntCast = static_cast<int*>(&nDataCost);
	//float* pfloatCast = static_cast<int*>(&nDataCost);//�����Ͽ���

	cout << "DataCost:" << nDataCost << endl;
	cout << "DataStaticCast:" << nDataStaticCast << endl;
}
//�����Ҵ纯��/��ü
void DynamicCastMain()
{
	int* pIntData = new int();
	float* pfloatDataCast = (float*)pIntData;
	//�Ϲݸ���� �������� ����Ҽ�����.
	//float* pfloatDataDynamicCast = dynamic_cast<float*>(pIntData);
	delete pIntData;

	Parent* pParent = new Parent();
	ChildA* pChildA = new ChildA();
	ChildA* pParentToChildCast = (ChildA*)pParent;
	//�θ�->�ڽ�: ����O Downcasting -> NULL�� ��ȯ�Ѵ�.
	ChildA* pParentToChildDynamicCast = dynamic_cast<ChildA*>(pParent);
	//�ڽ�->�θ�: ����X Upcasting -> �����͸� ��ȯ�Ѵ�.
	Parent* pChildToParentDynamicCast = dynamic_cast<Parent*>(pChildA);
	//������ ���� ������ �ִ� ����� ��ȯ�ϰ�� ĳ�����̵����ʰ� null�� ��ȯ�Ѵ�.
	cout << "pParentToChildDynamicCast:" << (int)pParentToChildDynamicCast << endl;
	cout << "pChildToParentDynamicCast:" << (int)pChildToParentDynamicCast << endl;
	delete pParent;
	delete pChildA;
}

//���������迡�� �θ� � Ÿ������ �˾Ƴ����ִ� �Լ�.
//������������ ��ü�� ����� �Ҵ�Ǿ��ִ��� �˱��ƴ�.
//�׷��Ƿ�, ������ ���� �Ҵ�Ȱ�ü�� �Ǵ��Ҽ��ִٸ� ���� ������ �����Ҽ��ִ�.
void TypeIdMain()
{
	Parent* pParentA = new ChildA();
	Parent* pParentB = new ChildB();

	cout << "ParentA:" << typeid(pParentA).name() << endl;
	cout << "ParentB:" << typeid(pParentB).name() << endl;

	cout << "ParentA*:" << typeid(*pParentA).name() << endl;
	cout << "ParentB*:" << typeid(*pParentB).name() << endl;

	delete(pParentA);
	delete(pParentB);
}

void main()
{
	//PizzaSiliceMain();
	//PolymorphismExceptionMain();
	//DynamicCastMain();
	TypeIdMain();
}