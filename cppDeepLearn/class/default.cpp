#include <iostream>

class Default
{
    public:
        // explicitly ask the compiler to generate the synthesized versions of the copycontrol members by defining them as = default
        Default() = default;
};

struct A
{
    Default my_mem;
};

struct B
{
    B(){}
    Default b_member;
};

int main()
{
    A a;
}