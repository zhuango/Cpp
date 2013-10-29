#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include<exception>
#include<bitset>
#include<cassert>
using std::bitset;
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::runtime_error;
//using std::
#define NDEBUG
int main()
{
	double d=97.0;
	char ch=static_cast<char>(d);
	cout<<d<<' '<<ch<<endl;
	unsigned long sh=23;
	bitset<100> bh;
	for(size_t i=0;i<100;++i)
		bh[i]=1;
	try
		{bh.to_ulong();}
	catch(runtime_error err)
		{cout<<err.what()<<endl;}
	string s;
	while(cin>>s&&s!="sought") {}
#ifndef NDEBUG
	assert(cin);
#endif
	cout<<"×ß£¡£¡£¡ÍæÈ¥°¡£¡"<<endl;
	return 0;
}
