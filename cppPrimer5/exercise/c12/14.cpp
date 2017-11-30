#include <iostream>
#include <memory>

using namespace std;

void dispose(int *a)
{
    cout << "dispose " << *a << endl;
    delete a;
}

int main(void)
{
    int *init = new int;
    *init = 10;
    shared_ptr<int> p(init, dispose);

    int *init1 = new int;
    *init1 = 100;
    shared_ptr<int> p1(init1, [](int *a){cout << "dispose " << *a << endl; delete a;});
    return 0;
}