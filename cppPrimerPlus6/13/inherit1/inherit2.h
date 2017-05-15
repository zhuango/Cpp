#ifndef _INHERIT2_H_
#define _INHERIT2_H_
#include "inherit.h"
#include<iostream>

using namespace std;

class Test2: public Test{
	public:
		void print_child(){cout << "child" << endl;}
		void print1(){cout << "Print1(child class)" << endl;}
		virtual void print_v(){cout << "child print virtual" << endl;}
};

#endif
