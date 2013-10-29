#include<iostream>
#include"explicit.h"

void print(Test &a)
{
	a.print();
}
int main()
{
	Test *a = new Test();
	a->print();

	Test2 b;
	print(b);
	return 0;
}
