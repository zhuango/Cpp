#include<iostream>
#include "redef.h"

int main(void)
{
	Test2 *a = new Test2();
	a->print();
	cout << "+++++++++++++++++++++++++++++++" << endl;
	Test *b = new Test2();
	b->print();
	cout << "+++++++++++++++++++++++++++++++" << endl;
	
	delete a;
	cout << "_______________________________" << endl;
	delete b;
//	cout << "Use project: _________________________" << endl;

	//Test2 c(*a);
	//c.print();

//	Test d;
//	d.print();

	return 0;
}
