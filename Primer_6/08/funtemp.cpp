#include<iostream>
using namespace std;

template<typename T>
void print_(T a)
{
	cout << a << endl;
}

template<>
void print_<int>(int a)
{
	cout << a * a << endl;
}

int main()
{
	print_("Nima");
	print_(10);
	print_(1000);
	print_(19.12);
	
	std::string s = "LiuZhuang";
	print_(s);
	return 0;
}
