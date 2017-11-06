#include <iostream>
using namespace std;

// The data members all must have literal type.
// • The class must have at least one constexpr constructor.
// • If a data member has an in-class initializer, the initializer for a member of builtin type must be a constant expression (§ 2.4.4, p. 65), or if the member has
// class type, the initializer must use the member’s own constexpr constructor.
// • The class must use default definition for its destructor, which is the member
// that destroys objects of the class type (§ 7.1.5, p. 267).
class Debug
{
public:
    constexpr Debug(bool b = true): hw(b), io(b), other(b){}
    constexpr Debug(bool h, bool i, bool o): hw(h), io(i), other(o){}

    constexpr bool any() const { return hw || io || other; }
    void set_io(bool b) {io = b;}
    void set_hw(bool b) {hw = b;}
    void set_other(bool b) {hw = b;}

private:
    bool hw;
    bool io;
    bool other;
};

int main(void)
{
    constexpr Debug io_sub(false, true, false);
    if (io_sub.any())// equivalent to if(true)
    {
        cerr << "print appropriate error messages" << endl;
    }

    constexpr Debug prod(false);
    if (prod.any())// equivalent to if(false)
    {
        cerr << "print an error message" << endl;
    }
    return 0;
}