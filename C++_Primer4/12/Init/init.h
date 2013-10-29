#ifndef _INIT_H_
#define _INIT_H_

class Test{
	public:
		Test(int i);
		void print(){
			std::cout << "a = " << a << std::endl
				<< "b = " << b << std::endl
				<< "c = " << c << std::endl;
		}
	private:
		int a;
		const int b;
		const int &c;
};

Test::Test(int i):b(10), c(100)
{
	a = i;//OK
//	b = i;//Error
//	c = i;//Error
}

#endif
