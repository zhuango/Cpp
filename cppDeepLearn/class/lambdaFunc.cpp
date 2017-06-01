#include <iostream>
using namespace std;

class FuncAdd
{
    public:
        FuncAdd(){}
        int operator () (int a, int b){
            return a + b;
        }
};

int main(void)
{
    FuncAdd fa;
    int result = fa(2, 3);
    cout << result << endl;
}