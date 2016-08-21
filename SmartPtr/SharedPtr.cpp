#include <memory>
#include <iostream>
#include <vector>
#include "MyClass.h"

void duplicateUseShardPtr()
{
	std::shared_ptr<MyClass> shardPtr1(new MyClass());
	shardPtr1->Func(); //OK

	std::shared_ptr<MyClass> shardPtr2 = shardPtr1; //OK
    std::shared_ptr<MyClass> shardPtr3 = std::move(shardPtr1); // shardPtr1 is NULL
	shardPtr1->Func(); //error
	shardPtr2->Func(); //OK
    shardPtr3->Func(); //OK

    std::weak_ptr<MyClass> weakPtr(shardPtr1);
    std::cout << "Use count of shared pointer is " << weakPtr.use_count() << std::endl;
}

void ShardPtrInSTLVector()
{
    std::vector< std::shared_ptr<MyClass> > sharedPtrVec; 
    std::shared_ptr<MyClass> shardPtr1(new MyClass());
    std::shared_ptr<MyClass> shardPtr2 = shardPtr1; 
    std::shared_ptr<MyClass> shardPtr3 = shardPtr1; 
    sharedPtrVec.push_back(shardPtr1); 
    sharedPtrVec.push_back(shardPtr2); 
    sharedPtrVec.push_back(shardPtr3); 
    for(auto i: sharedPtrVec)
        (*i).Func();
}

int main()
{
    duplicateUseShardPtr();
    ShardPtrInSTLVector();

    return 1;
}
    
