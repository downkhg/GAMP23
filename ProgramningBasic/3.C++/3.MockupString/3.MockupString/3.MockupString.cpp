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

void STDHangManGameMain()
{
	string strQ = "____";
	string strA = "GAME";
	char cInput;

	do
	{
		cout << "Q:" << strQ << endl;
		cin >> cInput;

		int idx = strA.find(cInput);
		if (idx == -1)
		{
			cout << cInput << "is not found!" << endl;
		}
		else
		{
			strQ.replace(idx, 1, 1, cInput);
			//strQ[idx] = cInput;
		}
	} 
	while (!strQ._Equal(strA));
	cout << "The End" << endl;
	//while (strQ != strA);
}
//1.���ڿ� ���ϱ� 
//2.���ڿ� ��(����, �ٸ���)
//3.���ڹ迭 �׽�Ʈ
//4.�����Է�/���
void STDStringOperatorTestMain()
{
	string strLastName = "k";
	string strFirstName= "hg";
	
	//cout << "LastName:";
	//cin >> strLastName;
	//cout << "FristName:";
	//cin >> strFirstName;

	cout << "LastName:";
	for (int i = 0; i < strLastName.size(); i++) 
		cout << strLastName[i]; 
	cout << endl;
	cout << "FirstName:";
	for (int i = 0; i < strFirstName.size(); i++)
		cout << strFirstName[i];
	cout << endl;

	string strKrFullName = strLastName + strFirstName;
	cout << "KrFullName:" << strKrFullName.c_str() << endl;
	//cout << "KrFullName:" << strKrFullName << endl;

	string strEnFullName = strFirstName + strKrFullName;
	cout << "EnFullName:" << strKrFullName.c_str() << endl;
	//cout << "EnFullName:" << strKrFullName << endl;
}

namespace Mockup
{
	class string
	{
		char* m_pStr;
	public:
		string(const char* text = nullptr)
		{
			if (text)
			{
				int nSize = strlen(text);
				nSize++;
				m_pStr = new char[nSize];
				strcpy_s(m_pStr, nSize, text);
				cout << "string[" << this << "/" << (int)this->c_str() << "]:" << this->c_str() << endl;
			}
		}
		~string()
		{
			cout << "~string[" << this << "/" << (int)this->c_str() << "]:" << this->c_str() << endl;
			delete[] m_pStr;
		}
		string(string&& str)
		{
			//*this = str;
			int nSize = strlen(str.c_str());
			nSize++;
			m_pStr = new char[nSize];
			strcpy_s(m_pStr, nSize, str.c_str());
			cout << "string[" << this << "/" << (int)this->c_str() << "]:" << this->c_str() << endl;
		}

		const char* c_str()
		{
			return m_pStr;
		}

		//��ǰ��� �߰�����
		int find(char c)
		{
			return  -1;
		}
		int replace(int idx, int size, int count, char c)
		{
			return -1;
		}
		bool _Equal(string str)
		{
			return !strcmp(this->m_pStr, str.c_str());
		}

		//�����ڿ����ε� �߰�����.
		int size()
		{
			return 0;
		}

		string operator+(const string& str)
		{
			string strTemp;
			return strTemp;
		}

		bool operator==(const string& str)
		{
			return false;
		}

		bool operator!=(const string& str)
		{
			return false;
		}

		char operator[](int idx)
		{
			return m_pStr[idx];
		}

		friend ostream& operator<< (ostream& os, string& s)
		{
			return os << s;
		}

		friend istream& operator>> (istream& is, string& s)
		{
			return is >> s;
		}
	};
}

void MockupStringMain()
{
	//_CrtSetBreakAlloc(161); //�޸� ������ ��ȣ�� ������ �Ҵ��ϴ� ��ġ�� �극��ũ ����Ʈ�� �Ǵ�.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //�޸� ���� �˻� 
	Mockup::string strMsg("test");
	Mockup::string strMsg2("DataTest");
	Mockup::string strCopyMsg = strMsg;

	cout << "Msg[" << &strMsg << "/" << (int)strMsg.c_str() << "]:" << strMsg.c_str() << endl;
	cout << "Msg2[" << &strMsg2 << "/" << (int)strMsg2.c_str() << "]:" << strMsg2.c_str() << endl;
	cout << "CopyMsg[" << &strCopyMsg << "/" << (int)strCopyMsg.c_str() << "]:" << strCopyMsg.c_str() << endl;
}

void MockupHangManGameMain()
{
	Mockup::string strQ = "____";
	Mockup::string strA = "GAME";
	char cInput;

	do
	{
		cout << "Q:" << strQ.c_str() << endl;
		cin >> cInput;

		int idx = strA.find(cInput);
		if (idx == -1)
		{
			cout << cInput << "is not found!" << endl;
		}
		else
		{
			strQ.replace(idx, 1, 1, cInput);
			//strQ[idx] = cInput;
		}
	} 	while (!strQ._Equal(strA));
	cout << "The End" << endl;
	//while (strQ != strA);
}
//1.���ڿ� ���ϱ� 
//2.���ڿ� ��(����, �ٸ���)
//3.���ڹ迭/���� �׽�Ʈ
//4.�����Է�/���
void MockupStringOperatorTestMain()
{
	Mockup::string strLastName = "k";
	Mockup::string strFirstName = "hg";

	//cout << "LastName:";
	//cin >> strLastName;
	//cout << "FristName:";
	//cin >> strFirstName;

	cout << "LastName:";
	for (int i = 0; i < strLastName.size(); i++)
		cout << strLastName[i];
	cout << endl;
	cout << "FirstName:";
	for (int i = 0; i < strFirstName.size(); i++)
		cout << strFirstName[i];
	cout << endl;

	Mockup::string strKrFullName = strLastName + strFirstName;
	cout << "KrFullName:" << strKrFullName.c_str() << endl;
	//cout << "KrFullName:" << strKrFullName << endl;

	Mockup::string strEnFullName = strFirstName + strKrFullName;
	cout << "EnFullName:" << strKrFullName.c_str() << endl;
	//cout << "EnFullName:" << strKrFullName << endl;
}

void main()
{
	//STDStringMain();
	//MockupStringMain();
	//STDHangManGameMain();
	MockupStringMain();
}