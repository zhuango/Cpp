#include<iostream>
using namespace std;
class Test
{
	public:
		Test(){cout << "Test created" << endl;}
		~Test(){cout << "Test die" << endl;}
	private:
};

class Test2 : public Test
{
	public:
		Test2(){cout << "Test2 created" << endl;}
		~Test2(){cout << "Test2 die" << endl;}
	private:
};

int main(void)
{
	Test2 a;
	cout << endl << endl;

	Test *b = new Test2();
	cout << endl << endl;
	return 0;
};
