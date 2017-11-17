#include <memory>
#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    shared_ptr<int> p1;
    shared_ptr<list<int>> p2;

    shared_ptr<int> pp = make_shared<int>(23);
    if (pp)
    {
        cout << *pp << endl;
    }

    list<int> ll({1, 2, 3, 4, 5});
    shared_ptr<list<int>> plist = make_shared<list<int>>(5, 4);
    for(auto &a : *plist)
    {
        cout << a << endl;
    }
    return 0;
}