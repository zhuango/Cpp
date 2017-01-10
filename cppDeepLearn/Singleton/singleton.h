#ifndef _SINGLETON_H_
#define _SINGLETON_H_
#include<iostream>
using namespace std;
class MySingleton;
class Singleton{
	public:
		static Singleton *Instance();
		void setData(int d){data = d;}
		virtual void print(){cout << data << endl;}
	protected:
		Singleton(){data = 0;};

	private:
		int data;
		static Singleton *_instance;
};

class MySingleton : public Singleton{
	public:
		virtual void print(){cout << "NIMA" << endl;}

	private:
		int data;
};

#endif
