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
//����������:++data,����������:data++ 
//�������� ���� ���������ڿ� ���� �������� �������� Ȯ���ϴ� ���α׷�
//������: ������2���� �ʿ��ϴ� -> nDataA,nDataB -> ����
//�˰���: nDataB = ++nDataA, nDataB = nDataA++, ?
void IncDecTestMain()
{
	int nDataA = 10, nDataB; //10, ?
	nDataB = nDataA; //10
	printf("1.nDataA/B:%d/%d\n",nDataA,nDataB);
	nDataB = ++nDataA; //11/11 ->  ����������: ���Կ����ں��� �켱������ �����Ƿ�, �����ϰ�, ���� ������ ���Եȴ�.
	printf("2.nDataA/B:%d/%d\n", nDataA, nDataB);
	nDataB = nDataA++; //12/12 -> 12/11 -> ���������ڴ� ���Կ����ں��� �켱������ �����Ƿ�, ������ ���� ������ ���Եȴ�.
	printf("3.nDataA/B:%d/%d\n", nDataA, nDataB);
}
//������ �Է¹޾Ƽ� ������ ����ϴ� ���α׷�
//(A: 90�̻� B: 80���̻� C: 70���̻� D: 60���̻� F: 60���̸�)
//������: ����->����, ����->����
//�˰���: �Է¹��� ������ (A: 90�̻� B: 80���̻� C: 70���̻� D: 60���̻� F: 60���̸�) �� �ش�Ǹ� ������ ����ϱ�
void GradeTestMain()
{
	int nScore;
	char cGrade;

	printf("Score:");
	scanf("%d", &nScore);

	if (nScore >= 90)
	{
		cGrade = 'A';
	}
	else
	{
		if (nScore >= 80)
		{
			cGrade = 'B';
		}
		else
		{
			if (nScore >= 70)
			{
				cGrade = 'C';
			}
			else
			{
				if (nScore >= 60)
				{
					cGrade = 'D';
				}
				else
				{
					cGrade = 'F';
				}
			}
		}
	}

	printf("Score/Grade:%d/%c",nScore,cGrade);
}

void GradeTestMain2()
{
	int nScore;
	char cGrade;

	printf("Score:");
	scanf("%d", &nScore);

	if (nScore >= 90)
	{
		cGrade = 'A';
	}
	else if (nScore >= 80)
	{
		cGrade = 'B';
	}
	else if (nScore >= 70)
	{
		cGrade = 'C';
	}
	else if (nScore >= 60)
	{
		cGrade = 'D';
	}
	else
	{
		cGrade = 'F';
	}

	printf("Score/Grade:%d/%c", nScore, cGrade);
}
//���� �����
//1. ���� -> (����:����:����?�Ǽ�!)�� (������:����:����)�� (�Է�:scanf)�ϸ� ��(���:����:�Ǽ�)�� ����ϴ� ���.
//2. �����ڴ� ��Ģ���길 �����ϴ�(+,-,*,/)
//3. ������ �ϱ����ؼ� �ּ� 2���� ������ �ʿ��ϹǷ� 2���� ����Ѵ�.
//������: ����A, ����B, ������, ���
//�˰���: ���ڿ� �����ڸ� �Է¹ް�, 
//		    �Է¹��� �����ڰ� +�� �μ��� ���Ͽ� ����� �ִ´�.
//		    �Է¹��� �����ڰ� -�� �μ��� ���� ����� �ִ´�.
//		    �Է¹��� �����ڰ� *�� �μ��� ���ϰ� ����� �ִ´�.
//		    �Է¹��� �����ڰ� /�� �μ��� ������ ����� �ִ´�.
void CaculatorMain()
{
	float fDataA, fDataB, fResult;
	char cOp;
	//scanf("%f", &fDataA);
	//scanf("%f", &fDataB);
	//scanf("%c", &cOp);
	printf("ex) 1+1 >> ");
	scanf("%f%c%f",&fDataA,&cOp,&fDataB);

	if(cOp == '+')
		fResult = fDataA + fDataB;
	else if (cOp == '-')
		fResult = fDataA - fDataB;
	else if (cOp == '*')
		fResult = fDataA * fDataB;
	else if (cOp == '/')
		fResult = fDataA / fDataB;
	else
	{
		printf("%c is not Support!\n",cOp);
		return; //������ ������ �Լ��� ����ȴ�.
	}

	printf("%f%c%f=%f",fDataA,cOp, fDataB, fResult);
}

void CaculatorSwitchMain()
{
	float fDataA, fDataB, fResult;
	char cOp;
	//scanf("%f", &fDataA);
	//scanf("%f", &fDataB);
	//scanf("%c", &cOp);
	printf("ex) 1+1 >> ");
	scanf("%f%c%f", &fDataA, &cOp, &fDataB);

	switch (cOp)
	{
	case '+':
		fResult = fDataA + fDataB;
		break;
	case '-':
		fResult = fDataA - fDataB;
		break;
	case '*':
		fResult = fDataA * fDataB;
		break;
	case '/':
		fResult = fDataA / fDataB;
		break;
	default:
		printf("%c is not Support!\n", cOp);
		return; //������ ������ �Լ��� ����ȴ�.
		break;
	}
	
	printf("%f%c%f=%f", fDataA, cOp, fDataB, fResult);
}

//���� �����
//1. ���� -> (����:����:����?�Ǽ�!)�� (������:����:����)�� (�Է�:scanf)�ϸ� ��(���:����:�Ǽ�)�� ����ϴ� ���.
//2. �����ڴ� ��Ģ���길 �����ϴ�(+,-,*,/)
//3. ������ �ϱ����ؼ� �ּ� 2���� ������ �ʿ��ϹǷ� 2���� ����Ѵ�.
//4. ����� �����Ҷ����� (�ݺ�)�ؼ� ����� �Է��ϰ�, Ȯ���Ҽ��ִ�.
//������: ����A, ����B, ������, ���
//�˰���: ���ڿ� �����ڸ� �Է¹ް�, 
//		    �Է¹��� �����ڰ� +�� �μ��� ���Ͽ� ����� �ִ´�.
//		    �Է¹��� �����ڰ� -�� �μ��� ���� ����� �ִ´�.
//		    �Է¹��� �����ڰ� *�� �μ��� ���ϰ� ����� �ִ´�.
//		    �Է¹��� �����ڰ� /�� �μ��� ������ ����� �ִ´�.
void CaculatorLoofMain()
{
	float fDataA, fDataB, fResult; //�ΰ��� �Է��ϴ� �Ǽ��������� ������ �Է��ϴ� ������ �������. �ʱ�ȭ �����ʾ����Ƿ� ��� ������ ���� �˼�����.
	char cOp = 0; //�����ڸ� �Է¹ޱ����ؼ� ������������ �����ϰ� �ʱ�ȭ�� �ʾҴ�.

	//while (true) //���� ����
	//while(cOp == 'x')// 0 == 'x' -> F
	//while (!(cOp == 'x'))// 0 == 'x' -> F //���������� �ݴ� ����� �ݺ����� �������� �����.
	while (cOp != 'x')
	{
		printf("ex) 1+1 exit)?x?>> "); //
		scanf("%f%c%f", &fDataA, &cOp, &fDataB); //
		//if (cOp == 'x') break; //�ΰ��� ������ ���� ������ ������ �����ϱ� ����Ƿ�, ���ǹ����� �����Ѵ�.
		switch (cOp)
		{
		case '+':
			fResult = fDataA + fDataB;
			break;
		case '-':
			fResult = fDataA - fDataB;
			break;
		case '*':
			fResult = fDataA * fDataB;
			break;
		case '/':
			fResult = fDataA / fDataB;
			break;
		default:
			printf("%c is not Support!\n", cOp);
			return; //������ ������ �Լ��� ����ȴ�.
			break;
		}

		printf("%f%c%f=%f\n", fDataA, cOp, fDataB, fResult);
	}
}

//������ 10������ ����ϰ� 100���� �̻��϶� �ð���?
//������ 1�ð����� 2�辿 �����Ѵ�.
//������: ���ռ�,�ð� -> ����! �Ǽ�?
//�˰���: 1�ð�����, ���ռ�*2,  100���� �̻��̵ɶ�����
//1.�����Ϳ� �˰����� �и��Ѵ�.
//2.�����ʹ� ���� �˰����� ����,�ݺ�,���� ���� ���յȴ�.
//3.�ݺ��Ǵ� ���� ���� �ݺ��ϰ� ������ ����Ѵ�.
void BateriaMain()
{
	int nBater = 10;
	int nTime = 0;

	while (true)
	{
		nTime = nTime + 1; //1
		nBater = nBater * 2; //10 * 2 = 20
		printf("Batera/Time: %d/%d\n", nBater, nTime);
		if (nBater >= 100) break;
	}
	//nTime = 1; //1
	//nBater = nBater * 2; //10 * 2 = 20

	//nTime = 2; //2
	//nBater = nBater * 2; //20 * 2 = 40

	//nTime = 3; //3
	//nBater = nBater * 2; //40 * 2 = 80

	//nTime = 4; //4
	//nBater = nBater * 2; //80 * 2 = 160

	printf("Batera/Time: %d/%d\n",nBater,nTime);
}

//(����:����) 10������ ����Ͽ� (10�ð���:����)�� ���ռ��� ���Ͽ���.
//�̶�, ������ (1�ð� ���� 4��)�� �����Ѵ� 
//���ռ�:10 //�ð�:0  //���ռ�*=4
void BateriaCountMain()
{
	int nBater = 10;
	int nTime = 0;

	////�Ϲ������� ������ �����ϱ⿣ while���� �����ϴ�.
	//while (true)
	//{
	//	nTime = nTime + 1; //1
	//	nBater = nBater * 4; //10 * 4 = 40
	//	printf("Batera/Time: %d/%d\n", nBater, nTime);
	//	if (nTime == 10) break;
	//}
	
	////���α׷��ֿ� �ͼ������ʴٸ� �̷��� ����ϱ� �����ʴ�.
	//for (nTime = 0; nTime <= 10; nTime++)
	//{
	//	nBater = nBater * 4; //10 * 4 = 40
	//	printf("Batera/Time: %d/%d\n", nBater, nTime);
	//}
}

void main()
{
	//Ctrl+F5
	printf("Hello World!!!\n");//����Լ� //\n:�ٹٲ޹���
	//SumMain();//�����ݷ�: ������ ���� ���� ��ȣ
	//CircleAreaMain();
	//ValSizeMain();
	//ASCIICodeTestMain();
	//LightSpeedMain();
	//IncDecTestMain();
	//GradeTestMain();
	//CaculatorMain();
	//CaculatorLoofMain();
	//BateriaMain();
	BateriaCountMain();
}