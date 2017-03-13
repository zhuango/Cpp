#include <string>
using namespace std;

class WordBitWiseCopy
{
public:
	WordBitWiseCopy(const char *s)
	{
		str = new char[10];
	} 
	~WordBitWiseCopy()
	{
		delete[] str;
	}
private:
	int   cnt;
	char *str;
};

class WordNoBitWiseCopy
{
public:
	WordNoBitWiseCopy(const string &s):
		str(s)
	{

	}
	~WordNoBitWiseCopy() {}
private:
	int   cnt;
	string str;
};

void foo()
{
	WordBitWiseCopy wordBitWiseCopy("zhuangliu");
	//bit-wise copy, complier does not generate default copy constructor.
	WordBitWiseCopy wordBitWiseCopy2 = wordBitWiseCopy;

	WordNoBitWiseCopy wordNoBitWiseCopy("zhuangliu");
	//not a bit-wise copy, complier will generate default copy constructor.
	WordNoBitWiseCopy wordNoBitWiseCipy2 = wordNoBitWiseCopy;
}