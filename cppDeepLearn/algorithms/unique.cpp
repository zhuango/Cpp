#include <algorithm>
using std::unique;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <iterator>
using std::istream_iterator;

int main(void)
{
    istream_iterator<int> initVec(cin), eof;
    vector<int> vec(initVec, eof);
    sort(vec.begin(), vec.end());
    auto pointerToDup = unique(vec.begin(), vec.end());
    for_each(vec.begin(), vec.end(), [](int a) { cout << a << " "; });
    cout << endl;
    vec.erase(pointerToDup, vec.end());
    for_each(vec.begin(), vec.end(), [](int a) { cout << a << " "; });
    cout << endl;
    return 0;
}