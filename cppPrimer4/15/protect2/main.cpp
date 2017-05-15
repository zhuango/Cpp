#include <iostream>
#include "protect.h"

int main()
{
	Test a;
	Test2 b;
	Test3 c;
	Test3 d;
	Test2 e;

	//c.print();//Error : Protected inherit, Parent public will be protected in derivative class
	d.use_print(c);//OK : User use the derivative class public

	//b.print();//Error : Private inherit, Parent public will be private in derivative class
	b.use_print(e);
	return 0;
}
