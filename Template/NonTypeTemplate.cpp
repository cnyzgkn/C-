#include <stdlib.h>
#include <iostream>

template<typename T, int N> void initArray(T (&parm)[N])
{
	for(int i = 0; i < N; i++)
		parm[i] = 0;
}

int main()
{
	int a[10];
	double b[20];

	initArray(a);
	initArray(b);
	
	return 1;
}