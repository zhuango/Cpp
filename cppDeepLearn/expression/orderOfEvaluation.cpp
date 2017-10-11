#include <iostream>
using namespace std;


int a()
{
    cout << "a()" << endl;
    return 4;
}
int b()
{
    cout << "b()" << endl;
    return 2;
}

int main(void)
{
    int c = 100;
    c = b() * a();
    c = a() * b();

    cout << c << " " << ++c << " " << c << endl;
    return 0;
}
