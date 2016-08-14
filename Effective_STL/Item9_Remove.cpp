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

int main()
{
	removeVectorWrong();
	removeVector();
	removeList();
}