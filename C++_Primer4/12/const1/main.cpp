#include<iostream>
#include"const.h"

int main()
{
	Test a(10);
	a.display.set(10);//Error for doing set for a const Object
	a.display();
	a.set(100);
	a.display();
	return 0;
}
