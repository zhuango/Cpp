#include<iostream>
using std::cout;
using std::endl;

class time
{
	public:
		time(int h, int m, int s);
		friend void display(time &);
	private:
		int hour;
		int minu;
		int sec;
};

time::time(int h,int m,int s)
{
	hour = h;
	minu = m;
	sec = s;
}

void display(time &t)
{
	cout<<t.hour<<":"<<t.minu<<":"<<t.sec<<endl;
}

int main(void)
{
	time t1(10,13,56);
	display(t1);
	return 0;
}
