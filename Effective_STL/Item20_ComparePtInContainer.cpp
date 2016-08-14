#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void ComparePtsWrong()
{
	vector<string*> strVec;
	strVec.push_back(new string("Randy"));
	strVec.push_back(new string("Leo"));
	strVec.push_back(new string("Alice"));
	strVec.push_back(new string("Bob"));

	sort(strVec.begin(), strVec.end(), less<string*>());

	for(vector<string*>::const_iterator iter = strVec.begin(); 
		iter != strVec.end(); iter++)
	{
		cout << **iter << endl;
	}
}

bool strPtLess(const string* str1, const string * str2)
{
	return *str1 < *str2;
}

void ComparePtsUsingFunctionPt()
{
	vector<string*> strVec;
	strVec.push_back(new string("Randy"));
	strVec.push_back(new string("Leo"));
	strVec.push_back(new string("Alice"));
	strVec.push_back(new string("Bob"));

	sort(strVec.begin(), strVec.end(), strPtLess);

	for(vector<string*>::const_iterator iter = strVec.begin(); 
		iter != strVec.end(); iter++)
	{
		cout << **iter << endl;
	}
}

struct strPtLessFunctor{
public:
	bool operator()(const string* str1, const string * str2) const
	{
		return *str1 < *str2;
	}
};

void ComparePtsUsingFuctor()
{
	vector<string*> strVec;
	strVec.push_back(new string("Randy"));
	strVec.push_back(new string("Leo"));
	strVec.push_back(new string("Alice"));
	strVec.push_back(new string("Bob"));

	sort(strVec.begin(), strVec.end(), strPtLessFunctor());

	for(vector<string*>::const_iterator iter = strVec.begin(); 
		iter != strVec.end(); iter++)
	{
		cout << **iter << endl;
	}
}

int main()
{
	ComparePtsWrong();
	ComparePtsUsingFunctionPt();
	ComparePtsUsingFuctor();

	return 1;
}