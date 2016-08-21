#include <memory>
#include <iostream>
#include <vector>
#include "MyClass.h"

void duplicateUseAutoPtr()
{
	std::auto_ptr<MyClass> autoPtr1(new MyClass());
	autoPtr1->Func(); //OK

	std::auto_ptr<MyClass> autoPtr2 = autoPtr1;
	autoPtr2->Func(); //OK
	autoPtr1->Func(); //should crash but OK in VS2015. need to test in gcc
}

void AutoPtrInSTLVector()
{
    std::vector< std::auto_ptr<MyClass> > autoPtrVec; // error: auto_ptr not used in std container
    for(auto i: autoPtrVec)
        i->Func();
}

int main()
{
    duplicateUseAutoPtr();
    AutoPtrInSTLVector();

    return 1;
}
    
