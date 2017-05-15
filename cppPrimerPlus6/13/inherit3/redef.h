#ifndef _REDEF_H_
#define _REDEF_H_
#include<iostream>
using namespace std;
class Test{
	public:
		Test(){cout << "Parent !" << endl;}
		virtual void print(){cout << "NiMei" << endl;}
		//~Test(){cout << "Parent die" << endl;}
		virtual ~Test(){cout << "Parent die" << endl;}
	private:
		int data;
};

class Test2: public Test{
	public:
		Test2(){cout << "Child !" << endl;}
		~Test2(){cout << "child die" << endl;}
		virtual void print(){cout << "Yo I'm child" << endl;}

	private:
		int data;
};

#endif
