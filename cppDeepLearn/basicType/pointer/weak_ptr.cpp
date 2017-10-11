#include <memory>
using std::weak_ptr;
using std::shared_ptr;
#include <iostream>
using namespace std;

int main(void)
{
    auto p = make_shared<int>(42);
    // creating wp doesn’t change the reference count of p;
    weak_ptr<int> wp(p);
    // error! weak_ptr object has no operator *, i.e. we cannot use a weak_ptr object directly.
    // cout << *wp << endl;
    // Because the object might no longer exist, we cannot 
    // use a weak_ptr to access its object directly.
    // we don’t affect the lifetime of object.
    // However, we can prevent the user from attempting to access a object that no longer exists.
    shared_ptr<int> sp = wp.lock();
    if (sp)
    {
        cout << "still exist." << endl;
    }
    else
    {
        cout << "pointer has been deleted." << endl;
    }

}