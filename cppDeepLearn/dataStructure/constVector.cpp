#include <iostream>
#include <vector>
using namespace std;


int main(void)
{
    const vector<int> v1(10, 2);
    // v1.push_back(100);
    auto iter = v1.begin();
    *(iter) = 100;
    
    return 0;
}
