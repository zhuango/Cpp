#include <memory>
using std::make_shared;
using std::shared_ptr;
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
    shared_ptr<int> foo = std::make_shared<int> (10);
    // same as :
    shared_ptr<int> foo2(new int(10));

    auto bar = make_shared<int> (20);

    cout << "*foo " << *foo << endl;
    cout << "*foo " << *foo2 << endl;
    cout << "*bar " << *bar << endl;
    return 0;
}