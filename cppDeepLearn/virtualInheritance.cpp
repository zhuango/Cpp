#include <iostream>
using namespace std;

//virtual inheritance lets a class specify that it is willing to share its base class. 
//The shared base-class subobject is called a virtual base class.
// Virtual derivation affects the classes that subsequently derive from a class
// with a virtual base; it doesn’t affect the derived class itself.
namespace Type1
{
    class A
    {
        public:
        virtual void func(){ cout << "func" << endl;}
    };

    class B: public virtual A
    {
        public:
        virtual void foo(){}
    };
}

namespace Type2
{
    class A
    {
        public:
        virtual void func(){}
    };

    class B: public A
    {
        public:
        virtual void foo(){}
    };
}

namespace Type3
{
    class A
    {
        public:
        virtual void func(){}
        char x;
    };
    class B: public virtual A
    {
        public:
        virtual void foo(){}
    };
}

namespace Type4
{
    class A
    {
        public:
        virtual void func(){}
        char x;
    };
    class B:public A
    {
        public:
        virtual void foo(){}
    };
}

int main(void)
{
    char *add;
    cout << sizeof(add) << endl;

    Type1::A aType1;
    Type1::B bType1;

    typedef void (*function)(void);
    function func =     (function)(&aType1);
    func();

    cout << "Type1" << endl;
    cout << sizeof(aType1) << endl;
    cout << sizeof(bType1) << endl;
    cout << endl;
    
    Type2::A aType2;
    Type2::B bType2;
    cout << "Type2" << endl;
    cout << sizeof(aType2) << endl;
    cout << sizeof(bType2) << endl;
    cout << endl;

    Type3::A aType3;
    Type3::B bType3;
    cout << "Type3" << endl;
    cout << sizeof(aType3) << endl;
    cout << sizeof(bType3) << endl;
    cout << endl;

    Type4::A aType4;
    Type4::B bType4;
    cout << "Type4" << endl;
    cout << sizeof(aType4) << endl;
    cout << sizeof(bType4) << endl;
    cout << endl;

}