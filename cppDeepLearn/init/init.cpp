#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int v1(1024);   // direct-initialization, functional form
    int v2{1024};   // direct-initialization, list initializer form
    int v3 = 1024;  // copy-initialization
    int v4 = {1024};// copy-initialization, list initializer form

    string titleA = "zhuangliu, student.";
    string titleB("zhuanglium student.");
    string all_nines(10, '9');

    return 0;
}