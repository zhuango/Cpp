#include<iostream>
#include "bank.h"
using std::cout;
using std::cin;
using std::endl;

int main(void)
{
	Bank *bank = new Bank();
	bank->Search();

	bank->Save(100);
	bank->Search();

	bank->Getout(90);
	bank->Search();

	bank->Getout(1000);
	bank->Search();
	return 0;
}
