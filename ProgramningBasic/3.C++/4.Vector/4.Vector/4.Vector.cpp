#include <iostream>
using namespace std;

class Vector
{
    float x;
    float y;
public:
    Vector(float x = 0, float y = 0)
    {
        this->x = x;
        this->y = y;
    }
    Vector operator+(Vector v)
    {
        return Vector(x + v.x, y + v.y);
    }
    Vector operator-(Vector v)
    {
        return Vector(x - v.x, y - v.y);
    }
    Vector operator*(float d)
    {
        return Vector(x * d, y * d);
    }
    float Scala()
    {
        return sqrt(x * x + y * y);
    }
    Vector Normalize()
    {
        float fDist = Scala();
        return Vector(x / fDist, y / fDist);
    }
    void Display(const char* msg)
    {
        cout << msg << "(" << x << "," << y << ")" << endl;
    }
    bool operator==(Vector v)
    {
        return (x == v.x && y == v.y);
    }
};
//벡터의 연산이 맞는지 각 연산들이 정상작동하는지 출력과 비교를 통해 검증한다.
//빼기: 위치B - 위치A = 벡터(방향이 있는 이동량)
//더하기 : 위치 + 벡터 = 이동
//평준화: 벡터의 순수한 방향값을 구함.
//스칼라(거리): 벡터의 양.
//곱하기: 방향(평준화)*거리(스칼라) = 벡터 
//검산(테스트)을 통해 해당 벡터가 정상작동하는지 검증한다.
void VectorTestMain()
{
    Vector vPos;// (0, 0); //기본생성자를 디폴트매개변수를 통해 사용가능하게 한다.
    Vector vEndPos(10, 0); //디폴트매개변수이므로 값을 변경하고 싶다면 바로 변경가능하다.
    vPos.Display("vPos");
    vEndPos.Display("vEndPos");

    Vector vDist = vEndPos - vPos; //현재위치에서 도착할 위치를 빼서 거리(벡터)를 구한다.
    vDist.Display("vDist");
    float fDist = vDist.Scala(); //스칼라를 이용하여 벡터에 이동량을 구한다.
    cout << "fDist:" << fDist << endl;
    Vector vDir = vDist.Normalize(); //평준화를 이용하여 벡터의 순수한 방향값을 구한다.
    Vector vScalaMul = vDir * fDist; //두수를 곱하여 다시 방향과 이동량이 있는 벡터를 구함.
    vScalaMul.Display("ScaraMul");

    if (vScalaMul == vDist) //스칼라곱과 초기이동거리가 같다면 수학공식대로 구현된 것이다.
        cout << "vScalaMul == vDist" << endl; //검산완료
    else
        cout << "vScalaMul != vDist" << endl; //문제점 찾기
}

int main()
{
    VectorTestMain();
}