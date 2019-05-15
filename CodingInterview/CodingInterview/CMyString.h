#pragma once
#include <cstring>
class CMyString
{
private:
	char* m_pData;
public:
	CMyString(char * pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString();
	CMyString& operator = (const CMyString& str);
};


inline CMyString::CMyString(char* pData)
{
	if (pData == nullptr) {
		this->m_pData = new char('\0');
	}
	else {
		this->m_pData = new char[strlen(pData) + 1];
		strcpy_s(this->m_pData, strlen(pData) + 1, pData);
	}
}

inline CMyString::CMyString(const CMyString& str) :
	m_pData{ nullptr }
{
	this->m_pData = new char[strlen(str.m_pData) + 1];
	strcpy_s(this->m_pData, strlen(str.m_pData) + 1, str.m_pData);
}

inline CMyString::~CMyString()
{
	delete[] this->m_pData;
}

inline CMyString& CMyString::operator=(const CMyString& str)
{
	// TODO: insert return statement here
	if (this != &str) {
		CMyString tempStr{ str };

		char* temp = this->m_pData;
		this->m_pData = tempStr.m_pData;
		tempStr.m_pData = temp;
	}
	return *this;
}
