#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex

static int counter = 0;
std::mutex mtx;

void Increase_normal()
{
	for(int i = 0; i < 1000; ++i)
	{
		++counter;
		std::cout << "counter = " << counter << std::endl;
	}
}

void Increase_mutex_try_lock()
{
	for(int i = 0; i < 1000; ++i)
	{
		//if current mutex be locked by other thread, return fale intead of blocked
		if(mtx.try_lock())
		{
			++counter;
			std::cout << "counter = " << counter << std::endl;
			mtx.unlock();
		}
	}
}

void Increase_mutex_lock()
{
	for(int i = 0; i < 1000; ++i)
	{
		//protect the ++counter operation
		mtx.lock();
		++counter;
		std::cout << "counter = " << counter << std::endl;
		mtx.unlock();
	}
}

int main()
{
	std::thread threads[10];
	for(int i=0; i < 10; ++i)
	{
		threads[i] = std::thread(Increase_mutex_try_lock);
	}

	for(auto &thread: threads)
		thread.join();

	std::cout << counter << " successful increases of the counter.\n";

	counter = 0;

	return 0;
}