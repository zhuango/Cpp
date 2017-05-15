#ifndef __PERSON_CPP__
#define __PEROSN_CPP__

#include<iostream>

Person:Person(const string &ln, const char *fn)
{
	lname = ln;
	for(int i = 0; i < LIMIT; i++){
		fname[i] = *(fn + i);
	}
}
