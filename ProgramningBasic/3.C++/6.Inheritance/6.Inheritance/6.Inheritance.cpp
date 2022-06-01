//�߻�ȭ
//��ǥ(����):������ ��ǥ�� 2�������� ��Ÿ�������� ��ü
//����: ����:�׸��� //�������̽�
//�ﰢ��: �Ӽ�:��ǥx3 ����:�׸���
//�簢��: �Ӽ�:��ǥx4 ����:�׸���
//��: �Ӽ�:��ǥ,������ ����:�׸���
#include <iostream>
using namespace std;
//���: �ڽ��� �������� �κ��� Ŭ������ �����Ͽ�, ����ϸ� ������ ������ �ڵ带 �ۼ������ʾƵ��ȴ�. 
//�θ�κ��� �����ǰ�, �ڽĺκ��� �޸𸮰� �߰��Ǿ� �����ȴ�.
namespace Inheritance
{
	class Vihicle
	{
	protected: //�ڽ��� ���ٰ����ϰ� �ܺο��� ���ٺҰ�.
		int m_nGear = 0;
		int m_nSpeed = 0;
		int m_nSeats = 1;
	public:
		Vihicle(int seat = 1)
		{
			cout << "Vihicle[" << this << "]:" << sizeof(*this) << endl;
			m_nSeats = seat;
		}
		~Vihicle() { cout << "~Vihicle[" << this << "]" << endl; }

		void Accel() { m_nSpeed++; }
		void Break() { m_nSpeed--; }
		void SetGear(int gear) { m_nGear = gear; }
		void SetSeats(int seat) { m_nSeats = seat; }
	};

	class Bike : public Vihicle
	{
	public:
		Bike() { cout << "Bike[" << this << "]:" << sizeof(*this) << endl; }
		~Bike() { cout << "~Bike[" << this << "]" << endl; }
	};

	class AutoBike : public Vihicle
	{
		int m_nEngine;
	public:
		AutoBike(int engine = 300)
		{
			cout << "AutoBike[" << this << "]:" << sizeof(*this) << endl;
			m_nEngine = engine;
		}
		~AutoBike() { cout << "~AutoBike[" << this << "]" << endl; }
	};

	class Track : public Vihicle
	{
		int m_nEngine;
		int m_nMaxWight;
	public:
		Track(int engine = 3000, int wight = 1000)
		{
			cout << "Track[" << this << "]:" << sizeof(*this) << endl;
			m_nEngine = engine;
			m_nMaxWight = wight;
		}
		~Track() { cout << "~Track[" << this << "]" << endl; }
	};

	class Bus : public Vihicle
	{
		int m_nEngine;
	public:
		Bus(int engine = 7000, int seat = 30) :Vihicle(seat)//�θ�������� ȣ��: �����ڸ� ���� ȣ���ϸ� �θ����� ���������ڿ� ������� ��밡��.
		{
			cout << "Bus[" << this << "]:" << sizeof(*this) << endl;
			m_nEngine = engine;
			///m_nSeats = seat; //�θ����� private�� �ƴϿ��� ���ٰ���.
		}
		~Bus() { cout << "~Bus[" << this << "]" << endl; }
	};

	void CarMain()
	{
		Vihicle cVihvle;
		Bike cBike;
		AutoBike cAutoBike;
		Track cTrack;
		Bus cBus;
	}
}
//�������: �θ� ����Ŭ������ ��ӹ޴°�.
namespace HierarchyInheritance
{
	class Vihicle
	{
	protected: //�ڽ��� ���ٰ����ϰ� �ܺο��� ���ٺҰ�.
		int m_nGear = 0;
		int m_nSpeed = 0;
		int m_nSeats = 1;
	public:
		Vihicle(int seat = 1)
		{
			cout << "Vihicle[" << this << "]:" << sizeof(*this) << endl;
			m_nSeats = seat;
		}
		~Vihicle() { cout << "~Vihicle[" << this << "]" << endl; }

		void Accel() { m_nSpeed++; }
		void Break() { m_nSpeed--; }
		void SetGear(int gear) { m_nGear = gear; }
		void SetSeats(int seat) { m_nSeats = seat; }
	};

	class Eneginer : Vihicle
	{
	protected:
		int m_nEngine;
	public:
		Eneginer(int engine = 300)
		{
			cout << "Eneginer[" << this << "]:" << sizeof(*this) << endl;
			m_nEngine = engine;
		}
		~Eneginer()
		{
			cout << "~Eneginer[" << this << "]" << endl;
		}
	};

	class AutoBike : public Eneginer
	{
	public:
		AutoBike(int engine = 300) : Eneginer(engine)
		{
			cout << "AutoBike[" << this << "]:" << sizeof(*this) << endl;
		}
		~AutoBike() { cout << "~AutoBike[" << this << "]" << endl; }
	};

	class Track : public Eneginer
	{
		int m_nMaxWight;
	public:
		Track(int engine = 3000, int wight = 1000)
		{
			cout << "Track[" << this << "]:" << sizeof(*this) << endl;
			m_nEngine = engine;
			m_nMaxWight = wight;
		}
		~Track() { cout << "~Track[" << this << "]" << endl; }
	};

	class Bus : public Eneginer
	{
	public:
		Bus(int engine = 7000, int seat = 30) :Eneginer(engine)//�θ�������� ȣ��: �����ڸ� ���� ȣ���ϸ� �θ����� ���������ڿ� ������� ��밡��.
		{
			//Vihicle(seat); //���������� ó���ϸ� �ӽð�ü����⶧���� �ʱ�ȭ�� �ƴϴ�.
			//m_nSeats = seat; //��������� ������ �ʱ�ȭ�� �θ𿡼� �̹� �̷������,
			cout << "Bus[" << this << "]:" << sizeof(*this) << endl;
			m_nEngine = engine;
			///m_nSeats = seat; //�θ����� private�� �ƴϿ��� ���ٰ���.
		}
		~Bus() { cout << "~Bus[" << this << "]" << endl; }
	};

	void CarMain()
	{
		//Vihicle cVihicle; //Ż���̶�°��� ��з��� �����̹Ƿ� ���������ʴ´�.
		//Bike cBike; //����� �߰����������Ƿ� ���� Ŭ������ �����ʿ䰡����.
		//���� �����Ÿ� ����ٸ� ��ü�� �ٸ��� ǥ���ϴ°��� ����ϼ��ִ�.
		Vihicle cBike;
		Eneginer cAutoBike;
		//AutoBike cAutoBike;
		Track cTrack;
		Bus cBus;
		cout << "#### Size #####" << endl;
		//cout << "Vihicle:" << sizeof(cVihicle) << endl;
		cout << "Engener:" << sizeof(cAutoBike) << endl;
		cout << "Track:" << sizeof(cTrack) << endl;
		cout << "Bus:" << sizeof(cBus) << endl;
	}
}
//���߻���� ����
namespace DiamondInhartance
{
	class Vihicle
	{
	protected: //�ڽ��� ���ٰ����ϰ� �ܺο��� ���ٺҰ�.
		int m_nGear = 0;
		int m_nSpeed = 0;
		int m_nSeats = 1;
	public:
		Vihicle(int seat = 1)
		{
			cout << "Vihicle[" << this << "]:" << sizeof(*this) << endl;
			m_nSeats = seat;
		}
		~Vihicle() { cout << "~Vihicle[" << this << "]" << endl; }

		void Accel() { m_nSpeed++; }
		void Break() { m_nSpeed--; }
		void SetGear(int gear) { m_nGear = gear; }
		void SetSeats(int seat) { m_nSeats = seat; }
	};

	class Bike : public Vihicle
	{
	public:
		Bike() { cout << "Bike[" << this << "]:" << sizeof(*this) << endl; }
		~Bike() { cout << "~Bike[" << this << "]" << endl; }
	};

	class Enginer : public Vihicle
	{
	protected:
		int m_nEngine;
	public:
		Enginer(int engine = 300)
		{
			cout << "Enginer[" << this << "]:" << sizeof(*this) << endl;
			m_nEngine = engine;
		}
		~Enginer()
		{
			cout << "~Enginer[" << this << "]" << endl;
		}
	};

	class AutoBike : public Bike, public Enginer
	{
	public:
		AutoBike(int engine = 300) : Enginer(engine)
		{
			cout << "AutoBike[" << this << "]:" << sizeof(*this) << endl;
		}
		~AutoBike() { cout << "~AutoBike[" << this << "]" << endl; }
	};

	class Track : public Enginer
	{
		int m_nMaxWight;
	public:
		Track(int engine = 3000, int wight = 1000)
		{
			cout << "Track[" << this << "]:" << sizeof(*this) << endl;
			m_nEngine = engine;
			m_nMaxWight = wight;
		}
		~Track() { cout << "~Track[" << this << "]" << endl; }
	};

	class Bus : public Enginer
	{
	public:
		Bus(int engine = 7000, int seat = 30) :Enginer(engine)//�θ�������� ȣ��: �����ڸ� ���� ȣ���ϸ� �θ����� ���������ڿ� ������� ��밡��.
		{
			//Vihicle(seat); //���������� ó���ϸ� �ӽð�ü����⶧���� �ʱ�ȭ�� �ƴϴ�.
			//m_nSeats = seat; //��������� ������ �ʱ�ȭ�� �θ𿡼� �̹� �̷������,
			cout << "Bus[" << this << "]:" << sizeof(*this) << endl;
			m_nEngine = engine;
			///m_nSeats = seat; //�θ����� private�� �ƴϿ��� ���ٰ���.
		}
		~Bus() { cout << "~Bus[" << this << "]" << endl; }
	};
	//���̾Ƹ����: �����θ� ���� �ڽ��� ���߻�ӹ޾Ƽ� �����Ѱ��.
	//C#�̳� Java������ ������ ���� ���߻���� �������ؼ� ���߻���� �Ұ����ϴ�.
	//(��, �������̽��� ���߻�Ӱ����ϳ� Ŭ�������� �� �ٸ��Ƿ� ���� ������)
	void CarMain()
	{
		AutoBike cAutoBike;

		cout << "#### Size #####" << endl;
		cout << "Engener:" << sizeof(cAutoBike) << endl;
		//���߻���� �Ҷ��� ��ӱ����� ����� �ľ��ؾ��Ѵ�.
		//cAutoBike.SetGear(0);
		cAutoBike.Bike::SetGear(0);
		cAutoBike.Enginer::SetGear(0);
	}
}
void main()
{
	//ShapeMain();
	//Inheritance::CarMain();
	//HierarchyInheritance::CarMain();
	DiamondInhartance::CarMain();
}