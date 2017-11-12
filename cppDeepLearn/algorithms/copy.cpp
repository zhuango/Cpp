#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> vec0({1, 2, 3, 4, 5, 6, 7, 8, 9, 0});
    vector<int> vec1(10, 2);
    for(auto &a : vec1) { cout << a << " "; }
    cout << endl;

    copy(vec0.cbegin(), vec0.cend(), vec1.begin());

    for(auto &a : vec1) { cout << a << " "; }
    cout << endl;
    return 0;
}