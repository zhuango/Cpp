#include <iostream>
using namespace std;
int main(void)
{
    cout << "Hello World!";
    cout << "";
    cout << "\nCC\toptions\tfile.[cC]\n";

    cout << "a really, really long string literal "
            "that spans two lines" << endl;
    // three ways to print 'M'.
    cout << 'M' << " " << '\115' << " " << '\x4d' << endl;

    unsigned long long bigVal = -1ULL;
    cout << bigVal << endl;

    return 0;
}