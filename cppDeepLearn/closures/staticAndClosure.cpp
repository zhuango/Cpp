#include <iostream>
#include <functional>

int static_f() 
{
    static int var = 0;
    return ++var;
}

std::function<int()> closure_f_gen()
{
    int var = 0;
    return [=]() mutable {return ++var;};
}

std::function<int()> static_f_gen()
{
    return static_f;
}

int main(void)
{
    auto static_f1 = static_f_gen();
    auto static_f2 = static_f_gen();
    auto closure_f1 = closure_f_gen();
    auto closure_f2 = closure_f_gen();

    std::cout << "static_f:" << std::endl;
    std::cout << static_f1() << std::endl;
    std::cout << static_f1() << std::endl;
    std::cout << static_f2() << std::endl;
    std::cout << static_f2() << std::endl;

    std::cout << "closure_f_gen: " << std::endl;
    std::cout << closure_f1() << std::endl;
    std::cout << closure_f1() << std::endl;
    std::cout << closure_f2() << std::endl;
    std::cout << closure_f2() << std::endl;

}