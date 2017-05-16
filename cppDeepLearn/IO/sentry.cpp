#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Its constructor performs the following operations on the stream object passed as its argument 
// (in the same order):
//  1.If any of its internal error flags is set, the function sets its failbit flag and returns.
//  2.If it is a tied stream, the function flushes the stream it is tied to (if its output buffer 
// is not empty). The class may implement ways for library functions to defer this flush until 
// the next call to overflow by its associated stream buffer.
//  3.If its skipws format flag is set, and the constructor is not passed true as second argument
// (noskipws), all leading whitespace characters (locale-specific) are extracted and discarded. 
// If this operation exhausts the source of characters, the function sets both the 
// failbit and eofbit internal state flags.

// Prepare stream for input
// Member class that performs a series of operations before and after each input operation

struct Phone
{
    std::string digits;
};

istream &operator>>(istream &is, Phone &ph)
{
    istream::sentry s(is);
    if (s)
    {
        while (is.good())
        {
            char c = is.get();
            if (isspace(c, is.getloc())) break;
            if (isdigit(c, is.getloc())) ph.digits += c;
        }
    }
    return is;
}

int main()
{
    stringstream parsem("   (555)2326");
    Phone phone;
    parsem >> phone;
    cout << "digits parsed: " << phone.digits << endl;
    return 0;
}