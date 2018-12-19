#include <iostream>

using namespace std;

struct A
{
	virtual void func1()
	{
		cout << "A func1" << endl;
	};

	virtual void func2(){
		cout << "A func2" << endl;
	};
};


struct B : A
{
	void func1() override
	{
		cout << "B func1" << endl;
	}

	void func2() final
	{
		cout << "B func2" << endl;
	}
};

struct C final : B
{
	void func1() override
	{
		cout << "C func1" << endl;
	}

	/*
	void func2()  //error
	{
		cout << "C func2" << endl; 
	}
	*/
};

/*
struct D : C{

};
*/

int main(int argc, char const *argv[])
{
	A a;
	a.func1();
	a.func2();

	B b;
	b.func1();
	b.func2();

	C c;
	c.func1();
	//c.func2(); //error


	return 0;
}