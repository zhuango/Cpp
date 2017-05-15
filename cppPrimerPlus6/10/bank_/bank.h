#ifndef _BANK_H_
#define _BANK_H_
#include<iostream>
using namespace std;
typedef double MONEY;

class Bank{
	public:
		Bank() : money(0) {};
		Bank(MONEY m){money = m;}

		void Search(){cout << money << endl;}
		void Save(MONEY m) {
			money += m; 
		}
		void Getout(MONEY m) {
			money -= m;
			if(money < 0){
				cout << "can not do this" << endl;
				money += m;
			}
		}

	private:
		MONEY money;
};

#endif
