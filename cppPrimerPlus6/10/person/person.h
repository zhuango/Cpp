#ifndef __PERSON_H__
#define __PERSON_H__

#include<iostream>

class Persin{
	private:
		static const LIMIT = 25;
		string lname;
		char fname[LIMIT];
	public:
		Person(){lname = ""; fname[0] = '\0' }
		Person(const string &ln, const char *fn);

		void Show() const;
		void FormalShow() const;
};

#endif

