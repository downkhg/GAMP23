#pragma once
#include <iostream>
//������ο��� ��������� �ҷ��ð��
//��������� �������ų� ��������� �߻��ϹǷ�,
//������ ���� �ܼ��� �����ϰų� �׳� ���ڸ� ����ϴ� ���� ����.
#define NULL 0

namespace ALL
{
	class Context;
	class StateOne;
	class StateTow;
	class StateThree;

	class Context
	{
		State* m_pState = NULL;
		///�ر׷��� friend�� ��������ʵ��� ������.
		//������ ���� friendŬ������ Ȱ���Ͽ�
		//SetState�� �ܺο����� ������� ��������,
		//�� State��ü������ ���ٰ����ϵ��� �Ҽ��� �ִ�.
		friend class StateOne;
		friend class StateTow;
		friend class StateThree;

		void SetState(State* newState)
		{
			if (m_pState) delete m_pState;
			std::cout << "SetState:" << typeid(*newState).name() << std::endl;
			m_pState = newState;
		}
	public:
		Context()
		{
			m_pState = new StateOne();
		}

		Context(State* curState)
		{
			m_pState = curState;
		}

		~Context()
		{
			delete m_pState;
		}
		void GoNext()
		{
			m_pState->GoNext(this);
		}
	};

	class State
	{
		friend class Context;
	public:
		virtual void GoNext(Context* context) = 0;
	};


	class StateThree : public State
	{
	public:
		void GoNext(Context* context) override
		{
			context->SetState(new StateOne);
		}
	};

	class StateTow : public State
	{
	public:
		void GoNext(Context* context) override
		{
			context->SetState(new StateThree);
		}
	};


	class StateOne : public State
	{
	public:
		void GoNext(Context* context) override
		{
			context->SetState(new StateOne);
		}
	};
}
