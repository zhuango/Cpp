// Keep in mind these facts about range-based for:
// Automatically recognizes arrays.
// Recognizes containers that have .begin() and .end().
// Uses argument-dependent lookup begin() and end() for anything else.
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(int y : x)
    {
        cout << y << " ";
    }
    cout << endl;

    for (auto y : x)
    {
        cout << y << " ";
    }
    cout << endl;

    for (auto &y :x)
    {
        cout << y << " ";
    }
    cout << endl;

    for (const auto y: x)
    {
        cout << y << " ";
    }
    cout << endl;
    cout << "end of object that contains 10 elements.";
    cout << endl;

    vector<double> v;
    for(int i = 0; i < 10; i++)
    {
        v.push_back(i + 0.14159);
    }
    for (const auto &j:v)
    {
        cout << j << " ";
    }
    cout << endl;
    cout << "end of vector test." << endl;

    return 0;
}