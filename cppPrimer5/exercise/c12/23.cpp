#include <iostream>
#include <cstring>

using namespace std;

char * cat(char *a, char *b)
{
    char *c = new char[strlen(a) + strlen(b) + 1];
    strcpy(c, a);
    strcat(c, b);
    cout << c << endl;
    return c;
}
int main(void)
{
    char *c = cat("SSSSSSS", "dsssssssss");
    delete[] c;
    return 0;
}
