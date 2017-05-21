#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    vector<int> myvector(10, 2);
    ostream_iterator<int> out_it(cout, ", ");
    copy(myvector.begin(), myvector.end(), out_it);
    cout << endl;
    (*out_it) = 100;
    out_it = 1000;
    
    return 0;
}