#ifndef _EXPLICIT_H_
#define _EXPLICIT_H_

#include<iostream>
using namespace std;

class Test{
	public:
		explicit Test(){data = 10;}
		void print(){cout << data << endl;}
	private:
		int data;
};

class Test2{
	public:
		Test2(int data){d = data;}
		void print(){cout << d << endl;}
	private:
		int d;
};

class Test_p{
	public:
		void print(Test a){
			a.print();
		}
	private:
};
#endif
