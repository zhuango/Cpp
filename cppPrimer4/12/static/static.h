#ifndef STATIC_H_
#define STATIC_H_

class Test{
	private:
		int data;
		static int data2;
	public:
		Test() : data(0){}
		Test(int i) : data(i){}

		static void print(){std::cout << Test::data2 << std::endl;}
};

int Test::data2 = 100;
#endif
