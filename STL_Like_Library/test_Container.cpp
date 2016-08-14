#include <stdio.h>
#include <iostream>
#include "Container.h"

int main()
{
	String str1("123");
	String str2("456");
	String str3("789");

	std::cout << "str created" << std::endl;

	ListContainer strlist;
	strlist.push_back(&str1);
	strlist.push_back(&str2);
	strlist.push_back(&str3);

	std::cout << "str pushed to strList" << std::endl;

	Iterator strIter(strlist);
	String* str = NULL;
	while(str = strIter.next())
	{
		str->printSelf();
	}
    
    return 0;
}