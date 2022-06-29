#pragma once
#include <iostream>
//헤더내부에서 헤더파일을 불러올경우
//빌드과정이 느려지거나 헤더꼬임이 발생하므로,
//다음과 같이 단순히 정의하거나 그냥 숫자를 사용하는 것이 좋다.
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
		///※그러나 friend는 사용하지않도록 권장함.
		//다음과 같이 friend클래스를 활용하여
		//SetState를 외부에서는 사용하지 못하지만,
		//각 State객체에서는 접근가능하도록 할수도 있다.
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
