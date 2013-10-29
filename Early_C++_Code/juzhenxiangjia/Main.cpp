#include<iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
	double juzhen_a[10]={1,2,3,4,5,6,7,8,9,10};
	double juzhen_b[10]={12,23,14,15,16,17,23};
	double add[10];
	double *qiuhe(double juzhen_a[10],double juzhen_b[10],double add[10]);
	qiuhe(juzhen_a,juzhen_b,add);
	for(int i=0;i<10;++i)
		cout<<*(add+i)<<' ';
	cout<<endl;
	return 0;
}
double *qiuhe(double juzhen_a[10],double juzhen_b[10],double add[10])
{
	
	for(int i=0;i<10;++i)
	{
		add[i]=juzhen_a[i]+juzhen_b[i];
	}
	return add;
}