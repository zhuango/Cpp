#include<iostream>
using namespace std;

int main()
{
	using namespace std;
	int chest = 42;
	int waist = 42;
	int inseam = 42;

	cout << "Monsieur cuts a strking figure!" << endl;
	cout << "chest = " << chest << " (decimal for 42)" << endl;
	cout << hex;
	cout << "waist = " << waist << " (hexdecimal for 42)" << endl;
	cout << oct;
	cout << "inseam = " << inseam << " (octl for 42)" << endl;

	return 0;
}
