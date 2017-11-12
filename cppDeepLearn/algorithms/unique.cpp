#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<int> vec({213, 65, 2, 354, 2, 8, 987, 8});
    sort(vec.begin(), vec.end());
    for(auto & a : vec) { cout << a << " "; }
    cout << endl;

    vector<int>::iterator end_unique = unique(vec.begin(), vec.end());
    for(auto & a : vec) { cout << a << " "; }
    cout << endl;
    vec.erase(end_unique, vec.end());
    for(auto & a : vec) { cout << a << " "; }
    cout << endl;

    cout << endl;
    return 0;
}