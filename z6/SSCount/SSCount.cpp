// KMP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PF.h"
#include <vector>

int unsigned SSCount(const char* s) {
	int count = 0;
	int max = 0;
	PF pf;
	pf.Init(s, strlen(s));
	for (int i = 0;i < sizeof(pf) ;i++) {
		count++;
		if (pf[i] > max) {
			max = pf[i];
		}
	}
	return count+1-max; // неизвестно почему всегда 24 выводит
}
int unsigned SimpleSSCount(const char* s) {
	string str(s);
	string sarr[10000];
	unsigned int n = 0;
	for (int i = 0; i < sizeof(s); i++) {
		string fs = "";
		for (int j = 0; j < sizeof(s)-i; j++) {
			fs += s[i + j];
			for (int k = 0; k < n; k++) {
				if (sarr[k] == fs) {
					fs = "";
					break;
				}
			}
			if(fs != "")
			  sarr[n++] = fs;
		}		
	}
	return n;
}
int main()
{
	// ѕример использовани€ класса PF.
	char s[] = "ghfhgfghfhfhgfhfhgfhghghghgf";
	PF pf;
	pf.Init(s, strlen(s));
	cout << s << endl;
	for (int i = 0; i < pf; i++)
		cout << pf.pattern(i);
	cout << endl;
	for (int i = 0; i < pf; i++)
		cout << pf[i];
	cout << endl;

	// ѕример перебора всех подстрок s длины 8, использу€ класс string.
	cout << endl;
	string str(s);
	for (int i = 0; i < str.length() - 7; i++)
		cout << str.substr(i, 8) << endl;

	// ѕример генерации случайной строки длины N.
	cout << endl;
	const int N = 128;
	char t[N]{ 0 };
	for (int i = 0; i < N - 1; i++)
		t[i] = rand() % ('z' - 'a') + 'a';
	cout << t << endl;
	cout << SSCount(s) << endl;
	cout << SimpleSSCount(s) << endl;
	return 0;
}


