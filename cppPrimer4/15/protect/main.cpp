#include <iostream>
#include "protect.h"

int main()
{
	Test a;
	Test2 b;
	Test2 c;

	a.print();/* OK: Base class object visit Public */
//	a.print_pro();//Error: Parent class object visit Parent class protecetd
	b.print_child();//OK: derivative class object visit derivative public
	b.print_prot(c, a);//OK: derivetive class object visit Parent protecetd by visiting derivative class public
//	b.print_pro();//Error: visit parent class protected Directly(You should visit it in derivative class public

	return 0;
}
