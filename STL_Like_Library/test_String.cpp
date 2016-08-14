#include <iostream>
#include "String.h"

int main()
{
	String str1("123");
	std::cout << str1[0] << str1[1] << str1[2] << str1[3] << std::endl;

	String str2(str1);
	std::cout << str2[0] << str2[1] << str2[2] << str2[3] << std::endl;

	String str3 = str1;
	std::cout << str3[0] << str3[1] << str3[2] << str3[3] << std::endl;
}