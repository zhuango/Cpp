#include <iostream>
extern const int bufSize;
using namespace std;
int main(void)
{
    std::cout << &bufSize << std::endl;
    std::cout << bufSize << std::endl;
    int cnt = 0;
    const int sz = cnt;
    cout << sz << endl;

    const int ci = 1;
    const int *rci = &ci;
    // rci = 100;//error
    // int &noconst_r_ci = ci;

    //const int &const i = 100;
    //const int c, &ic = c;
    //int null = 0, *p = null;
    //constexpr int const *p = &ci;
}