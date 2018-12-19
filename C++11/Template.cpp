
void DefFunc1(int val = 3) {};

template<typename T>
	class DefClassCPP08 {
	public:
		DefClassCPP08(const T& val) : m_val(val) {};
		T m_val;
	};

template<typename T = int>
	class DefClassCPP11 {
	public:
		DefClassCPP11(const T& val) : m_val(val) {};
		T m_val;
	};

template<typename T = int>
	void DefFunc2() {};

int main(int argc, char const *argv[])
{
	DefClassCPP08<int> a(1);
	DefClassCPP11<int> b(2);
	return 0;
}