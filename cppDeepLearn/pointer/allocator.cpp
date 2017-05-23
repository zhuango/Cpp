#include <string>
#include <memory>
using std::allocator;
#include <cstddef>
using std::size_t;
#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
    const size_t n = 100;
    allocator<string> alloc;
    auto p = alloc.allocate(n);

    auto q = p;
    alloc.construct(q++);
    cout << "++++++++++" << *(q-1) << "++++++++++++++" << endl;

    alloc.construct(q++, 10, 'c');
    cout << "++++++++++" << *(q-1) << "++++++++++++++" << endl;

    alloc.construct(q++, "hi");
    cout << "++++++++++" << *(q-1) << "++++++++++++++" << endl;

    cout << *p << endl;
    while(q != p)
    {
        alloc.destroy(--q);
    }
    // Releases a block of storage previously allocated with member allocate and not yet released.
    alloc.deallocate(p, n);

    p = alloc.allocate(n);
    string s;
    q = p;
    ifstream in("storyDataFile");
    while (in >> s && q != p + n)
    {
        alloc.construct(q++, s);
    }
    size_t size = q - p;
    cout << "read " << size << " strings" << endl;

    for (q = p + size - 1; q != p; --q)
    {
        alloc.destroy(q);
    }
    alloc.deallocate(p, n);
    in.close();
    in.open("storyDataFile");
    p = new string[n];
    q = p;
    while(in >> s && q != p + n)
    {
        *q++ = s;
    }
    size = q - p;
	cout << "read " << size << " strings" << endl;

	delete[] p;  // p points to an array; must remember to use delete[]

    return 0;
}