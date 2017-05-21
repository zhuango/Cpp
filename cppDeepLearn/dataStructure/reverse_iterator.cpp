#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iterator>
using std::reverse_iterator;
using std::istream_iterator;
#include <vector>
using std::vector;

int main(void)
{
    istream_iterator<int> initVec(cin), eof;
    vector<int> vec(initVec, eof);
    
    // header -> 1 -> 2 -> 3;
    // minus i to rev_t mean that adds i-1 to vec.begin().
    vector<int>::reverse_iterator rev_it(vec.begin());
    cout << *(rev_it.base()) << endl;

    cout << *(vec.begin()) << endl;
    cout << *(rev_it - 1) << endl;
    cout << *(rev_it - 2) << endl;
    cout << *rev_it << endl;
    return 0;
}