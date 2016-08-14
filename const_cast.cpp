#include <stdlib.h>
#include <iostream>

//const_cast can only be used for pointer or reference
const int Int2ConstInt(int a)
{
	return const_cast<const int&>(a);
	//wrong: return const_cast<const int>(a);
}

int ConstInt2Int(const int a)
{
	return const_cast<int&>(a);
	//wrong: return const_cast<int>(a);
}

int main()
{
	const int a = Int2ConstInt(10);
	std::cout << a << std::endl;

	const int b = ConstInt2Int(10);
	std::cout << b << std::endl;

}