#include<iostream>
#include"person.h"
using std::cout;
using std::endl;
using std::cin;

int main()
{
	Person p("LiuZhuang", "LiaoNing");
	cout << p.getName() << endl;
	cout << p.getAddr() << endl;

	return 0;
}
