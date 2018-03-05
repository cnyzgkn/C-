#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class Int
{
public:
	void printSelf() { cout << "Int" << endl; }
};

//iterator in while loop
void loop1()
{
	cout << "loop1" << endl;
	vector<Int> vec(10);
	auto iter = vec.begin();
	while(iter++ != vec.end())
	{
		iter->printSelf();
	}
}

//iterator in for loop
void loop2()
{
	cout << "loop2" << endl;
	vector<Int> vec(10);
	for(auto iter : vec)
	{
		iter.printSelf();
	}
}

//iterator reference in for loop. You can change the content of the iterator
void loop3()
{
	cout << "loop2" << endl;
	vector<Int> vec(10);
	for(auto& iter : vec)
	{
		iter.printSelf();
	}
}

//return value
template <typename T1, typename T2>  
auto compose(T1 t1, T2 t2) -> decltype(t1 + t2)  
{  
   return t1+t2;  
}  

int main()
{
	loop1();
	loop2();
	loop3();
	auto v = compose(2, 3.14); // v's type is double  
	cout << "v = " << v << endl;
	return 0;
}
