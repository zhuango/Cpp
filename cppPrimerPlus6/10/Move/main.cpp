#include<iostream>
#include "move.h"

int main(void)
{
	Move a;
	a.showmove();
	cout << endl;

	a.reset(100, 10);
	a.showmove();
	cout << endl;

	Move b(10, 10);
	b.showmove();
	cout << endl;

	Move c(b.add(a));
	c.showmove();

	cout << endl;
	a.showmove();

	cout << endl;
	b.showmove();
	return 0;
}
