#include <iostream>
int main(void)
{
    int a = 50;
    int sum = 0;

    while (a < 100) sum += a++;
    std::cout << sum << std::endl;
}