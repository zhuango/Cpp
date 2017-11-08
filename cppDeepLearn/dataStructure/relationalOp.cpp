#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    // • If both containers are the same size and all the elements are equal, then the
    // two containers are equal; otherwise, they are unequal.
    // • If the containers have different sizes but every element of the smaller one is
    // equal to the corresponding element of the larger one, then the smaller one is
    // less than the other.
    // • If neither container is an initial subsequence of the other, then the comparison
    // depends on comparing the first unequal elements.

    vector<int> v1 = {1, 3, 5, 7, 9, 10};
    vector<int> v2 = {1, 3, 9};
    vector<int> v3 = {1, 3, 5, 7};
    vector<int> v4 = {1, 3, 5, 7, 9, 12};

    cout << (v1 < v2) << endl;
    cout << (v1 < v3) << endl;

    cout << (v1 == v4) << endl;
    cout << (v1 == v2) << endl;
    return 0;
}