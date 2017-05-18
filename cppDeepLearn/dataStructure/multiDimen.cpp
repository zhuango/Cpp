#include <iterator>
using std::begin;
using std::end;

#include <vector>
#include <iostream>
using namespace std;

#include <cstddef>
using std::size_t;

int main(void)
{
    int ia1[3][4];

    // only the first element is assigned to 1.
    int arr[10][20][30] = {1};
    cout << arr[0][0][0] << endl;
    cout << arr[0][0][1] << endl;
    cout << arr[1][1][0] << endl;
    cout << arr[1][2][3] << endl;
    cout << "+++++++++++++++++++++" << endl;

    ia1[2][3] = arr[0][0][0];

    // binds row to the seconds four-element array in ia.
    // array of reference.
    int (&row)[4] = ia1[1];

    int ia2[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };

    int ia3[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    int ia4[3][4] = {{0}, {4}, {8}};
    cout << ia4[0][0] << endl;
    cout << ia4[0][1] << endl;

    cout << ia4[1][0] << endl;
    cout << ia4[1][1] << endl;

    cout << ia4[2][0] << endl;
    cout << ia4[2][1] << endl;
    cout << "++++++++++++++++++++++++" << endl;

    // explicitly initialize row 0; the remaining elements
    // are value initialized.
    int ix[3][4] = {1, 3, 6, 9};
    cout << ix[0][0] << endl;
    cout << ix[0][1] << endl;
    cout << ix[0][2] << endl;
    cout << ix[0][3] << endl;

    // read only.
    constexpr size_t rowCnt = 3, colCnt = 4;
    // Error!!!read only.
    // rowCnt = 12;
    int ia[rowCnt][colCnt];

    // for each row
    for (size_t i = 0; i != rowCnt; ++i) {
        // for each column within the row
        for (size_t j = 0; j != colCnt; ++j) {
            // assign the element's positional index as its value
            ia[i][j] = i * colCnt + j;   
		}
	}


    for (const auto &row : ia)
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    for (auto p = ia; p != ia + rowCnt; ++p)
    {
        for(auto q = *p; q != *p + colCnt; ++q)
        {
            cout << *q << " ";
        }
        cout << endl;
    }

    for (auto p = begin(ia); p != end(ia); ++p)
    {
        for (auto q = begin(*p); q != end(*p); ++q)
        {
            cout << *q << ' ';
        }
        cout << endl;
    }

    // new style type alias declaration.
    using int_array = int[4];
    for (int_array *p = ia; p != ia + 3; ++p)
    {
        for(int *q = *p; q != *p + 4; ++q)
        {
            cout << *q << ' ';
        }
        cout << endl;
    }

    int alt_ia[rowCnt][colCnt];
    size_t cnt = 0;
    for(auto &row : alt_ia)
    {
        for (auto &col : row)
        {
            col = cnt;
            ++cnt;
        }
    }
    for(const auto &row : alt_ia)
    {
        for(auto &col : row)
        {
            cout << col << ' ';
        }
        cout << endl;
    }
    return 0;
}