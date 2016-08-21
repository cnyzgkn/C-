#include <stdio.h>
#include <iostream>
#include <thread>

void thread_task()
{
	std::cout << "Hello thread " << std::this_thread::get_id() << std::endl;
}

int main()
{
	std::thread t1; //t1 is not a thread
	std::thread t2(thread_task);
	//t1.join(); //error
	t2.join();

	std::thread t3(thread_task);
	std::thread t4(std::move(t3)); //t3 is not a thread any more
	//t3.join();
	t4.join(); 

	return 0;
}
