#include<iostream>
#include<string>
using namespace std;
int shuzu1[10];
int main()
{
	const char *cp1="I like C++";
	const char *cp2="I like C++ too";//字典排序法，cp2在cp1后面，cp2>cp1
	int i=strcmp(cp1,cp2);
	cout<<i<<endl;
	i=strcmp(cp1,cp2);//后大于前返回负数
	cout<<i<<endl;
	i=strcmp(cp1,cp1);
	cout<<i<<endl;//相同返回0
	i=strcmp(cp2,cp1);
	cout<<i<<endl;//cp2>cp1，前大于后返回整数
	char ca[]={'C','+','+','\0'};
	cout<<strlen(ca)<<endl;
	char largeStr[16+18+2];
	strcpy(largeStr,cp1);
	strcat(largeStr," ");
	strcat(largeStr,cp2);
	cout<<largeStr<<endl;
	strncpy(largeStr,cp1,17);
	strncat(largeStr," ",2);
	strncat(largeStr,cp2,18);//数字（包括NULL字符） 控制 cp2 连接的个数，这样不会产生安全泄露
	cout<<largeStr<<endl;
	return 0;
}