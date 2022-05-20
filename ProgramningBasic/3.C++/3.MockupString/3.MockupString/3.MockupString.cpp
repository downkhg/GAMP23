#include <iostream>
#include <string.h>

using namespace std;

void STDStringMain()
{
	string strMsg("test");
	string strMsg2("DataTest");
	string strCopyMsg = strMsg;

	cout << "Msg[" << &strMsg << "/" << (int)strMsg.c_str() << "]:" << strMsg.c_str() << endl;
	cout << "Msg2[" << &strMsg2 << "/" << (int)strMsg2.c_str() << "]:" << strMsg2.c_str() << endl;
	cout << "CopyMsg[" << &strCopyMsg << "/" << (int)strCopyMsg.c_str() << "]:" << strCopyMsg.c_str() << endl;
}

namespace Mockup
{
	class string
	{
		char* m_pStr;
	public:
		string(const char* text)
		{
			int nSize = strlen(text);
			nSize++;
			m_pStr = new char[nSize];
			strcpy_s(m_pStr, nSize , text);
			cout << "string[" << this << "/" << (int)this->c_str() << "]:" << this->c_str() << endl;
		}
		~string()
		{
			cout << "~string[" << this << "/" << (int)this->c_str() << "]:" << this->c_str() << endl;
			delete[] m_pStr;
		}

		const char* c_str()
		{
			return m_pStr;
		}
	};
}

void MockupStringMain()
{
	//_CrtSetBreakAlloc(161); //메모리 누수시 번호를 넣으면 할당하는 위치에 브레이크 포인트를 건다.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //메모리 누수 검사 
	Mockup::string strMsg("test");
	Mockup::string strMsg2("DataTest");
	Mockup::string strCopyMsg = strMsg;

	cout << "Msg[" << &strMsg << "/" << (int)strMsg.c_str() << "]:" << strMsg.c_str() << endl;
	cout << "Msg2[" << &strMsg2 << "/" << (int)strMsg2.c_str() << "]:" << strMsg2.c_str() << endl;
	cout << "CopyMsg[" << &strCopyMsg << "/" << (int)strCopyMsg.c_str() << "]:" << strCopyMsg.c_str() << endl;
}

void main()
{
	//STDStringMain();
	MockupStringMain();
}