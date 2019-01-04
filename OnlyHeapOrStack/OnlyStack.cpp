
class OnlyStack
{
private:
	void* operator new(size_t size) {}
	void operator delete(void *pp) {}
};

int main()
{
	OnlyStack a;
	//OnlyStack* pb = new OnlyStack; //无法访问重载new和delete

	return 0;
}