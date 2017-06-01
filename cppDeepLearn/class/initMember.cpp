class Init
{
    public:
        Init(): a(0){}
        Init(int d): a(d) {}
    private:
        int a;
        const static int b = 0;
        int c = 1; // in c++98, member must be initialized in constructor.
        // static int d = 0; // Error! not const.
        // static const double e = 1.3; // Error! not a integer or enum.
        // static const char * const f = "e"; // Error! not a integer or enum
};

struct Init1 
{ 
    int a = 1;
    double b{1.2};
};

struct C
{
    C(int i):c(i){}
    int c;
};

struct Init2
{
    int a = 1;
    // string s("Hello"); // Error! () is not allowed.
    // C c(1); // Error! () is not allowed.
};

int main()
{
    return 0;
}