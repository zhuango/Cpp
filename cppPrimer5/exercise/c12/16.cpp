#include <iostream>
#include <memory>

using namespace std;

int main(void)
{
    int *a = new int;
    unique_ptr<int> p(a);

    unique_ptr<int> p2= p;
    return 0;
}