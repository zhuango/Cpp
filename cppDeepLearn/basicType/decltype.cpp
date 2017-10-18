#include <iostream>
using namespace std;
int main(void)
{
	const int ci =0, &cj = ci;
	decltype(ci) x = 0; // x has type const int
	decltype(cj) y = x; // y has type const int & and is bound to x.
	//decltype(cj) z;     // error: z is reference and must be initialize

	int i = 42, *p = &i, &r = i;
	decltype(r + 0) b; // addition yields and int; b is an (uninitialized) int
	//decltype(*p) c;// error: c is int & and must be initialized
	return 0;
}

