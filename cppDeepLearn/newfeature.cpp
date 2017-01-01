
#include <iostream>
#include<cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <map>
using namespace std;

//Function return type deduction(C++14)
auto Correct(int i)
{
    if (i == 1)
        return 1; // return type deduced as int
    else
        return Correct(i - 1) + i;
}
/*
auto Wrong(int i) {
    if (i != 1)
        return Wrong(i - 1) + i;  // Too soon to call this. No prior return statement.
    else
        return i;             // return type deduced as int
}
*/

//Alternate type deduction on declaration(C++14)
//the way decltype and auto deduce types are different
//In particular, auto will always deduce a non - reference type, 
//as though by using std::decay, while auto&& will always deduce a reference type.However, 
//decltype can be prodded into deducing a reference or non - reference type, 
//based on the value category of the expression and the nature of the expression it is deducing :

int&& f()
{
    return 10;
}
void TestAutoDecltype()
{
    int i = 10;
    int&& f();
    auto copyi = i;                 //int
    decltype(i) copyi1 = i;         //int
    auto copyi2 = (i);              //int
    decltype((i)) copyiRef = (i);   //int&
    copyiRef = 11;//i is also changed.
    auto copyFun = f();             //int
    decltype(f()) newF = f();       //int&&
}

// move semantics and rvalue reference(C++11)
class NewString
{
    char * data;
public:
    NewString(const char *p)
    {
        size_t size = strlen(p) + 1;
        data = new char[size];
        memcpy(data, p, size);
    }
    ~NewString()
    {
        delete[] data;
    }
    NewString(const NewString &that)
    {
        size_t size = strlen(that.data) + 1;
        data = new char[size];
        memcpy(data, that.data, size);
    }
    NewString(NewString &&that)
    {
        data = that.data;
        that.data = nullptr;
    }
    NewString operator +(NewString &right)
    {
        size_t llen = strlen(this->data);
        size_t  rlen = strlen(right.data);
        size_t counter = 0;

        char *tempchar = new char[llen + rlen];
        for_each(this->data, this->data + llen, [&counter, tempchar](char a) {tempchar[counter++] = (a); });
        //for (; _First != _Last; ++_First)
        //    _Func(*_First);
        for_each(right.data, right.data + rlen, [&counter, tempchar](char a) {tempchar[counter++] = (a); });
        tempchar[counter] = '\0';

        return NewString(tempchar);
    }
};

void RvalueReferenceTest()
{
    NewString x("zhuangliu");
    NewString y("is gen");
    NewString a(x); //x is lvalue may be used in the fature somewhere.So deep copy is resonable.
    NewString b(x + y);
    NewString c(std::move(NewString("liuzhuag")));// x + y is rvalue, so use move semantics. 
}

//constexpr ¨C Generalized constant expressions(C++11)
//First, the function must have a non-void return type.
//Second, the function body cannot declare variables or define new types.
//Third, the body may contain only declarations, null statements and a single return statement.
constexpr int get_five() { return 5; }

void constexprTest()
{
    int some_value[get_five() + 7];
}


//Initializer lists(C++11)

class SequenceClass {
private:
    int a;
    int b;
    int c;
public:
    SequenceClass(std::initializer_list<int> lists)
    {
        //do something.
    }
};

void InitializerLists()
{
    vector<vector<int>> test = { {1, 2, 3}, {2, 5, 3}, {3}, {4}, {5} };
    for (auto &value : test)
    {
        cout << value.size() << " ";
    }
    cout << endl;

    list<int> test1 = { 1, 2, 3, 4 };
    for (auto &node : test1)
    {
        cout << node << " ";
    }
    cout << endl;

    vector<string> strSet = { "sdfasdf", "sdwwwww", "zhuanglui", "zhaungakle" };
    for (auto &str : strSet)
    {
        cout << str << " ";
    }
    cout << endl;

    map<string, int> marks = { {"zhuangliu", 123}, {"kailizhang", 12} };
    for (auto &pair : marks)
    {
        cout << pair.first << " " << pair.second << " ";
    }
    cout << endl;
}

//Uniform initialization(C++11)

class/*struct*/ BasicStruct
{
public:
    int x;
    double y;
};

class/*struct*/ AltStruct
{
public:
    AltStruct(int x, double y) : x_{ x }, y_{ y }
    {}
private:
    int x_;
    double y_;
};
struct IdString
{
    std::string name;
    int identifier;
};

IdString get_string()
{
    return{ "foo", 22 };
}

void UniformInit()
{
    BasicStruct var1{ 5, 2.2 };
    AltStruct var2{ 2, 4.3 };
    IdString idstr = get_string();
}

#include <functional>
using std::placeholders::_1;
using std::placeholders::_2;
//Type inference(C++11)
void some_function(int a, int b, int c)
{
    cout << a << " " << b << " " << c << endl;
}
void TypeInfer()
{
    auto some_strange_callable_type = std::bind(&some_function, _2, _1, 1);
    some_strange_callable_type(1, 2, 3);

    auto other_variable = 5;

    int some_int;
    decltype(some_int) other_integer_variable = 5;

    vector<int> test = { 1, 2, 3, 4, 5, 7 };
    //instead using std::vector<int>::const_iterator, auto is perfect.
    for (auto value = test.begin(); value != test.end(); ++value)
    {
        cout << *(value) << " ";
    }
    cout << endl;

    //useing & instead value transition.
    for (auto &x : test)
    {
        cout << x << " ";
    }
    cout << endl;

    const std::vector<int> v(1);
    auto a = v[0];        // a has type int
    decltype(v[1]) b = 1; // b has type const int&, the return type of
                          //   std::vector<int>::operator[](size_type) const
    auto c = 0;           // c has type int
    auto d = c;           // d has type int
    decltype(c) e;        // e has type int, the type of the entity named by c
    decltype((c)) f = c;  // f has type int&, because (c) is an lvalue
    decltype(0) g;        // g has type int, because 0 is an rvalue
}

//Lambda functions and expressions(C++11)
void lambdaTest()
{
    auto fun = [](int x, int y) -> int { return x + y; };
    cout << fun(1, 2) << endl;
}

//Alternative function syntax(C++11)

//Not allowed in c++03
//template<class Lhs, class Rhs>
//Ret adding_func(const Lhs &lhs, const Rhs &rhs) { return lhs + rhs; } //Ret must be the type of lhs+rhs

//Not legal C++11
//template<class Lhs, class Rhs>
//decltype(lhs + rhs) adding_func(const Lhs &lhs, const Rhs &rhs) { return lhs + rhs; } //Not legal C++11

//This is allowed in C++11.
//This is totally new syntax
template<class Lhs, class Rhs>
auto adding_func(const Lhs &lhs, const Rhs &rhs) -> decltype(lhs + rhs) { return lhs + rhs; }

struct SomeStruct {
    auto func_name(int x, int y) -> int;
};

auto SomeStruct::func_name(int x, int y) -> int {
    return x + y;
}

//Object construction improvement(C++11)
//in C++03
class SomeType {
    int number;

private:
    void Construct(int new_number) { number = new_number; }
public:
    SomeType(int new_number) { Construct(new_number); }
    SomeType() { Construct(42); }
};
//In C++11
class SomeType2 {
    int number;

public:
    SomeType2(int new_number) : number(new_number) {}
    SomeType2() : SomeType2(42) {}
};

int main(void)
{
    lambdaTest();
    TypeInfer();
    UniformInit();
    InitializerLists();
    string str("saf");
    string str1("sdfsdfs");
    str += "sdfsdf";
    cout << Correct(100) << endl;
    int array[10] = { 1,2, 3, 4, 5, 6, 7, 8, 9, 10 };
    for_each(array, array + 10, [](int n) {cout << n << " "; });
    RvalueReferenceTest();
    return 0;
}