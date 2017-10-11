#include <string>
using std::string;
#include <memory>
using std::unique_ptr;
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
    unique_ptr<string> p1(new string("Stegosaurus"));
    unique_ptr<string> p2(p1.release());
    cout << *p2 << endl;
    unique_ptr<string> p3(new string("Trex"));

    p2.reset(p3.release());
    cout << *p2 << endl;

    // p1 realease.
    if (p1)
    {
        cout << "p1 not null" << endl;
    }
    // p3 realease.
    if (p3)
    {
        cout << "p3 not null" << endl;
    }

    return 0;
}