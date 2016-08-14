#include "Myclass.h"

int main()
{
	Base a(1000);
	int* vPtrAddress = (int*)(&a);
	std::cout << "virtual pointer address is " << vPtrAddress << std::endl;

	typedef void (*Func)(void);

}
