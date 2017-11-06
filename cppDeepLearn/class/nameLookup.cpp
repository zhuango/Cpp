#include <iostream>
using namespace std;

class Test
{
public:
    int GetA(){return a;}
    int GetB(){return b;}
    int GetC(){return c;}
private:
    // Member function definitions are processed after the compiler processes all of
    // the declarations in the class
    int c = b;
    int b = 2;
    int a = b;
};

typedef double Money;
string bal = "liuzhuang";
class Account
{
    // Ordinarily, an inner scope can redefine a name from an outer scope even if that name
    // has already been used in the inner scope. However, in a class, if a member uses a
    // name from an outer scope and that name is a type, then the class may not
    // subsequently redefine that name:
    typedef double Money;
public:
    Money balance () {return bal;}    
    Money balance1 () {return bal;}
    // error aaa is not found cause the typedef is below this function declaration.
    // aaa GetA(){return 0;}
    // int SetA(aaa c){aaa b = 100; return 0;}
    typedef int  aaa;
private:
    Money bal;
};

int height; // defines a name subsequently used inside Screen

class Screen 
{
public:
    typedef std::string::size_type pos;
    void setHeight(pos);
    pos height = 0; // hides the declaration of height in the outer scope
};

Screen::pos verify(Screen::pos){}
void Screen::setHeight(pos var) 
{
    // var: refers to the parameter
    // height: refers to the class member
    // verify: refers to the global function
    height = verify(var);
}

int main(void)
{
    Test t;
    cout << t.GetA() << endl;
    cout << t.GetB() << endl;
    cout << t.GetC() << endl;

    Account acc;
}