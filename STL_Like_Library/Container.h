#include <stdio.h>
#include "String.h"
#include "Geom.h"

class Container
{
public:
	Container();
	Container(void*);
	Container* next() {return mNext;};
	void setNext(Container*);
	Container* prev() {return mPrev;};
	void setPrev(Container*);
	void* node() const {return mNode;};
	void setNode(void*);
	operator String*() {return (String*)mNode;};
	operator Point2d*() {return (Point2d*)mNode;};
	operator Line2d*() {return (Line2d*)mNode;};

private:
	friend class ListContainer;
	friend class Iterator;

	void* mNode;
	Container* mNext;
	Container* mPrev;
};

Container::Container()
    :mNode(NULL), mNext(NULL), mPrev(NULL)
{
}

Container::Container(void* n)
	: mNode(n), mNext(NULL), mPrev(NULL)
{
}

void Container::setNext(Container* n)
{
	mNext = n;
}

void Container::setPrev(Container* n)
{
	mPrev = n;
}

void Container::setNode(void* n)
{
	mNode = n;
}

class ListContainer
{
public:
	ListContainer();
	~ListContainer();
	void push_back(void*);
	Container* pop();
	void clear();
	Container* first() {return mFirst;};
	Container* last() {return mLast;};

private:
	friend class Iterator;
	Container* mFirst;
	Container* mLast;
};

ListContainer::ListContainer()
    :mFirst(NULL), mLast(NULL)
{
}

ListContainer::~ListContainer()
{
	clear();
}

void ListContainer::push_back(void* p)
{
	if(p == NULL)
		return;

	Container* con = new Container(p);
	if(mFirst == NULL) //empty
	{
		mFirst = mLast = con;
		con->mNext = NULL;
		con->mPrev = NULL;
	}else if(mFirst == mLast) //only one element
	{
		mFirst->mNext = con;
		mLast = con;
		con->mPrev = mFirst;
		con->mNext = NULL;
	}else
	{
		mLast->mNext = con;
		con->mPrev = mLast;
		con->mNext = NULL;
		mLast = con;
	}
}

Container* ListContainer::pop()
{
	Container* p = mLast;
	mLast = mLast->mPrev;
	mLast->mNext = NULL;
	p->mPrev = NULL;
    return p;
}

void ListContainer::clear()
{
	Container* p = mLast;
	while(p->mPrev != NULL)
	{
		p->mPrev = p;
	}
}

class Iterator
{
public:
	Iterator();
	Iterator(ListContainer&);
	Iterator(Iterator&);
	Container next();
	Container prev();
	Iterator& operator=(ListContainer&);

private:
	Container* mCurrent;
	ListContainer* mListContainer;
};

Iterator::Iterator()
{	
}

Iterator::Iterator(ListContainer& list)
	: mCurrent(list.mFirst), mListContainer(&list)
{
}

Iterator::Iterator(Iterator& iter)
	: mCurrent(iter.mCurrent), mListContainer(iter.mListContainer)
{
}

Container Iterator::next()
{
	if(!mCurrent)
		return Container(NULL);

	Container* next = mCurrent;
	mCurrent = mCurrent->mNext;
    return *next;
}

Container Iterator::prev()
{
	return mCurrent->mPrev;
}

Iterator& Iterator::operator=(ListContainer& list)
{
	mCurrent = list.mFirst;
	mListContainer = &list;

	return *this;
}