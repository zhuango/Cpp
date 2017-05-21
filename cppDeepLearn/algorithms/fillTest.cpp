#include <iostream>
#include <algorithm>
#include <vector>

#include <numeric>

using namespace std;

int main(void)
{
    vector<int> vec(10);
    fill(vec.begin(), vec.end(), 1);
    for_each(vec.begin(), vec.end(), [](int i){cout << i << " ";});
    cout << endl;

    // vec.cbegin() return pointer that point to a const content.
    int sum = accumulate(vec.cbegin(), vec.cend(), 3);
    cout << sum << endl;

    fill(vec.begin(), vec.begin() + vec.size() / 2, 10);
    cout << accumulate(vec.begin(), vec.end(), 0) << endl;
    
    fill_n(vec.begin(), vec.size() / 2, 0);
    cout << accumulate(vec.begin(), vec.end(), 0) << endl;
 
    fill_n(back_inserter(vec), 10, 42);
    cout << accumulate(vec.begin(), vec.end(), 0) << endl;

    vector<string> v;
    string s;
    while (cin >> s)
    {
        v.push_back(s);
    }
    string concat = accumulate(v.cbegin(), v.cend(), string("[Start]"));
    cout << concat << endl;
    return 0;
}