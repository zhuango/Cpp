#include<iostream>
#include "inherit.h"
#include "inherit2.h"
int main(void)
{
	Test2 *a = new Test2();
	a->print_child();
	a->print1();
	a->print2();
	a->print3();

	Test *b = new Test2();
	b->print_v();
	return 0;
}
