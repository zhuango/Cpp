#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> vec0({1, 1, 2, 2, 3, 4, 4, 5, 4, 4, 5});
    replace(vec0.begin(), vec0.end(), 4, 100);
    for(auto & a : vec0) { cout << a << " "; }
    cout << endl;
    
    vector<int> vec1;
    replace_copy(vec0.begin(), vec0.end(), back_inserter(vec1), 4, 100);
    for(auto & a : vec0) { cout << a << " "; }
    cout << endl;
    
    return 0;
}