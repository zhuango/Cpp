#include<iostream>
#include"this.h"

int main()
{
	A a;
	A b(a.getSelf());
	b.print_data();
	return 0;

}
