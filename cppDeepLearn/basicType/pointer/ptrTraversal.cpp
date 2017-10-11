#include <iterator>
using std::begin;
using std::endl;

#include <cstddef>
using std::size_t;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(void)
{
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *e = &ia[10];
    for(int *b = ia; b != e; ++b)
    {
        cout << *b << ' ';
    }
    cout << endl;

    const size_t sz = 10;
    int arr[sz];

    for (auto &n : arr)
    {
        cin >> n;
    }
    for (auto i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;

    int *pbeg = begin(arr);
    int *pend = end(arr);
    // find the negative element.
    while (pben != pend && *pbeg >= 0)
    {
        ++pbeg;
    }
    if (pbeg == peng)
    {
        cout << "no negative elements in arr" << endl;
    }
    else
    {
        cout << "first negative number was " << *pbeg << endl;
    }

    return 0;
}