#include<iostream>
using namespace std;

class Test
{
	public:
		virtual void print() const {cout << "nime" << endl;};
	private:
		int da;
};

class Test2 : public Test
{
	public:
		Test2(int d) : data(0){ data = d; }
		virtual void print() const {cout << "Test2" << endl;}

	private:
		int data;
};

class Test3: public Test
{
	public:
		Test3(int d) : data(0) {data = d;}
		virtual void print() const { cout << "Test3" << endl;}
	private:
		int data;
};

class Test4 : public Test
{
	public:
		Test4(int d) : data(10) {data = d; }
	private:
		int data;
};

int main()
{
	Test *self = new Test();
	self->print();

	Test *a = new Test2(10);
	a->print();
	
	Test *b = new Test3(10);
	b->print();

	Test *c = new Test4(10);
	c->print();

//	Test2 *d = new Test();
//	d->print();

	return 0;
}
