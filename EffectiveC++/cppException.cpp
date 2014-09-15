#include <iostream>
#include <string>
using std::string;

class DivisorCanNotBeZeroException
{
public :
	DivisorCanNotBeZeroException(string errorMessage)
		:mErrorMessage(errorMessage)
	{
	}
	string ToString()
	{
		return mErrorMessage;
	}
private:
	string mErrorMessage;
};

int dev(int a, int b)
{
	if(!b)
		throw new DivisorCanNotBeZeroException("Divisor can not be zero");
}

void main()  
{
	try{
		dev(1, 0);
	}
	catch(DivisorCanNotBeZeroException *d){
		std::cout << d->ToString() << std::endl;
		delete d;
	}
	//catch all exception.
	catch(...)
	{
		std::cout << "bala bala" << std::endl;
	}
}
/*
release 版本时，complier会检查try数据块中是否有throw，如果没有，会被视为不会抛异常，这样catch会被优化掉。
于是便有了下面两种方法：

1、
	__try
	{
	BYTE* pch ;
	pch = ( BYTE* )00001234 ;   //给予一个非法地址
	*pch = 6 ; //对非法地址赋值，会造成Access Violation 异常
	}
	__except( EXCEPTION_EXECUTE_HANDLER )
	{
	AfxMessageBox( "catched" ) ;
	}

	但是用__try, __except块还有问题， 就是这个不是C++标准， 而是Windows平台特有的扩展。 而且如果在使用过程中涉及局部对象析构函数的调用，则会出现C2712 的编译错误。 那么还有没有别的办法呢？

2、当然有， 就是仍然使用C++标准的try{}catch(..){}， 但在编译命令行中加入 /EHa 的参数。这样VC编译器不会把try catch模块给优化掉了。
*/