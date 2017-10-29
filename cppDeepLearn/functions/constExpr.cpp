#include <iostream>
using namespace std;

// A constexpr function is a function that can be used in a constant expression
constexpr int new_sz() {return 42;}
constexpr int foo = new_sz();

// The return type and the type of each parameter in a must be a literal
// type (§ 2.4.4, p. 66), and the function body must contain exactly one return
// statement:
// constexpr functions are implicitly inline

constexpr size_t scale(size_t cnt) { return new_sz() * cnt;}

double random(double start, double end)
{
    return start+(end-start)*rand()/(RAND_MAX + 1.0);
}

int main(void)
{
    srand(unsigned(time(0)));
    int arr[scale(2)];
    int i = random(1, 10);
    cout << i << endl;
    int a2[scale(i)];
    cout << sizeof a2 << endl;
    cout << sizeof arr << endl;
    return 0;
}