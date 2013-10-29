#ifndef _PLORG_H_
#define _PLORG_H_

#include<iostream>
#include<string.h>
using namespace std;

class Plorg{
	private:
		static const int LIMIT = 20;
		char name[LIMIT];
		int CI;

	public:
		Plorg()
		{
			strncpy(name, "Plorg", 5);
			name[5] = '\0';
			CI = 50;
		};

		Plorg(const char *n, int ci)
		{
			strncpy(name, n, strlen(n));
			name[strlen(n)] = '\0';
			CI = ci;
		}

		void setCI(int ci){CI = ci;}
		void report()
		{
			cout << "name: " << name << endl;
			cout << "CI  : " << CI << endl;
		}
};
#endif
