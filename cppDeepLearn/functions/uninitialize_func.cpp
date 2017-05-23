#include <iostream>
#include <vector>
#include <memory>
using std::uninitialized_copy;
using std::allocator;
using std::uninitialized_fill_n;

#include <cstddef>
using namespace std;

int main(void)
{
    vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};
    allocator<int> alloc;
    auto p = alloc.allocate(vi.size() * 2);
    // p               q
    // |||||||||||||||||||||||||||||||
    // Constructs copies of the elements in the range [first,last) into a range 
    // beginning at result and returns an iterator to the last element in the 
    // destination range.
    auto q = uninitialized_copy(vi.begin(), vi.end(), p);
    uninitialized_fill_n(q, vi.size(), 42);
    for (size_t i = 0; i != vi.size(); ++i)
    {
        cout << *(p + i) << " ";
    }
    cout << endl;

    for(size_t i = 0; i != vi.size(); ++i)
    {
        cout << *(q + i) << " ";
    }
    cout << endl;

    alloc.deallocate(p, vi.size());
    return 0;
}