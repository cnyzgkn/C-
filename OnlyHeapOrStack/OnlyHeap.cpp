
class OnlyHeap
{
private:
	~OnlyHeap() {};

public:
	void destroy()
	{
		delete this;
	}
};

int main()
{
	//OnlyHeap a;  //stack上的对象自动析构时无法调用private析构函数
	
	OnlyHeap* pb = new OnlyHeap;
	pb->destroy();

	return 0;
}