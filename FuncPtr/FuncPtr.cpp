#include <stdlib.h>
#include <iostream>

int Func(int a)
{
	return 1;
}

int Func(double a)
{
	return 2;
}

int main()
{
	typedef int (*pf1)(int);
	typedef int (*pf2)(double);
	pf1 funcPtr1 = Func;
	int a1 = funcPtr1(1);
	pf2 funcPtr2 = Func;
	int a2 = funcPtr2(1.0);
	std::cout << "Func(int a) returns " << a1 << std::endl;
	std::cout << "Func(double a) returns " << a2 << std::endl;
}