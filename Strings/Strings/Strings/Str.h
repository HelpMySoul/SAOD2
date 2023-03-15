#pragma once
class Str {
	char* m_pszText;
public:
	Str() 	//Конструктор “по умолчанию” (default)*
	{
		m_pszText = new char[1]{ 0 };
	}

	~Str() { delete[]m_pszText; }
	Str(const char* p)
	{
		if (p) {
			m_pszText = new char[strlen(p) + 1];
			strcpy_s(m_pszText, strlen(p) + 1, p);
		}
		else
			m_pszText = new char[1]{ 0 };
	}
	operator const char* ()const { return m_pszText; }
	Str(const Str& s) //Константная ссылка на объект
	{
		m_pszText = new char[strlen(s.m_pszText) + 1];
		strcpy_s(m_pszText,
			strlen(s.m_pszText) + 1,
			s.m_pszText);
	}
	const Str& operator = (const Str& s) //Константная ссылка на объект
	{
		if (&s == this) return *this;
		delete[] m_pszText;	 //Освобождаем текущие данные					//Дальше просто копирование
		m_pszText = new char[strlen(s.m_pszText) + 1];
		strcpy_s(m_pszText,
			strlen(s.m_pszText) + 1,
			s.m_pszText);
		return *this;
	}
	Str& operator +=(const char* sz) 
	{
		char* result = new char[strlen(this->m_pszText) + strlen(sz) + 1];
		int pos = 0;
		for (int i = 0; this ->m_pszText[i] != 0; i++) {
			result[pos] = this -> m_pszText[i];
			pos++;
		}
		for (int i = 0; *sz != 0; *sz++) {
			result[pos] = *sz;
			pos++;
		}
		result[pos] = 0;
		this->m_pszText = result;
		return *this;
	}
	Str operator +(const char* sz) const {
		char* result = new char[strlen(this->m_pszText) + strlen(sz) + 1];
		int pos = 0;
		for (int i = 0; this->m_pszText[i] != 0; i++) {
			result[pos] = this->m_pszText[i];
			pos++;
		}
		for (int i = 0; *sz != 0; *sz++) {
			result[pos] = *sz;
			pos++;
		}
		result[pos] = 0;
		return result;

	}
};

