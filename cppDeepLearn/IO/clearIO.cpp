#include <iostream>

using namespace std;
/*
  enum _Ios_Iostate
    { 
      _S_goodbit 		= 0,
      _S_badbit 		= 1L << 0,
      _S_eofbit 		= 1L << 1,
      _S_failbit		= 1L << 2,
      _S_ios_iostate_end = 1L << 16,
      _S_ios_iostate_max = __INT_MAX__,
      _S_ios_iostate_min = ~__INT_MAX__
    };
*/

void on()
{
    /*
    void
      setstate(iostate __state)
      { this->clear(this->rdstate() | __state); }
    */
    cin.setstate(cin.badbit | cin.eofbit | cin.failbit);
}
void off()
{
    cin.clear(cin.rdstate() & !cin.failbit & ~cin.badbit);
}

int main(void)
{
    cout << "before read" << endl;
}