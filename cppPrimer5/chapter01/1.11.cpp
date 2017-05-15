#include <iostream>
int main(void)
{
    int start = 0;
    int end = 0;
    std::cin >> start >> end;
    while (start <= end) std::cout << start++ << std::endl;
    return 0;
}
