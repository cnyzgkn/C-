#include <iostream>
#include <string>

using namespace std;

struct A
{
	operator int() const { 
		return 100;
	}

	explicit operator string() {
		return "explicit!";
	}

	operator wstring() {
		return L"implict!";
	}
};

void func(int) {}

int main(int argc, char const *argv[])
{
	A a1;
	A a2;
	A a3;
	func(a1);
	func(a2);

	int sum = a1 + a2;
	cout << "a1 + a2 == " << sum << endl;

	int i = a3;
	cout << "i == " << i << endl;

	
	string s = a3;
	cout << "string == " << s << endl;
	

	wstring ws = a3;
	cout << "wtring == " << ws << endl;

	return 0;
}