#include <iostream>
using namespace std;
int main(void)
{
    int i = 0, &r1 = i;
    double d = 0, &r2 = d;
    int i2 = (1, 2, 3);
    cout << i2 << endl;
    return 0;
}