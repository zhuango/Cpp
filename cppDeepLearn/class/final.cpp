#include<iostream>
using namespace std;

class MathObject
{
    public:
    virtual double Arith() = 0;
    virtual void Print() = 0;
};

class Printable: public MathObject
{
    public:
    double Arith() = 0;
    // can not limit override of this function in c++98.
    // we can do it in c++11 by add final mark.
    void Print() final
    {
        cout << "Output is: " << Arith() << endl;
    }
};

class Add2 : public Printable
{
    public:
    Add2(double a, double b): x(a), y(b)
    {

    }
    double Arith() { return x + y; }
    //Error! Print() of Printable is a final function.
    //void Print(){}

    private:
    double x, y;
};

class Mul3 : public Printable
{
    Mul3(double a, double b, double c):x(a), y(b), z(c){}
    double Arith(){ return x * y * z; }
    
    private:
    double x, y, z;
};

int main(void)
{
    return 0;
}