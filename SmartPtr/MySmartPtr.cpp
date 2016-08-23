#include <stdlib.h>
#include <iostream>
#include "MyClass.h"

template<typename T> class MyAuto_ptr
{
public:
	MyAuto_ptr(T* ptr = NULL) : mPtr(ptr) {};
	MyAuto_ptr(MyAuto_ptr& other) : mPtr(other.release()) {};
	~MyAuto_ptr() {delete mPtr;};
	T& operator=(const MyAuto_ptr& other) //!! here not use const because mPtr in other be released
	{
		if(this != &other)
			reset(other.release());

		return *this;
	}
	T* operator->() {return mPtr;};
	const T* operator->() const {return mPtr;};
	T& operator*() {return *mPtr;};
	const T& operator*() const {return *mPtr;};
	T* get() const {return mPtr;};
	T* release()
	{
		T* oldPtr = mPtr;
		mPtr = NULL;
		return oldPtr;
	};
	void reset(T* ptr = NULL)
	{
		if(mPtr != ptr)
		{
			delete mPtr;
			mPtr = ptr;
		}
	};

private:
	T* mPtr;
};

void duplicateUseAutoPtr()
{
	MyAuto_ptr<MyClass> autoPtr1(new MyClass());
	autoPtr1->Func(); //OK

	MyAuto_ptr<MyClass> autoPtr2 = autoPtr1;
	autoPtr2->Func(); //OK
	autoPtr1->Func(); //should crash but OK in VS2015. need to test in gcc
}

template<typename T> class MyShared_ptr
{
public:
	MyShared_ptr(T* ptr = NULL) : mPtr(ptr), count(1) {};
	MyShared_ptr(MyShared_ptr& other) : mPtr(other.mPtr), count(other.count) {++count;};
	~MyShared_ptr() {count_decrement();};
	//OK to self-assignment becuase it will increment and decrement
	MyShared_ptr& operator=(const MyShared_ptr& other) 
	{
		++count;
		count_decrement();
		mPtr = other.mPtr;
		count = other.count;
		return *this;
	}
	T* operator->() {return mPtr;};
	const T* operator->() const {return mPtr;};
	T& operator*() {return *mPtr;};
	const T& operator*() const {return *mPtr;};
	int get_refCount() {return count;};

private:
	void count_decrement()
	{
		if(--count == 0)
		{
			delete mPtr;
		}
	}
	T* mPtr;
	int count;
};

void duplicateUseShardPtr()
{
	MyShared_ptr<MyClass> shardPtr1(new MyClass());
	shardPtr1->Func(); //OK

	MyShared_ptr<MyClass> shardPtr2 = shardPtr1; //OK
    MyShared_ptr<MyClass> shardPtr3 = shardPtr1; //OK
	shardPtr1->Func(); //OK
	shardPtr2->Func(); //OK
    shardPtr3->Func(); //OK

    std::cout << "Use count of shared pointer is " << shardPtr1.get_refCount() << std::endl;
    std::cout << "Use count of shared pointer is " << shardPtr2.get_refCount() << std::endl;
    std::cout << "Use count of shared pointer is " << shardPtr3.get_refCount() << std::endl;
}

int main()
{
	duplicateUseAutoPtr();
	duplicateUseShardPtr();
}