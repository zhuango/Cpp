#ifndef _ABC_H_
#define _ABC_H_

#include<iostream>
using namespace std;

class Test{
	public:
		virtual void print()const = 0;
		void print_abc(){cout << "I'm abstract" << endl;}
		virtual void print_vir(){cout << "I'm virtual " << endl;}
	private:
		int data;
};

class Test2 : public Test{
	public:
		virtual void print()const { cout << "abc" << endl;}
		void print2(){cout << "Nima" << endl;}
		//virtual void print_vir(){cout << "I'm child vir" << endl;}

	private:
		int data;
};

#endif
