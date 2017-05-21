#include <algorithm>
using std::find_if;
using std::for_each;
using std::sort;
using std::stable_sort;
using std::unique;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <functional>
using std::bind;
using std::placeholders::_1;
using namespace std::placeholders;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iterator>
using std::istream_iterator;

int main(void)
{
    istream_iterator<int> initVec(cin), eof;
    vector<int> vec(initVec, eof);

    auto pointerTo = find_if(vec.begin(), vec.end(), [](int a) { return a < 0; });
    cout << *pointerTo << endl;

    return 0;

}
