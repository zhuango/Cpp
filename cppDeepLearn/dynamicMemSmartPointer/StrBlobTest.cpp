#include "StrBlob.h"

int main(void)
{
    StrBlob sb;
    {
        StrBlob sb0 = {"12", "23", "34", "45"};
        sb = sb0;
    }
    
    return 0;
}