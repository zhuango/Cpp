#include <cstdio>
#define LOG(...) {\
    fprintf(stderr, "%s: Line %d:\t", __FILE__, __LINE__);\
    fprintf(stderr, __VA_ARGS__);\
    fprintf(stderr, "\n");\
}

int main(void)
{
    int x = 3;
    LOG("x = %d", x);
    return 0;
}
