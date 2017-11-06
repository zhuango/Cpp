#include <iostream>
using namespace std;

class ConstRef
{
public:
    //error
    //ConstRef(int ii){i = ii;}

    ConstRef(int ii):i(ii), ci(ii), ri(ii) {}
private:
    int i;
    const int ci;
    int &ri;
};

int main(void)
{
    // ConstRef cr(100);
    return 0;
}