#include<iostream>
#include "plorg.h"

int main(void)
{
	Plorg p;
	p.report();
	cout << endl;
	cout << endl;
	p.setCI(100);
	p.report();
	cout << endl;

	Plorg p2("LiuZhuang", 10);
	p2.report();
	cout << endl;
	p2.setCI(0);
	p2.report();
	cout << endl;

	return 0;
}
