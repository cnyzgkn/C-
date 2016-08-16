#include <stdio.h>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

void removeVectorWrong()
{
	vector<int> vec;
	for(int i=0; i < 5; i++)
		vec.push_back(i);
	remove(vec.begin(), vec.end(), 3);
	for(int i=0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
	for(int i=0; i < vec.capacity(); i++)
		cout << vec[i] << " ";
	cout << endl;
}

void removeVector()
{
	vector<int> vec;
	for(int i=0; i < 5; i++)
		vec.push_back(i);
	vec.erase(remove(vec.begin(), vec.end(), 3), vec.end());
	for(int i=0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
	for(int i=0; i < vec.capacity(); i++)
		cout << vec[i] << " ";
	cout << endl;
}

void removeList()
{
	list<int> List;
	int i = 0;
	for(int i=0; i < 5; i++)
		List.push_back(i);
	List.remove(3);
	while(!List.empty())
	{
		cout << List.back() << " ";
		List.pop_back();
	}
	cout << endl;
}

void insertVectorWrong()
{
	vector<int> vec;
	for(int i=0; i < 5; i++)
		vec.push_back(i);
	for(int i=0; i < vec.size(); i++)
		cout << vec[i] << " ";
	//insert 6 between 3 and 4
	vector<int>::iterator iter = vec.begin();
	while(iter != vec.end())
	{
		if(*iter == 4)
			vec.insert(iter, 6);
		iter++;
	}
	for(int i=0; i < vec.size(); i++)
		cout << vec[i] << " ";
}

void insertVector()
{
	vector<int> vec;
	for(int i=0; i < 5; i++)
		vec.push_back(i);
	for(int i=0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
	//insert 6 between 3 and 4
	vector<int>::iterator iter = vec.begin();
	while(iter != vec.end())
	{
		if(*iter == 4)
			iter = vec.insert(iter, 6);
		iter+=2;
	}
	for(int i=0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}


int main()
{
	removeVectorWrong();
	removeVector();
	removeList();
	//insertVectorWrong();
	insertVector();
}