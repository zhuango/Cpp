#include<iostream>
#include<bitset>
#include<string>
#include<stdio.h>
using std::bitset;
using std::cout;
using std::endl;
using std::string;
int main()
{
	int i(1023);
	int *pi=new int(1024);
	cout<<pi<<endl;
	delete pi;
	pi=NULL;
	cout<<pi<<endl;
	int *pca=&i;
	const int *pci=new const int(1024);
	cout<<*pci<<endl;
	pci=pca;
	cout<<*pci<<endl;
	int s=3;
	printf("%f",s);
	return 0;
}