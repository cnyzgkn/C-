#include<iostream>
using namespace std;
 
struct V {
    virtual void f() {};  // must be polymorphic to use runtime-checked dynamic_cast
};

struct A : virtual V {};

struct B : virtual V {
  B(V* v, A* a) {
    // casts during construction
    dynamic_cast<B*>(v); // well-defined: v of type V*, V base of B, results in B*
    dynamic_cast<B*>(a); // undefined behavior: a has type A*, A not a base of B
  }
};

struct D : A, B {
    D() : B((A*)this, this) { }
};
 
struct Base {
    virtual ~Base() {}
};
 
struct Derived: Base {
    virtual void name() {}
};
 
struct Some {
    virtual ~Some() {}
};
 
int main(void)
{
	D d;
	A& a = d; //upcast  这里可以用dynamic_cast
	D& new_d = dynamic_cast<D&>(a);//downcast
	B& new_b = dynamic_cast<B&>(a);//sidecast
 
	Base* b1 = new Base;
	if(Derived* d = dynamic_cast<Derived*>(b1))
	{
		cout << "dynamic downcast from b1 to d succeful" << endl;
		d->name(); 
	}
    if(Derived* d = static_cast<Derived*>(b1))
	{
		cout << "static downcast from b1 to d succeful" << endl;
	}
 
 
	Base* b2 = new Derived;
	if(Derived* d = dynamic_cast<Derived*>(b2))
	{
		cout << "dynamic downcast from b2 to d successful" << endl;
		d->name();
	}
    if(Derived* d = static_cast<Derived*>(b2))
	{
		cout << "static downcast from b2 to d successful" << endl;
		d->name();
	}
 
	if(Some *d = dynamic_cast<Some*>(b1))
	{
		cout << "dynamic downcast from b1 to Some Successful" << endl;
	}
 
	delete b1;
	delete b2;
 
	return 0;

}