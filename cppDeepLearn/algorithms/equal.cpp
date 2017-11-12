#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<int> vec0({0, 1, 2, 3, 4, 5, 6, 7});
    vector<int> vec1({0, 1, 2, 3, 4, 5, 6, 7, 8});
    vector<int> vec2({0, 1, 2, 3, 4, 5, 3, 7, 8});

    bool isEqual = equal(vec0.cbegin(), vec0.cend(), vec1.cbegin());
    cout << isEqual << endl;

    isEqual = equal(vec0.cbegin(), vec0.cend(), vec2.cbegin());
    cout << isEqual << endl;
    return 0;
}