#include<iostream>
using namespace std;
#include "layer.h"

int main(void)
{
	Test1 a;
	Test2 b;
	Test3 c;

	b.setLowerlayer(&a);
	c.setLowerlayer(&b);

	c.l3service();

	return 0;
}
