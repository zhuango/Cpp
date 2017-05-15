#include <iostream>
using namespace std;

int main(void)
{
    int v1 = 0;
    int sum = 0;
    while(cin >> v1)
    {
        sum += v1;
    }
    std::cout << sum << std::endl;
}