#pragma once
#include <string.h>;
class Str {
	_str* m_pStr;
public:
	Str() { m_pStr = new _str; }		//���� �� �����, �� �������
	Str(const char* p) {		// ����� ������
		m_pStr = new _str(p);
	}
	~Str() {
		m_pStr->Release(); 	// �� ���������� ������!
	}				// ��������� ������� ������!

	int len() const {
		return strlen(m_pStr->m_pszData);
	}
	Str(const Str& s)
	{
		m_pStr = s.m_pStr; 	// ��������� �� ��� �� ������
		m_pStr->AddRef(); 	// ��������, ��� ���������
	}
	Str& operator = (const Str& s) {
		if (this != &s) {
			s.m_pStr->AddRef(); // ����� �������?!
			m_pStr->Release();
			m_pStr = s.m_pStr;
		}
		return *this;
	}
	Str& operator += (const Str& s) {
		int length = len() + s.len();
		if (s.len() != 0) {		// ���������� ������ �� �������!
			_str* pstrTmp = new _str; 	// ����� ������
			delete[] pstrTmp->m_pszData;

			pstrTmp->m_pszData = new char[length + 1];
			strcpy_s(pstrTmp->m_pszData, length + 1, m_pStr->m_pszData);
			strcat_s(pstrTmp->m_pszData, length + 1, s.m_pStr->m_pszData);

			m_pStr->Release();
			m_pStr = pstrTmp;
		}
		return *this;
	}
	operator const char* (){
		return  (const char*)m_pStr;
	}
	int Find(const char* t, int off) const {
		int len_t = strlen(t);
		int len_this = strlen((const char*)m_pStr);
		if (off >= len_this)
			return -1;
		for (int i = off; i <= len_this - len_t; ++i) {
			if (strncmp((const char*)(m_pStr + i), t, len_t) == 0)
				return i;
		}
		return -1;
	}
};
