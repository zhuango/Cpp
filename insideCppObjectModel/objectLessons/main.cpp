//#include "Point3d.cpp"
//using namespace ObjectLessons;

//#include "point3d.c"

//#include "varLengthArray.cpp"

void testVarLengthArray();
void testPoint3dTemplate();
void testVirtualDestruct();
#include <iostream>
using namespace std;

int main(void)
{
	//testPointFunc();
	//testPoint3d();
	//testVarLengthArray();
	//testPoint3dTemplate();
	char *a = "zhuangliu";
	a[2] = 'G';
	cout << a << endl;

	const char *b = "zhuangliu";
	//b[2] = 'G';// error, content in the address to which b points is const.
	b = "zhangkaili";// the pointer is itself is not const.
	cout << b << endl;

	char const * c = "zhuangliu";
	//c[2] = 'G';// error, same as b.
	c = "zhangkaili";
	cout << c << endl;

	char * const d = "zhuangliu";
	d[2] = 'G';//content is not const, so we can change it.
	//d = "zhnagkaili";//error, the pointer is const.
	cout << d << endl;

	testVirtualDestruct();
	return 0;
}