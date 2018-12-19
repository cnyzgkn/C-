#include <iostream>

struct Student
{
	bool gender;
	int age;
};

union T
{
	Student s;
	int a;
	char c[10];
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}