#ifndef _LINK_H_
#define _LINK_H_
#include<iostream>
using namespace std;

class Test{
	public:
		virtual void print(){cout << "Test" << endl;}
	private:
};

class Test2 : public Test{
	public:
		virtual void print(){cout << "Test2" << endl;}
	private:
};

class Test3 : public Test2{
	public:
		virtual void print(){cout << "Test3" << endl;}
	private:
};

class Test4 : public Test3{
	public:
//		virtual print(){cout << "Test4" << endl;}
	private:
};

#endif
