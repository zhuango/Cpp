#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<int> vec;
    vec.reserve(10);
    vec.reserve(5);
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;
    fill_n(vec.begin(), 10, 2);
    cout << vec.size() << endl;
    
    cout << vec[0] << endl;
    return 0;
}