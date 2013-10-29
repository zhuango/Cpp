#include <iostream>
using namespace std;
 int print(int a);
int main()
{
	typedef int (*camFun)(int);//定义camFun是一种数据类型的同义词，这种数据是一个指针
							   //指向的是一个函数，这个函数的返回值形参如定义中
	int f=7;
	camFun pf=print;//camFun代表一种数据类型，定义这个类型的变量
	f=pf(f);
	f=(*pf)(f);//此地的*pf和pf没有区别
	return 0;
}
 int print(int a)
{
	a=10;
	cout<<"成功调用"<<endl;
	return a;
}