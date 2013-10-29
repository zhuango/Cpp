#include<iostream>
#include"stock00.cpp"
int main()
{
	Stock Og;
	Og.acquire("NanoSmatr", 20, 12.50);
	Og.show();
	Og.buy(15, 18.125);
	Og.show();
	Og.sell(400, 20.00);
	Og.show();
	Og.buy(300000, 40.125);
	Og.show();
	Og.sell(300000, 0.125);
	Og.show();

	return 0;
}
