#include <stdlib.h>
#include <iostream>

template<typename T> class Queue
{
public:
	Queue(T data);
	~Queue();

private:
	T mData;
};