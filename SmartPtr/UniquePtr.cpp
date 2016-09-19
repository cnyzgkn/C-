#include <memory>
#include <iostream>
#include <vector>
#include "MyClass.h"

void duplicateUseUniquePtr()
{
	std::unique_ptr<MyClass> uniquePtr1(new MyClass());
	uniquePtr1->Func(); //OK

	//std::unique_ptr<MyClass> uniquePtr2 = uniquePtr1; //error: can't switch ownership by constructor
    std::unique_ptr<MyClass> uniquePtr2 = std::move(uniquePtr1); // use std::move
	uniquePtr2->Func(); //OK
	//uniquePtr1->Func(); //error
}

void UniquePtrInSTLVector()
{
    std::vector< std::unique_ptr<MyClass> > uniquePtrVec; 
    std::unique_ptr<MyClass> uniquePtr1(new MyClass());
    //uniquePtrVec.push_back(uniquePtr1); // error
    uniquePtrVec.push_back(std::move(uniquePtr1)); // correct
    uniquePtrVec.push_back(std::move(std::make_unique<MyClass>())); // correct
    //for(auto i: uniquePtrVec)
    //    (*i).Func();
}

void constUniquePtr()
{
    std::unique_ptr<MyClass> uniquePtr1(new MyClass(10));
    (*uniquePtr1).mData = 20;
    std::cout << "uniquePtr1 == " << uniquePtr1 << " *uniquePtr1 = " << (*uniquePtr1).mData << std::endl;

    const std::unique_ptr<MyClass> uniquePtr2(new MyClass(10));
    //uniquePtr2 = NULL; //error
    (*uniquePtr2).mData = 20;
    std::cout << "uniquePtr2 == " << uniquePtr2 << " *uniquePtr2 = " << (*uniquePtr2).mData << std::endl;

    //std::unique_ptr<const MyClass> uniquePtr3(new MyClass(10)); //error
}

int main()
{
    duplicateUseUniquePtr();
    UniquePtrInSTLVector();
    constUniquePtr();

    return 1;
}
    
