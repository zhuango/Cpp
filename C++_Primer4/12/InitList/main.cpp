#include<iostream>
#include<fstream>
#include "init.h"
using std::cout;
using std::endl;
int main()
{
	std::ifstream in;
	in.open("test");

	Test A(in);
	A.print();

	return 0;
}
