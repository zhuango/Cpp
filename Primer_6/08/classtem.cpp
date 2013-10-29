#include<iostream>
using namespace std;

//Class Template declaration
template<class T>
class Test{
	private:
		T a;
	public:
		Test(T arg) : a(arg){}
		void print_(){cout << a << endl;}
};

int main()
{
	Test<int> a(100);
	a.print_();

	Test<std::string> b("LiuZhuang");
	b.print_();

	return 0;
}
