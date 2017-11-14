#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8};

    ostream_iterator<int> osIter(cout, " ");
    copy(vec.crbegin(), vec.crend(), osIter);
    cout << endl;

    string s = "liu,zhuang,kai,lizhang";
    auto f = find(s.crbegin(), s.crend(), ',');
    cout << string(s.crbegin(), f) << endl;
    cout << string(f.base(), s.cend()) << endl;
    return 0;
}