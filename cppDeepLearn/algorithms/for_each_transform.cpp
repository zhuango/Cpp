#include <algorithm>
#include <iostream>
#include <vector>
using std::vector;
using std::for_each;
using std::transform;
using std::cout;
using std::cin;
using std::endl;

int main(void)
{
    vector<int> vi;
    int i;
    while (cin >> i)
    {
        vi.push_back(i);
    }
    for_each(vi.begin(), vi.end(), [](int i) { cout << i << " ";});
    cout << endl;

    vector<int> orig = vi;
    
    // replace negative values by their absolute value
    transform(vi.begin(), vi.end(), vi.begin(),
              [](int i) { return i < 0 ? -i : i;});
    for_each(vi.begin(), vi.end(), [](int i){ cout << i << " ";});
    cout << endl;

    vi = orig;
    transform(vi.begin(), vi.end(), vi.begin(),
              [](int i) -> int
              {
                  if (i < 0)
                  {
                      return -i;
                  }
                  else
                  {
                      return i;
                  }
              });
    for_each(vi.begin(), vi.end(), [](int i){cout << i << " ";});
    cout << endl;
}