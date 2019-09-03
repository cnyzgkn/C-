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

class C
{
public:
	C(initializer_list<pair<string,int>> l, initializer_list<int> m, initializer_list<int> n)
	{
		cout << "C constructor " << endl;
		for(auto item : l)
		{
			data.push_back(item);
		}
		for(auto item : m)
		{
			idx.push_back(item);
		}
		for(auto item : n)
		{
			d.push_back(item);
		}
	}

	C& operator[](initializer_list<int> l)
	{
		cout << "C operator []" << endl;
		for(auto item : l)
		{
			idx.push_back(item);
		}
		return *this;
	}

	C& operator=(int v)
	{
		if (idx.empty() != true)
		{
			for (auto i = idx.begin(); i != idx.end(); ++i)
			{
				d.resize((*i > d.size()) ? *i : d.size());
				d[*i - 1] = v;
			}
			idx.clear();
		}
		return *this;
	}

	static void printInfo(initializer_list<int> l)
	{
		for(auto item : l)
		{
			cout << item << " ";
			cout << endl;
		}
	}


private:
	vector<pair<string,int>> data;
	vector<int> idx;
	vector<int> d;
};


int main(int argc, char const *argv[])
{
	map<int, double> curMap{{1, 2.0}, {2, 3.0}};

	Person people1[] = {{10, "male"}, {20, "female"}};

	fun({1, 2, 3});
	fun({}); //空列表

	C ctr{{{"s",1}, {"e",2}}, {3,4}, {5,6}};
	ctr[{2,3,4}] = 7;
	ctr[{1,3,4,5}] = 2;

	C::printInfo({1,2});
	C::printInfo({});
	
	return 0;
}