#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <iterator>
using std::istream_iterator;

int main(void)
{
    istream_iterator<int> initVec(cin), eof;
    vector<int> a(initVec, eof);
    for(auto i = a.crbegin(); i != a.crend(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
    return 0;
}