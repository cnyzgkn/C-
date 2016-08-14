#include <stdlib.h>
#include <iostream>

using namespace std;

class Base {
public:
	virtual void mf1() = 0;
	virtual void mf1(int) {cout << "Base::mf1 int" << endl;};
	virtual void mf2() {cout << "Base::mf2 void" << endl;};
	void mf3() {cout << "Base::mf3 void" << endl;};
	void mf3(int) {cout << "Base::mf3 int" << endl;};
	virtual ~Base() {};
};
 
class Derived: public Base {
public:
	//using Base::mf1;
	//using Base::mf3;
	void mf1() {cout << "Derived::mf1 void" << endl;};
	void mf2() {cout << "Derived::mf2 void" << endl;};
	void mf3() {cout << "Derived::mf3 void" << endl;};
};

int main()
{
	cout << "A is Base object points to Derived pointer" << endl;
	Base* A = new Derived();
	A->mf1();
	A->mf1(1);
	A->mf2();
	A->mf3();
	A->mf3(1);
	delete A;

	cout << "B is Derived object points to Derived pointer" << endl;
	Derived* B = new Derived();
	B->mf1();
	B->Base::mf1(1);
	B->mf2();
	B->mf3();
	B->Base::mf3(1);
	delete B;

	return 1;
}