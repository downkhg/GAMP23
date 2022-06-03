#pragma once

#include <iostream>
#include <list>

using namespace std;
//������ ���� �������� Ư¡�� �Ӽ��� ���� ���۸� �����ϴ� Ŭ������ ���� ��Ӱ���� �����ʿ䰡 ����.
namespace Inheritance
{
	//1�����̶�� ��ü�� ��������.
	struct Vector//��ü: ����(2���� ��ġ)
	{
		//public:
		float x;
		float y;
		Vector(float x = 0, float y = 0)
		{
			this->x = x;
			this->y = y;
		}
		void Print(const char* msg)
		{
			cout << msg << "(" << x << "," << y << ")" << endl;
		}
	};

	class Shape //����:
	{
	public:
		Shape()
		{
			cout << "Shape[" << this << "]" << sizeof(*this) << endl;
		}
		~Shape()
		{
			cout << "~Shape[" << this << "]" << endl;
		}
		//�θ��� �Լ�, �ڽĿ��� ��ӹ޾� �����̸����� ���������, ���� �ٸ��Լ���.
		void Draw()
		{
			cout << "Shape[" << this << "]::Draw()" << endl;
		};
	};
	//���� ���� �ﰢ��,�簢���� Ŭ������ �����
	class Circle : public Shape
	{
		Vector vPos;
		float fRadius;
	public:
		Circle(Vector pos = Vector(), float rad = 1)
		{
			cout << "Circle[" << this << "]" << sizeof(*this) << endl;
			vPos = pos;
			fRadius = rad;

			cout << "Rad:" << fRadius << endl;
		}
		~Circle()
		{
			cout << "~Circle[" << this << "]()" << endl;
		}
		void Draw()
		{
			cout << "Circle[" << this << "]::Draw()" << endl;
			vPos.Print("Pos");
			cout << "Rad:" << fRadius << endl;
		}
	};
	class TriAngle : public Shape
	{
		Vector vA;
		Vector vB;
		Vector vC;
	public:
		TriAngle(Vector a = Vector(), Vector b = Vector(), Vector c = Vector()) { cout << "TriAngle[" << this << "]" << sizeof(*this) << endl; };
		~TriAngle() { cout << "TriAngle[" << this << "]" << endl; };
		void Draw()
		{
			cout << "TriAngle[" << this << "]::Draw()" << endl;
			vA.Print("A:");
			vB.Print("B:");
			vC.Print("C:");
		}
	};
	class RectAangle : public Shape
	{
		Vector vTL;
		Vector vBR;
	public:
		RectAangle(Vector tl = Vector(), Vector br = Vector())
		{
			cout << "RectAangle[" << this << "]" << sizeof(*this) << endl;
			vTL = tl;
			vBR = br;
		}
		~RectAangle()
		{
			cout << "~RectAangle[" << this << "]()" << endl;
		}
		void Draw()
		{
			cout << "RectAangle[" << this << "]::Draw()" << endl;
			vTL.Print("TopLeft:");
			vBR.Print("BottomRight:");
		}
	};

	//�θ��� �κа� �ڽ��� �κ��� �޸𸮰� �ٸ���. 
	//�ᱹ ����� ���ؼ� �ΰ��� �����̸��� �Լ��� ������.
	void ShapeMain()
	{
		Shape cShape;
		Circle cCrilce({ 1,1 }, 1);
		cShape.Draw();
		cShape.Shape::Draw();
		cCrilce.Draw();
		cCrilce.Shape::Draw();
	}
	//���α׷� �����߿� �����Ͽ� ����� �������� �׸����� ����ؾ��ϴ°�?//�������� �޸𸮸� �Ҵ�޾ƾ��Ѵ�.
	void RuntimeShapeDrawMain()
	{
		void** arrShape;
		arrShape = new void* [3];

		arrShape[0] = (void*)new Circle();
		arrShape[1] = (void*)new RectAangle();
		arrShape[2] = (void*)new TriAngle();

		//for (int i = 0; i < 3; i++)
		//	(Shape*)arrShape[i]->Draw();
		((Circle*)arrShape[0])->Draw();
		((RectAangle*)(arrShape[1]))->Draw();
		((TriAngle*)(arrShape[2]))->Draw();
	}
	void PowerPointTestMain()
	{
		cout << "#### Inheritance::PowerPointTestMain Start #####" << endl;
		list<Shape*> listShapes;
		listShapes.push_back(new RectAangle());
		listShapes.push_back(new TriAngle());
		listShapes.push_back(new Circle());
		cout << "#### Inheritance::PowerPointTestMain Draw All List #####" << endl;
		list<Shape*>::iterator it = listShapes.begin();
		for (it = listShapes.begin(); it != listShapes.end(); it++)
		{
			Shape* pShaep = *it;
			pShaep->Draw();
		}
		cout << "#### Inheritance::PowerPointTestMain Casting Draw #####" << endl;
		it = listShapes.begin();
		((RectAangle*)*it)->Draw();
		it++;
		((TriAngle*)*it)->Draw();
		it++;
		((Circle*)*it)->Draw();
		cout << "#### Inheritance::PowerPointTestMain Delete List  #####" << endl;
		for (it = listShapes.begin(); it != listShapes.end(); it++)
		{
			Shape* pShaep = *it;
			delete pShaep;
		}
		listShapes.clear();
		cout << "#### Inheritance::PowerPointTestMain End #####" << endl;
	}
}