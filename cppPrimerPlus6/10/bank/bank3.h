#ifndef __BANK_H__
#define __BANK_H__
#include<iostream>
using std::string;
class Bank{
	private:
		string Username;
		string Number;
		double Money;
	public:
		Bank(string *username, string *number, double money){
			Username = *username;
			Number = *number;
			Money = money;
		}

		void Print_info();
		void Save_mon(double money){
			Money += money;
		}
		void Get_mon(double money){
			Money -= money;
		}
};
#endif
