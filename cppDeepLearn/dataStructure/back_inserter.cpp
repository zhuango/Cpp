#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<int> vec0(10, 1);

// constructor
//     back_insert_iterator objects are constructed from a container, of which they keep a reference internally.
// operator=
//     Inserts a new element at the end of the container, initializing it with the argument.
// operator*
//     Does nothing. Returns a reference to the object.
// operator++
//     Does nothing. Returns a reference to the object.
    auto back_vec0 = back_inserter(vec0);
    back_vec0 = 10;
    for_each(vec0.begin(), vec0.end(), [](int a) { cout << a << " "; });
    cout << endl;

    back_insert_iterator< vector<int> > back_vec1(vec0);
    back_vec1 = 20;
    for_each(vec0.begin(), vec0.end(), [](int a) {cout << a << " ";});
    cout << endl;

    return 0;
}