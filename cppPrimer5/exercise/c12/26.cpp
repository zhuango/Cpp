#include <string>
#include <iostream>
#include <memory>

using namespace std;

int main(void)
{
    int n = 10;
    allocator<string> alloc;
    string *p = alloc.allocate(n);
    string *q = p;
    string s;
    while(cin >> s && q != p + n)
    {
        alloc.construct(q++, s);
    }
    const size_t size = q - p;
    cout << *p << endl;
    cout << *(p +1) << endl;
    while(q != p)
        alloc.destroy(--q);
    alloc.deallocate(p, n);
       
    return 0;
}