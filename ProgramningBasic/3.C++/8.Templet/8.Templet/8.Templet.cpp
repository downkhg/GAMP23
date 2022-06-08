#include <iostream>

using namespace std;
//�Ϲ� Ŭ����
class CData
{
	int nData;
public:
	void SetData(int data) { nData = data; }
	int GetData() { return nData; }
};

//�����Ҵ� ���� Ŭ����
//���ø����� �����Ҷ� �ʿ��� ȣ���Լ����� ��δ� �����ε��ؾ��Ѵ�.
class CBox
{
	int* pData;
	void _initData(int data) { this->pData = new int(); *this->pData = data; }
public:
	CBox(int data = 0) { _initData(data); }
	~CBox() { delete pData; }
	CBox(const CBox& box) { _initData(*box.pData); }
	CBox& operator= (const CBox& box) //���Կ�����
	{
		_initData(*box.pData);
		return *this;
	}
	void SetData(int data) { *pData = data; }
	int GetData() { return *pData; }
};

//���ø����� ����Ÿ���� ���氡���� Ŭ����
template<typename Type>
class CBoxTemplete
{
	Type* pData;
	void _initData(Type data) { this->pData = new Type(); *this->pData = data; }
public:
	CBoxTemplete(Type data = Type()) { _initData(data); }
	~CBoxTemplete() { delete pData; }
	CBoxTemplete(const CBoxTemplete& box) { _initData(*box.pData); }
	CBoxTemplete& operator= (const CBoxTemplete& box) //���Կ�����
	{
		_initData(*box.pData);
		return *this;
	}
	void SetData(Type data) { *pData = data; }
	Type GetData() { return *pData; }
};

template<typename Type>
void Swap(Type& a, Type& b)
{
	Type temp = a;
	a = b;
	b = temp;
}
//�Ϲݺ����� ���ø��Լ��� ��ȯ�Լ� �׽�Ʈ
void CommonFunctionTestMain()
{
	int nDataA = 10;
	int nDataB = 20;
	float fDataA = 3.14f;
	float fDataB = 0.1f;

	printf("Origin(int):%d/%d\n", nDataA, nDataB);
	Swap(nDataA, nDataB);
	printf("Swap(int):%d/%d\n", nDataA, nDataB);
	printf("Origin(float):%f/%f\n", fDataA, fDataB);
	Swap(fDataA, fDataB);
	printf("Swap(float):%f/%f\n", fDataA, fDataB);
}
//�����Ҵ�� ������� Ŭ������ ���ø��Լ��� ��ȯ�Լ� �׽�Ʈ
void StackClassTestMain()
{
	CData cDataA;
	CData cDataB;
	cDataA.SetData(10);
	cDataB.SetData(20);

	Swap(cDataA, cDataB);
	printf("Swap(Class):%d/%d\n", cDataA.GetData(), cDataB.GetData());
}
//������� �����Ҵ��Ͽ� Ŭ������ ������ ���ø��Լ��� ��ȯ�Լ� �׽�Ʈ
void BoxingClassTestMain()
{
	CData cDataA;
	CData cDataB;
	cDataA.SetData(10);
	cDataB.SetData(20);

	Swap(cDataA, cDataB);
	printf("Swap(Class):%d/%d\n", cDataA.GetData(), cDataB.GetData());
}
//������� �����Ҵ��Ͽ� ���ø�Ŭ������ ������ ���ø��Լ��� ��ȯ�Լ� �׽�Ʈ
void BoxingClassTempletTestMain()
{
	CBoxTemplete<float> cBoxanitypeA(3.14f);
	CBoxTemplete<float> cBoxanitypeB(1.25f);

	//���ø��� �̿��ϸ� Ÿ���� �����Ҽ��ְ� ������ִ�.
	Swap(cBoxanitypeA, cBoxanitypeB);
	printf("Swap(Templet):%f/%f\n", cBoxanitypeA.GetData(), cBoxanitypeB.GetData());
}

//���ø�: ���������� ����� ���� ó���Ҽ��ֵ��� �Ϲ�ȭ �ϴ°�.
void FunctionTempletMain()
{
	int nDataA = 10;
	int nDataB = 20;
	float fDataA = 3.14f;
	float fDataB = 0.1f;
	CData cDataA;
	CData cDataB;
	cDataA.SetData(10);
	cDataB.SetData(20);
	CBox cBoxDataA;
	CBox cBoxDataB;
	cBoxDataA.SetData(10);
	cBoxDataB.SetData(20);

	CBoxTemplete<float> cBoxanitypeA(3.14f);
	CBoxTemplete<float> cBoxanitypeB(1.25f);

	printf("Origin(int):%d/%d\n", nDataA, nDataB);
	Swap(nDataA, nDataB);
	printf("Swap(int):%d/%d\n", nDataA, nDataB);
	printf("Origin(float):%f/%f\n", fDataA, fDataB);
	Swap(fDataA, fDataB);
	printf("Swap(float):%f/%f\n", fDataA, fDataB);
	Swap(cDataA, cDataB);
	printf("Swap(Class):%d/%d\n", cDataA.GetData(), cDataB.GetData());
	//������ ���� �����ڳ� �⺻ȣ�� �Լ��� �����ε��ؾ��ϴ� ��찡 �ʿ��ϴ�.
	Swap(cBoxDataA, cBoxDataB);
	printf("Swap(Boxsing):%d/%d\n", cBoxDataA.GetData(), cBoxDataB.GetData());
	//���ø��� �̿��ϸ� Ÿ���� �����Ҽ��ְ� ������ִ�.
	Swap(cBoxanitypeA, cBoxanitypeB);
	printf("Swap(Templet):%f/%f\n", cBoxanitypeA.GetData(), cBoxanitypeB.GetData());
}

template<typename Type>
class Box
{
	Type data;
public:
	void SetData(Type data) { this->data = data; }
	Type GetData() { return data; }
	void Display()
	{
		cout << typeid(*this).name() << "(" << typeid(data).name() << "):" << data << endl;
	}
};

void TempletStaticBoxTestMain()
{
	//Ŭ���� ������ ������ Ÿ���� �ܺο��� �����Ҽ��ֵ��� ����°�.
	Box<int> box;
	box.SetData(10);
	box.Display();

	Box<float> fBox;
	fBox.SetData(3.14f);
	fBox.Display();
}

//���÷��� Ÿ���� ���� �ٸ�Ÿ���� ������ �����Ҽ��ִ�.
template <typename TypeKey, typename TypeData>
class MapData
{
	TypeKey key;
	TypeData data;
public:
	MapData(TypeKey key, TypeData data)
	{
		this->key = key;
		this->data = data;
	}
	TypeData operator[](TypeKey) { return data; }
};

void TemplatTyepKeyDataTestMain()
{
	//ù��° Ÿ�԰� �ι�°Ÿ���� �ٸ��� �־� ������.
	MapData<std::string, float> data("Pi", 3.14f);
	cout << data["Pi"] << endl;
}

void main()
{
	//FunctionTempletMain();
	TemplatTyepKeyDataTestMain();
}