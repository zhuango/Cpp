#include<iostream>
#include "init.h"

int main()
{
	Test2 *a = new Test2(1, 2, 3, 4);
	a->printA();
	a->printB();
	a->printC();
	a->printData();

	Test2 *b = new Test2(1000);
	b->printA();
	b->printB();
	b->printC();
	b->printData();
	
	Test &c = *a;
	c.printA();
	c.printB();
	c.printC();
	//c.printData();
	
	Test *d = new Test(*b);/* B is child */
	d->printA();
	d->printB();
	d->printC();

	return 0;
}
