#include <iostream>
#include <cstddef>
using std::size_t;

using namespace std;

int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main(void)
{
    constexpr size_t sz = sizeof(ia) / sizeof(*ia);
    int arr2[sz];

    cout << "ia size: " << sz << endl;

    return 0;
}
