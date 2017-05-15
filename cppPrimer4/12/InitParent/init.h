#ifndef _INIT_H_
#define _INTI_H_

class Test{
	private:
		int data;
	public:
		Test(int d) : data(d){}
		void print(){std::cout << "data = " << data << std::endl;}
};

class Test2 : public Test{
	private:
		int data;
	public:
		Test2() : Test(19), data(0){}
		void printc(){std::cout << "data(in child) = " << data << std::endl;}
};


#endif
