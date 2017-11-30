#include <vector>
#include <iostream>

using namespace std;

void setVector (vector<int> *vec)
{
    int tmp = 0;
    while(cin >> tmp)
    {
        vec->push_back(tmp);
    }
}

void printVector(vector<int> *vec)
{
    for (const auto &a : *vec)
    {
        cout << a << " ";
    }
    cout << endl;
}
int main(void)
{
    vector<int> *vec = new vector<int>;
    setVector(vec);
    printVector(vec);
    delete vec;

    return 0;
}