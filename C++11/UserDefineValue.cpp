

struct Watt
{
	unsigned int v;
};

Watt operator"" _w(unsigned long long v)
{
	return (unsigned int)v;
}

int main(int argc, char const *argv[])
{
	Watt cap = 1024_w;

	return 0;
}