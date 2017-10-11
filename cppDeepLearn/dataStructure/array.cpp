#include <iostream>
using namespace std;

int main(void)
{
    constexpr unsigned int a = 100;
    cout << a << endl;
    // a = 200;
    // cout << a << endl;

    int arraya[a];
    cout << sizeof(arraya) << endl;
    cout << &arraya << endl;
    cout << arraya << endl;

    const unsigned sz = 3;
    int ia1[sz] = {0, 1, 2};
    int a2[] = {0, 1, 2};
    int a3[5] = {0, 1, 2};
    string a4[3] = {"Hi", "bye"};
    //int a5[2] = {0,1,2};//error

    char hasnull[] = "C++";
    cout << sizeof(hasnull) << endl;
    cout << hasnull << endl;

    char hasNoNull[] = {'C', '+', '+'};
    cout << sizeof(hasNoNull) << endl;
    cout << hasNoNull << endl;

    int arr[10];

    int *ptrs[10]; // an array that has 10 elements which are int pointer.
    //int &refs[10]; // error: no arrays of reference, array holds object, reference is not object.
    int (*Parray)[10] = &arr;// a pointer that points an array that holds 10 integers.
    int (&arrRef)[10] = arr; // a reference that refer to an array that holds 10 integers.

    for (auto &i : arr)
    {
        cout << i << endl;
    }

    cout << "===================================" << endl;
    cout << "multidimension array" << endl;
    int ia[3][4];
    int arr1[10][20][30] = {0}; // initialize all elements to 0

    int ia5[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    int ia2[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int ia3[3][4] = { { 0 }, { 4 }, { 8 }}; // initialize only elements 0 in each row
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cout << ia3[i][j] << endl;
        }
    }
    int ia4[3][4] = {0, 3, 6, 9}; // initialize row 0; the remaining elements are initialized to 0.
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cout << ia4[i][j] << endl;
        }
    }
    cout << "using range" << endl;
    for (auto &row : ia4)
    {
        for (auto &col: row)
        {
            cout << col << endl;
        }
    }
    cout << "reference to an array" << endl;
    int (&row)[4] = ia[1];
    for (auto i : row)
    {
        cout << i << endl;
    }

    int (*p)[4] = ia; // p points to an array of four ints
    p = &ia[2]; // p now points to the last elements in ia.

    for (auto p = ia; p != ia + 3; ++p)
    {
        for (auto q = *p; q != *p + 4; ++q)
        {
            cout << *q << " ";
        }
        cout << endl;
    }
    // or
    for (auto p = begin(ia); p != end(ia); ++p)
    {
        for (auto q = begin(*p); q != end(*p); ++q)
        {
            cout << *q << ' ';
        }
        cout << endl;
    }

    //
    for (int (&row)[4]: ia)
    {
        for(int &col: row)
        {
            cout << col << ' ';
        }
        cout << endl;
    }

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cout << ia[i][j] << ' ';
        }
        cout << endl;
    }

    for (int (*p)[4] = ia; p != ia + 3; ++p)
    {
        for (int *q = *p; q != *p + 4; ++q)
        {
            cout << *q << ' ';
        }
        cout << endl;
    }
    return 0;
}