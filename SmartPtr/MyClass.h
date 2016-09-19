#include <stdlib.h>
#include <iostream>

class MyClass
{
public:
	MyClass(int Data = 0) : mData(Data) {};
    void Func() { std::cout << "I own this object!" << std::endl; }
	int mData;
};