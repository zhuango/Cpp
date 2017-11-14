#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main(void)
{
    ostream_iterator<int> osIter(cout, " ");
    vector<int> vec({1, 2, 3,4, 5, 6, 7, 8, 9});
    for (auto &a : vec) { *osIter++ = a;};
    cout << endl;

    for (auto &a : vec) { *osIter = a;};
    cout << endl;

    for (auto &a : vec) { osIter = a;};
    cout << endl;

    copy(vec.cbegin(), vec.cend(), osIter);
    cout << endl;
    
    return 0;
}