#ifndef CONST_STATIC_H_
#define CONST_STATIC_H_

class Test{
	private:
		int data;
		const static int data2;
	public:
		Test() : data(100){}
		Test(int d) : data(d){}
		void print(){cout << Test::data2 << endl;}
};
const int Test::data2 = 10;

#endif
