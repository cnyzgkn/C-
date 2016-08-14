#include <stdlib.h>
#include <iostream>

class Base
{
public:
	Base():a(10), b(20), c(30) {};
	int Func1(int i) { return i; };
	static int Func2(int i) { return i; };
	int a;
	double b;
	int c;
};

int main()
{
	//pointer to class data member
	int Base::*p2a = &Base::a;
	std::cout << "p2a == " << p2a << std::endl;

	double Base::*p2b = &Base::b;
	std::cout << "p2b == " << p2b << std::endl;

	int Base::*p2c = &Base::c;
	Base* pBase = new Base;
	int ic1 = pBase->c;
	int ic2 = pBase->*p2c;
	std::cout << "ic1 == " << ic1 << std::endl;
	std::cout << "ic2 == " << ic2 << std::endl;

	//pointer to class function member
	typedef int (Base::*pmf)(int);
	pmf func1 = &Base::Func1;
	std::cout << pBase->Func1(7) << std::endl;
	std::cout << (pBase->*func1)(7) << std::endl;

	delete pBase;

	return 1;
}