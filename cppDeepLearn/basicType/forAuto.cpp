#include <iostream>
using namespace std;

int main(void)
{
	const string s = "Keep out!";
	for (auto c : s)
	{
		c = 's';
		cout << c << endl;
	}
	cout << s << endl;

	int i = 0;
	const int ci = 0;

	auto &n = i;
	n = 100;
	cout << i << " " << n << endl;
	
	auto *p2 = &ci;//&ci is const int &, p2 is const int *
	p2 = nullptr;
	
	auto &k = ci;
	//k = 10;//error: k is const int &
	
	return 0;
}
