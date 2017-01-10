#include <exception>
#include <stdexcept>
#include <iostream>
using namespace std;

//<exception>
// bad_exception

//<stdexcept>
// domain_error Class	The class serves as the base class for all exceptions thrown to report a domain error.
// invalid_argument Class	The class serves as the base class for all exceptions thrown to report an invalid argument.
// length_error Class	The class serves as the base class for all exceptions thrown to report an attempt to generate an object too long to be specified.
// logic_error Class	The class serves as the base class for all exceptions thrown to report errors presumably detectable before the program executes, such as violations of logical preconditions.
// out_of_range Class	The class serves as the base class for all exceptions thrown to report an argument that is out of its valid range.
// overflow_error Class	The class serves as the base class for all exceptions thrown to report an arithmetic overflow.
// range_error Class	The class serves as the base class for all exceptions thrown to report a range error.
// runtime_error Class	The class serves as the base class for all exceptions thrown to report errors presumably detectable only when the program executes.
// underflow_error Class	The class serves as the base class for all exceptions thrown to report an arithmetic underflow.
void newHandler()
{
    cout << "My new exception handler." << endl;
}
int main(void)
{
    try
    {
        throw domain_error("lalllalla");
    }
    catch(domain_error &e)
    {
        cout << "error: " << e.what() << endl;
    }

    unexpected_handler oldHandler = set_terminate(newHandler);
    unexpected();
    
    cout << "All Done." << endl;
    return 0;
}