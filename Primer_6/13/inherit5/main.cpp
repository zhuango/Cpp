#include<iostream>
#include "abc.h"

using namespace std;

int main()
{
	Test *a = new Test2();
	a->print();
	a->print_abc();

	Test &b(*a);
	b.print();
	b.print_abc();

	Test2 c;
	c.print();
	c.print_abc();
	c.print_vir();
	return 0;
}
