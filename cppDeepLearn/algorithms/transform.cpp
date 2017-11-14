#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<int> vec(12, -2);
    transform(vec.begin(), vec.end(), vec.begin(), [](int i) { return i < 0 ? -i : i;});
    
    for(auto & a: vec) { cout << a << " "; };
    cout << endl;

    transform(vec.begin(), vec.end(), vec.begin(), [](int i) { if (i < 0) return -i; else return i;});
    for(auto & a: vec) { cout << a << " "; };
    cout << endl;

    transform(vec.begin(), vec.end(), vec.begin(), [](int i) -> int{ if (i > 0) return -i; else return i;});
    for(auto & a: vec) { cout << a << " "; };
    cout << endl;

    return 0;
}