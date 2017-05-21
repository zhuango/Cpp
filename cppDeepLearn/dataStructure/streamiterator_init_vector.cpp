#include <iterator>
#include <vector>
#include <iostream>
using namespace std;

int main(void)
{
    istream_iterator<int> in_iter(cin), eof;
    vector<int> vec(in_iter, eof);
    
    for(auto it : vec)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}