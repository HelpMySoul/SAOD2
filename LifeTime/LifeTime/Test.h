#pragma once
#include <iostream>
using namespace std;
static int nCount;
class Test
{
	
public:
	
	Test() {
		cout << "Created" << endl;
		nCount++;
		cout << nCount << endl;

	}
	~Test() {
		cout << "Deleted" << endl;
		nCount--;
		cout << nCount << endl;
	}
	void foo(Test t) {
		cout << "foo is running" << endl;
	};

};
class Child : public Test
{
public:
	Child() {
		cout << "Created" << endl;
	}
	~Child() {
		cout << "Deleted" << endl;
	}
};
class Aggregate
{
	Test m_objTest;
public:
	Aggregate() {
		cout << "Created" << endl;
	}
	~Aggregate() {
		cout << "Deleted" << endl;
	}
};
template <class Test>
class AggregateT
{
	Test m_objTest;
public:
	AggregateT() {
		cout << "Created" << endl;
	}
	~AggregateT() {
		cout << "Deleted" << endl;
	}
};