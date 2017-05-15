#include <iostream>
int main(void)
{
    int v1 = 0;
    int v2 = 0;
    std::cin  >> v1 >> v2;
    
    std::cout << "The sum of " << v1
              << " and " << v2
              << " is " << v1 + v2 << std::endl;
    
    return 0;
}