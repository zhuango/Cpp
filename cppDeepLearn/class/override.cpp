#include <iostream>
using namespace std;

class Test
{
    public:
        Test():a(0){}
        virtual void print()
        {
            cout << "print function " << a << endl;
        }
    private:
        int a;
};

class TestChild: public Test
{
    public:
        TestChild(){b = 100;}
        // print() must be a overrided function which is in base class.
        void print() override
        {
            cout << "print function2 " << b << endl;
        }

    private:
        int b;
};

class TestGrand: public TestChild
{
    public:
        TestGrand(){c = 1000;}
        void print() final
        {
            cout << "sdfsd " << c << endl;
        }
    private:
        int c;
};

class TestCC: public TestGrand
{
    public:
        TestCC(){d = 1000000;}
        //Error! function print in TestGrand is marked final.
        void print()
        {
            cout << "nothing" << endl;
        }
    private:
        int d;
};

int main()
{
    Test t;
    t.print();

    Test *tchild = new TestChild();
    tchild->print();

    return 0;
}