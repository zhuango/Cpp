#ifndef _MOVE_H_
#define _MOVE_H_
#include<iostream>
using namespace std;
class Move{
	private:
		double x;
		double y;
	public:
		Move(double a = 0, double b = 0);
		void showmove()const;
		Move add(const Move &m) const;
		double getX()const {return x;}
		double getY()const {return y;}
		void reset(double a = 0, double b = 0);
};

Move::Move(double a, double b)
{
	x = a;
	y = b;
}

void Move::showmove() const
{
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
}

Move Move::add(const Move &m) const
{
	Move *New = new Move(x + m.getX(), y + m.getY());
	return (*New);
}

void Move::reset(double a, double b)
{
	x = a;
	y = b;
}

#endif
