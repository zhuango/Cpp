#ifndef _SINGLETON_CPP_
#define _SINGLETON_CPP_
#include<iostream>
#include"singleton.h"
using namespace std;

Singleton *Singleton::_instance = NULL;
Singleton *Singleton::Instance()
{
	if(_instance == NULL)
		_instance = new MySingleton();
	return _instance;
}

#endif
