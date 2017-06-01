#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

int main(void)
{
    long long int lli = -90000000000000000LL;
    unsigned long long int ulli = -90000000000000000LL;
    cout << lli << endl;
    cout << ulli << endl;

    long long ll_min = LLONG_MIN;
    long long ll_max = LLONG_MAX;
    unsigned long long ull_max = ULLONG_MAX;

    cout << ll_min << endl;
    cout << ll_max << endl;
    cout << ull_max << endl;

    return 0;
}