#include<iostream>
#include "cast.h"

int main()
{
	First a;
	Second b;
	a.print();
	b.print();

	First c = static_cast<const First> b;
	c.print();

	return 0;
}
