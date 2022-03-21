#include <stdio.h>//ǥ������� ���̺귯�� //�ּ�: �����Ϸ��� �м������ʴ� ����.
//���̺귯��: �ʿ��Ҷ� �Լ��� �����پ������� �ʿ��Ѱ�.
#define PI 3.141592 //��ȣ���: ������ �ÿ� ��ȣ���ִ°��� �ش� ���� �־���.
//�μ��� ���� ���ϴ� ���α׷�.
void SumMain()//����������Լ�: ���� ���� �Լ�.
{
	//����: �����͸� �����ϴ� ����
	//Ÿ��: float,double(�Ǽ�), int(����),char(����)
	int a = 10;//�ʱ�ȭ: ���������� �����͸� ����.
	int b = 20;
	int c = a + b;
	printf("%d + %d = %d\n", a, b, c); //���̺귯���Լ�: ���̺귯���� �����ϴ� �Լ�.
}
//���� �������ϱ�.(��, ������ ����������*������(3.141592)�̴�.)
//������: ������(����:int),������(�Ǽ�:float),���Ǹ���(�Ǽ�) -> 
//�˰���: ���ǹ������� �Է¹޴´�. 
//���Ǹ��� = ������*������*������. 
//�����Ĵ�� �����۵��ϴ� �� Ȯ���ϱ����� ��� ������ ���� �������� ����Ѵ�.
void CircleAreaMain()
{
	int rad = 0;
	const float pi = 3.141592;//�������: �ʱ�ȭ�� ���� ������ �� ���� ����.
	//pi = 2; //��������� ������ �õ��ϸ� �����Ͽ����� ��.
	float area;
	printf("Radius? ");
	scanf("%d", &rad);
	area = rad * rad * PI; //area = rad * rad * 3.141592; //�����ϵɶ� �̷������� ġȯ�ȴ�.
	//area = rad * rad * pi;
	printf("%d * %d * %f = %f\n", rad, rad, pi, area);
}
//���� Ÿ�԰� ������ ũ�⸦ ����Ͽ���
//(��, sizeof()�� �̿��ϸ� ũ�⸦ �����ִ�)
//int x, char, int , short, long, float, double
void ValSizeMain()
{
	int x;
	printf("x: %d\n", sizeof(x));
	printf("char: %d\n", sizeof(char));
	printf("int: %d\n", sizeof(int));
	printf("short: %d\n", sizeof(short));
	printf("long: %d\n", sizeof(long));
	printf("float: %d\n", sizeof(float));
	printf("double: %d\n", sizeof(double));
}
//0~128
void ASCIICodeTestMain()
{
	for (int i = 0; i < 128; i++)
	{
		printf("%d:%c,",i,i);
		if (i % 12 == 0) printf("\n");
	}
}

//�¾�� ���������� �Ÿ��� d�̰�, 
//�� �ӵ��� s�϶�,
//�¾翡�� ������ ��� �ð� t�� ���Ͽ���.
//s: 30�� km/s
//d: 14960��km
//t: �ʴ���
//��ȭ: t�� �� �ʷ� ��Ÿ������
//������: distance, speed, time -> ����: int//����, float//�Ǽ�, charX //����x 
//�˰���: d / s = t
//---------------- //d //- //s
//����(=����� �´��� Ȯ��)�� �ؾ��Ѵ�. -> ����x �Ǽ�o -> ������ �������������Ƿ� float
void LightSpeedMain()
{
	float dist = 14960;
	float speed = 30;
	float time = dist / speed;
	printf("Time:%f\n", time);
	printf("%f / %f = %f\n",dist,speed,time);
	int min = time / 60;
	//int sec = (int)time % 60;
	int sec = time - (min * 60);
	printf("%d:%d",min, sec);
}

void main()
{
	//Ctrl+F5
	printf("Hello World!!!\n");//����Լ� //\n:�ٹٲ޹���
	//SumMain();//�����ݷ�: ������ ���� ���� ��ȣ
	//CircleAreaMain();
	//ValSizeMain();
	//ASCIICodeTestMain();
	LightSpeedMain();
}