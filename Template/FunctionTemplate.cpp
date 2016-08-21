#include <stdlib.h>
#include <iostream>

template<typename T> bool smaller(const T a, const T b)
{
	return a < b;
}

template<class T> bool bigger(const T a, const T b)
{
	return a > b;
}

//template specialization
template <> bool smaller<const char*>(const char* const &a, const char* const &b)
{
	return strcmp(a,b);
}

int main()
{
	std::cout << smaller(1, 2) << std::endl;
	std::cout << smaller(1.0, 2.0) << std::endl;
	std::cout << smaller("Bob", "Alice") << std::endl;

	std::cout << bigger(1, 2) << std::endl;
	std::cout << bigger(1.0, 2.0) << std::endl;
	std::cout << bigger("Alice", "Bob") << std::endl;
}