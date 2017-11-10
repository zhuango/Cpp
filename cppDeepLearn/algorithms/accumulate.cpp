#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(void)
{
    vector<int> vec({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    int sum = accumulate(vec.begin(), vec.end(), 0);
    cout << accumulate(vec.begin(), vec.end(), 0) << endl;

    sum = accumulate(vec.cbegin(), vec.cend(), 1.0);
    cout << accumulate(vec.cbegin(), vec.cend(), 1.0) << endl;
    return 0;
}