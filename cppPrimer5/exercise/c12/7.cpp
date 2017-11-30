#include <vector>
#include <iostream>
#include <memory>

using namespace std;

using shared_ptr_vec = shared_ptr<vector<int>>;

void setVector (shared_ptr_vec vec)
{
    int tmp = 0;
    while(cin >> tmp)
    {
        vec->push_back(tmp);
    }
}

void printVector(shared_ptr_vec vec)
{
    for (const auto &a : *vec)
    {
        cout << a << " ";
    }
    cout << endl;
}
int main(void)
{
    shared_ptr_vec vec = make_shared<vector<int>>();
    setVector(vec);
    printVector(vec);

    return 0;
}