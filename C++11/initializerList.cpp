#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <initializer_list>

using namespace std;

struct Person
{
	int age;
	string gender;
};

void fun(initializer_list<int> argv) //C++11唯一防止类型变窄的方式(编译器自动检查)
{
	for(auto itr = argv.begin(); itr != argv.end(); ++itr)
	{
		cout << *itr << endl;
	}
}


int main(int argc, char const *argv[])
{
	map<int, double> curMap{{1, 2.0}, {2, 3.0}};

	Person people1[] = {{10, "male"}, {20, "female"}};

	fun({1, 2, 3});
	fun({}); //空列表
	
	return 0;
}