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
        virtual void foo(){ cout << "foo" << endl;}
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
        virtual void func(){cout << "func" << endl;}
        char x ='c';
    };
    class B: public virtual A
    {
        public:
        virtual void foo(){cout << "foo" << endl;}
    };
}

namespace Type3ImpVirtualFunction
{
    class A
    {
        public:
        virtual void func(){cout << "func" << endl;}
        char x ='A';
    };
    class B: public virtual A
    {
        public:
        virtual void func() {cout << "func in B" << endl;}
        virtual void foo(){cout << "foo" << endl;}
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
void testType1()
{
    Type1::A aType1;
    Type1::B bType1;

    cout << "Type1" << endl;
    cout << sizeof(aType1) << endl;
    cout << sizeof(bType1) << endl;
    cout << endl;
}
void testType2()
{    
    Type2::A aType2;
    Type2::B bType2;
    cout << "Type2" << endl;
    cout << sizeof(aType2) << endl;
    cout << sizeof(bType2) << endl;
    cout << endl;
}
void testType3()
{
    Type3::A aType3;
    Type3::B bType3;
    cout << "Type3" << endl;
    cout << sizeof(aType3) << endl;
    cout << sizeof(bType3) << endl;
    cout << endl;
}
void testType4()
{
    Type4::A aType4;
    Type4::B bType4;
    cout << "Type4" << endl;
    cout << sizeof(aType4) << endl;
    cout << sizeof(bType4) << endl;
    cout << endl;
}
void testVirtualFunctionTable()
{
    Type1::B bType1;

    cout << "===================================" << endl;
    cout << sizeof(bType1) << endl;
    typedef void (*function)(void);
    function func = (function) *( (long*) (*( (long*)(&bType1) )));
    cout << (long*) (*( (long*)(&bType1) )) << endl;
    func();

    func = (function) *( (long*) (*( (long*)(&bType1) )) + 1 );
    cout << (long*) (*( (long*)(&bType1) )) + 1 << endl;
    func();

    // you will step into another object address space.
    // func = (function) *( (long*) (*( (long*)(&bType1) + 1 )));
    // cout << (long*) (*( (long*)(&bType1) + 1 )) << endl;
    // func();
    cout << "===================================" << endl;
}

void testVirtualPointerToBaseClass()
{
    typedef void (*function)(void);
    function func;

    // Type3::A aType3;
    // cout << aType3.x << endl;
    Type3::B bType3;
    cout << "===================================" << endl;
    cout << sizeof(bType3) << endl;
    cout << sizeof(char) << endl;


    func = (function) *( (long*) (*( (long*)(&bType3) )));
    func();
    
    func = (function) *( (long*) (*( (long*)(&bType3) + 1 )) );
    func();

    cout << "===================================" << endl;


    Type3ImpVirtualFunction::B bType3ImpVirtualFunction;
    cout << "===================================" << endl;
    cout << sizeof(bType3ImpVirtualFunction) << endl;

    func = (function) *( (long*) (*( (long*)(&bType3ImpVirtualFunction) )) );
    func(); 
    func = (function) *( (long*) (*( (long*)(&bType3ImpVirtualFunction) )) + 1 );
    func();

    func = (function) *( (long*) (*( (long*)(&bType3ImpVirtualFunction) + 1 )));
    func();

    char baseA = (char)(*( (long*)(&bType3ImpVirtualFunction) + 2 ));
    cout << baseA  << endl;
    //baseA->func();
    
    cout << "===================================" << endl;
}

int main(void)
{
    char *add;
    cout << "size of address: " << sizeof(add) << endl;

    // testType1();
    // testType2();
    // testType3();
    // testType4();
    // testVirtualFunctionTable();
    testVirtualPointerToBaseClass();
}
