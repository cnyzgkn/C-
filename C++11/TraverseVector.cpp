#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

//iterator
void test1()
{
	vector<int> vec(1000);
	vector<int>::const_iterator iter = vec.begin();
	while(iter++ != vec.end())
	{
		int n = *iter;
	}
}

// for loop C99
void test2()
{
	vector<int> vec(1000);
	for(int i = 0; i < vec.size(); i++)
	{
		int n = vec[i];
	}
}

// for loop C++ 11
void test3()
{
	vector<int> vec(1000);
	for(int i : vec)
	{
		int n = i;
	}
}

// auto C++ 11 iterator
void test4()
{
	vector<int> vec(1000);
	for(auto i = vec.begin(); i != vec.end(); i++)
	{
		int n = *i;
	}
}

// C++ 11 auto & for
void test5()
{
	vector<int> vec(1000);
	for(auto i : vec)
	{
		auto n = i;
	}
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();

	return 0;
}
