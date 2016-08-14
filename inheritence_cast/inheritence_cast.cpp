#include <stdlib.h>
#include <iostream>

class base
{
public:
	base();

	base(const base& obj)
	{
		x = obj.x;
		std::cout << "base copy constructor" << std::endl;
	};

	base& operator=(const base& obj)
	{
		std::cout << "base assignment operator" << std::endl;
		if(this == &obj)
			return *this;

		x = obj.x;
		return *this;
	}

	virtual ~base() {};
	int x;
};

base::base()
	:x(1)
{
	std::cout << "base default constructor" << std::endl; 
};

class derived : public base
{
public:
	derived();

	derived(const derived& obj)
	{
		y = obj.y;
		std::cout << "derived copy constructor" << std::endl;
	};

	derived& operator=(const derived& obj)
	{
		std::cout << "derived assignment operator" << std::endl;
		if(this == &obj)
			return *this;

		y = obj.y;
		return *this;
	}

	int y;
};

derived::derived()
	:y(2)
{
	std::cout << "derived default constructor" << std::endl;
};

void printBaseType(base obj)
{
	std::cout << "print base object" << std::endl << std::endl;
}

void printBaseReference(const base& obj)
{
	std::cout << "print base object reference" << std::endl << std::endl;
}

int main()
{
	base* pBasePt2Base = new base;
	std::cout << "base pt points to base object has address " << pBasePt2Base << std::endl;
	derived* pDynCastBasePt2Base = dynamic_cast<derived*>(pBasePt2Base); //fail
	std::cout << "Dyn cast base pt points to base object has address " << pDynCastBasePt2Base << std::endl;
	derived* pStaticCastBasePt2Base = static_cast<derived*>(pBasePt2Base); //success but slice down
	std::cout << "Static cast base pt points to base object has address " << pStaticCastBasePt2Base << std::endl;
	std::cout << "Static cast base pt points to base object has x = " << pStaticCastBasePt2Base->x << " y = " << pStaticCastBasePt2Base->y << std::endl;
	delete pBasePt2Base;
	std::cout << std::endl;

	base* pBasePt2Derived = new derived;
	derived* pDynCastBasePt2Derived  = dynamic_cast<derived*>(pBasePt2Derived); //success
	std::cout << "base pt points to derived object has address " << pBasePt2Derived << std::endl;
	std::cout << "Dyn cast base pt points to derived object has address " << pDynCastBasePt2Derived << std::endl;
	std::cout << "Dyn cast base pt points to derived object has x = " << pDynCastBasePt2Derived->x << " y = " << pDynCastBasePt2Derived->y << std::endl;
	derived* pStaticCastBasePt2Derived = static_cast<derived*>(pBasePt2Derived); //success
	std::cout << "Static cast base pt points to derived object has address " << pStaticCastBasePt2Derived << std::endl;
	std::cout << "Static cast base pt points to derived object has x = " << pStaticCastBasePt2Derived->x << " y = " << pStaticCastBasePt2Derived->y << std::endl;
	delete pBasePt2Derived;
	std::cout << std::endl;

	derived* pDerivedPt2Derived = new derived;
	base* pDynCastBasedPt2Derived = dynamic_cast<base*>(pDerivedPt2Derived); //success
	std::cout << "derived pt points to derived object has address " << pDerivedPt2Derived << std::endl;
	std::cout << "Dyn cast derived pt points to derived object has address " << pDynCastBasedPt2Derived << std::endl;
	std::cout << "Dyn cast derived pt points to derived object has x = " << pDynCastBasedPt2Derived->x << std::endl;
	base* pStaticastDerivedPt2Derived = static_cast<base*>(pDerivedPt2Derived); //success
	std::cout << "Static cast derived pt points to derived object has address " << pStaticastDerivedPt2Derived << std::endl;
	std::cout << "Static cast derived pt points to derived object has x = " << pStaticastDerivedPt2Derived->x << std::endl;
	delete pDerivedPt2Derived;
	std::cout << std::endl;

	derived DerivedObj;
	printBaseType(DerivedObj);
	printBaseReference(DerivedObj);

	base BaseObj1(DerivedObj);
	
	base BaseObj2;
	BaseObj2 = DerivedObj;
}
