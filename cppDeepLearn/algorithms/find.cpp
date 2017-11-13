#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(void)
{
    vector<int> vec;
    vec.push_back(32);
    vec.push_back(42);
    vec.push_back(44);
    int val = 42;
    auto result = find(vec.cbegin(), vec.cend(), val);
    cout << "The value " << val
         << (result == vec.cend() ? " is not present" : " is present") << endl;

    int ia[] = {27, 210, 12, 47, 109, 83};
    int val2 = 83;
    int * result1 = find(begin(ia), end(ia), val2);
    cout << *result1 << endl;
    int * result2 = find(ia + 1, ia + 4, val2);
    cout << *result2 << endl;

    return 0;
}