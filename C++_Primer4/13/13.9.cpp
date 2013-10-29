#include<iostream>
using namespace std;
#include "noname.h"

int main()
{
	NoName a;
	a.setString("LiuZhuang");
		
	NoName b;
	b = a;
	a.setStringChar(2, 'r');
	a.printString();
	b.printString();

	return 0;
}
