#include <iostream>
#include <vector>
#include <algorithm>

// for back_inserter
#include <iterator>

using namespace std;

int main(void)
{
    vector<int> vec0({1, 2, 3, 4});
    fill(vec0.begin(), vec0.end(), 0);
    for(auto &a: vec0) {cout << a << " ";};
    cout << endl;

    fill_n(vec0.begin(), vec0.size(), 3);
    for(auto &a : vec0) { cout << a << " "; }
    cout << endl;

    back_insert_iterator<vector<int>> backInserter = back_inserter(vec0);
    fill_n(backInserter, 2, 12);
    for(auto &a : vec0) { cout << a << " "; }
    cout << endl;

    return 0;
}