#pragma once
#include <string.h>;
class Str {
	_str* m_pStr;
public:
	Str() { m_pStr = new _str; }		//если не копия, то создаем
	Str(const char* p) {		// новый ресурс
		m_pStr = new _str(p);
	}
	~Str() {
		m_pStr->Release(); 	// Не уничтожаем ресурс!
	}				// Уменьшаем счетчик ссылок!

	int len() const {
		return strlen(m_pStr->m_pszData);
	}
	Str(const Str& s)
	{
		m_pStr = s.m_pStr; 	// ссылаемся на тот же ресурс
		m_pStr->AddRef(); 	// отмечаем, что сослались
	}
	Str& operator = (const Str& s) {
		if (this != &s) {
			s.m_pStr->AddRef(); // Важен порядок?!
			m_pStr->Release();
			m_pStr = s.m_pStr;
		}
		return *this;
	}
	Str& operator += (const Str& s) {
		int length = len() + s.len();
		if (s.len() != 0) {		// добавление ничего не изменит!
			_str* pstrTmp = new _str; 	// Новый ресурс
			delete[] pstrTmp->m_pszData;

			pstrTmp->m_pszData = new char[length + 1];
			strcpy_s(pstrTmp->m_pszData, length + 1, m_pStr->m_pszData);
			strcat_s(pstrTmp->m_pszData, length + 1, s.m_pStr->m_pszData);

			m_pStr->Release();
			m_pStr = pstrTmp;
		}
		return *this;
	}
	operator const char* () const {
		return m_pStr->m_pszData;
	}
	int Find(const char* t, int off) const {
		int i = off;
		int j = 0;
		while (m_pStr->m_pszData[i] != '\0') {
			if (m_pStr->m_pszData[i] == t[j]) {
				// начинаем сравнивать следующие символы
				i++;
				j++;
				if (t[j] == '\0') {
					// вхождение найдено, возвращаем индекс начала образца
					return i - j;
				}
			}
			else {
				// смещаем поиск и начинаем сравнивать с первым символом образца
				i = i - j + 1;
				j = 0;
			}
		}
		// образец не найден
		return -1;
	}
};
