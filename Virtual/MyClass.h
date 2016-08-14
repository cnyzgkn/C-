#include <stdlib.h>
#include <iostream>

class Base
{
public:
    Base(int i) :baseI(i) {};

    virtual void print(void)
    { 
    	std::cout << "call virtual Base::print()"; 
    };

    virtual void setI()
    {
    	std::cout << "call virtual Base::setI()";
    };

    virtual ~Base() {};
 
private:
    int baseI;
};