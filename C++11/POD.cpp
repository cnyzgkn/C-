#include <string>
#include <iostream>

using namespace std;

struct A {
    int m;
};
 
struct B {
public:
    int m1;
private:
    int m2;
};

struct C {
    int m1;
    double m2;
};

struct D {
    int m1;
    double m2;
    int m3;
};
 
struct E {
    virtual void foo();
};

struct F {
	A a;
	B b;
	C c;
};

int main(int argc, char const *argv[])
{
	std::cout << std::boolalpha;
	std::cout << std::is_pod<int>::value << std::endl;
	std::cout << std::is_pod<double>::value << std::endl;
    std::cout << std::is_pod<A>::value << std::endl;
    std::cout << std::is_pod<B>::value << std::endl;
    std::cout << std::is_pod<C>::value << std::endl;
    std::cout << std::is_pod<D>::value << std::endl;
    std::cout << std::is_pod<E>::value << std::endl;
    std::cout << std::is_pod<F>::value << std::endl;

	return 0;
}