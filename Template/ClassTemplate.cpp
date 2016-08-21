#include <stdlib.h>
#include <iostream>
#include <string>

template<typename T> class Queue;

template<typename T> class QueueItem
{
	friend class Queue<T>;
private:
	QueueItem(const T& t) : mItem(t), next(NULL) {};
	T mItem;
	QueueItem* next;
};

template<typename T> class Queue
{
public:
	Queue() : head(NULL), tail(NULL) {};
	Queue(const Queue& queue) { copy_element(queue); };
	~Queue() { clear(); };
	Queue& operator=(const Queue& queue);
	T& front();
	const T& front() const;
	void push(const T&);
	void pop();
	bool empty() const { return head == NULL; };
	void copy_element(const Queue&);
	void clear();
	QueueItem<T>* Head() { return head; };

private:
	QueueItem<T>* head;
	QueueItem<T>* tail;
};

template<typename T> void Queue<T>::pop()
{
	if(head == NULL)
		return;

	QueueItem<T>* p = head;
	head = head->next;
	delete p;
}

template<typename T> void Queue<T>::push(const T& t)
{
	QueueItem<T>* pItem = new QueueItem<T>(t);

	if(head == NULL)
		head = tail = pItem;
	else
	{
		tail->next = pItem;
		tail = pItem;
	}
}

template<typename T> void Queue<T>::copy_element(const Queue<T>& queue)
{
	QueueItem<T>* pItem = queue.head;
	while(pItem != NULL)
	{
		push(pItem->mItem);
		pItem = pItem->next;
	}
}

template<typename T> Queue<T>& Queue<T>::operator=(const Queue<T>& queue)
{
	if(this == &queue)
		return this;

	copy_element(queue);

	return this;
}

template<typename T> void Queue<T>::clear()
{
	while(head != NULL)
		pop();
}

template<typename T> void printQueue(Queue<T> queue)
{
	QueueItem<T>* pItem = queue.Head();
	while(pItem != NULL)
	{
		std::cout << pItem->mItem << std::endl;
		pItem = pItem->next;
	}
	std::cout << std::endl;
}

int main()
{
	// string queue
	Queue<std::string> strQ;
	strQ.push("Alice");
	strQ.push("Bob");
	strQ.push("Cindy");
	strQ.push("Dream");
	printQueue(strQ);
	strQ.pop();
	strQ.pop();
	printQueue(strQ);
	strQ.clear();
	printQueue(strQ);

	// int queue
	Queue<int> intQ;
	intQ.push(10);
	intQ.push(20);
	intQ.push(30);
	intQ.push(40);
	intQ.push(50);
	printQueue(intQ);
	intQ.pop();
	intQ.pop();
	printQueue(intQ);
	intQ.clear();
	printQueue(intQ);

	return 1;
}
