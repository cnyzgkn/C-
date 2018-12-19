#include <unordered_map>
#include <iostream>
#include <thread>         // std::thread
#include <mutex>          // std::mutex

std::unordered_map<int, int> GenUnorderedMap(int n)
{
	std::unordered_map<int, int> map;
	for(int i = 0; i <= n; ++i)
	{
		map.insert(std::make_pair(i, i));
	}
	return map;
}

void printUnorderedMap(const std::unordered_map<int, int>& map)
{
	std::cout << "print map:" << std::endl;
	for(auto iter = map.begin(); iter != map.end(); ++iter)
	{
		
		std::cout << iter->second << std::endl;
	}
}

void main()
{
	const std::unordered_map<int, int> map = GenUnorderedMap(100);
	std::cout << "normal print:" << std::endl;
	printUnorderedMap(map);

	std::cout << "multi threading print:" << std::endl;
	std::mutex mtx;
	for(int i = 0; i < 10; ++i)
	{
		mtx.lock();
		printUnorderedMap(map);
		mtx.unlock();
	}
}