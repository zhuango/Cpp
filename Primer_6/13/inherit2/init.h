#ifndef _INIT_H_
#define _INIT_H_
#include<iostream>
using namespace std;
class Test{
	public:
		Test():A(0), B(0), C(0){}
		Test(int a, int b, int c){A = a; B = b; C = c;}

		void printA(){cout << "Parent: " << A << endl;}
		void printB(){cout << "Parent: " << B << endl;}
		void printC(){cout << "Parent: " << C << endl;}
	private:
		int A;
		int B;
		int C;
};
class Test2: public Test{
	public:
		Test2(int d) { data = d;}
		Test2(int a, int b, int c, int d) : data(d), Test(a, b, c){}
		void printData() {cout << "Child: " << data << endl;}

	private:
		int data;
};

#endif
