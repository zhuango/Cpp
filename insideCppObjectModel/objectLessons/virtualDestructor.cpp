#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout << "construct A" << endl;
	}

	~A()
	{
		cout << "destruct A " << endl;
	}
};

class B : public A
{
public:
	B()
	{
		cout << "construct B" << endl;
	}

	~B()
	{
		cout << "destruct B" << endl;
	}
};

void testNonVirtualDestruct()
{
	A *b = new B();
	delete b;//destruct A only.
}

class EA
{
public:
	EA() { cout << "construct EA" << endl; }

	virtual ~EA() { cout << "destruct EA" << endl; }
};

class EB : public EA
{
public:
	EB() { cout << "construct EB" << endl; }

	~EB() { cout << "destruct EB" << endl; }
};

void testVirtualDestruct()
{
	EA *ea = new EB();
	delete ea;//destruct B firstly.Then destruct A
}