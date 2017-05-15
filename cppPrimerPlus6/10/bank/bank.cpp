#ifndef __BANK_CPP__
#define __BANK_CPP__

#include<iostream>
#include"bank.h"
using std::cout;
using std::endl;

void Bank::Print_info()
{
	cout << "Username : " << Username << endl;
	cout << "Number	  : " << Number << endl;
	cout << "Money    : " << Money << endl;
}

#endif
