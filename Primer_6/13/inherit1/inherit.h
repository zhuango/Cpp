#ifndef _INHERIT_H_
#define _INHERIT_H_
#include<iostream>
using namespace std;

class Test{
	public:
		void print1(){cout << "Print 1" << endl;}
		void print2(){cout << "Print 2" << endl;}
		void print3(){cout << "Print 3" << endl;}
		virtual void print_v(){cout << "In parent virtual function" << endl;}
};

#endif
