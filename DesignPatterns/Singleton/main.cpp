#include<iostream>
#include"singleton.h"
using namespace std;

int main()
{
//	Singleton sdf;
	MySingleton sfda;
	sfda.print();

	Singleton *a = Singleton::Instance();
	a->print();

	a->setData(1000);
	a->print();

	Singleton *b = Singleton::Instance();
	b->print();

	return 0;
}
