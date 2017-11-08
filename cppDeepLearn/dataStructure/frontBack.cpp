#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> vec = {1, 2, 3, 4, 5};
    // reference.
    cout << vec.front() << endl;
    cout << vec.back() << endl;

    vector<int> vec1;
    cout << vec1.front() << endl;
    cout << vec1.back() << endl;
    return 0;
}