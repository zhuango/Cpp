#include<iostream>
#include<deque>
#include<vector>
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::deque;
int main()
{
	deque<int> d1;
	deque<int> d2;
	for(int i=0;i<10;++i)
		d1.push_back(i);
	d2=d1;
	deque<int>::iterator dequ=d2.begin();
	while(dequ!=d2.end())
		cout<<*(dequ++);
	cout<<endl;
	d2.clear();
	for(int i=10;i<20;++i)
		d2.push_back(i);
	dequ=d2.begin();
	while(dequ!=d2.end())
		cout<<*(dequ++)<<" ";
	cout<<endl;
	d1.swap(d2);
	dequ=d1.begin();
	while(dequ!=d1.end())
		cout<<*(dequ++)<<" ";
	cout<<endl;
	deque<int> c;
	c.assign(d1.begin()+4,d1.end());
	dequ=c.begin();
	while(dequ!=c.end())
		cout<<*(dequ++)<<" ";
	cout<<endl;
	c.assign(9,10);
	dequ=c.begin();
	while(dequ!=c.end())
		cout<<*(dequ++)<<" ";
	cout<<endl;
	vector<int> ivec;
	cout<<"ivec:size  "<<ivec.size()<<endl
		<<"ivec:capacity"<<ivec.capacity()<<endl;
	for(vector<int>::size_type ix=0;ix!=24;++ix)
		ivec.push_back(ix);
	cout<<"ivec.size  "<<ivec.size()<<endl
		<<"ivec.capcity"<<ivec.capacity()<<endl;
	ivec.reserve(50);
	cout<<"ivec:size "<<ivec.size()<<endl
		<<"ivec:capacity "<<ivec.capacity()<<endl;
	while(ivec.size()!=ivec.capacity())
		ivec.push_back(0);
	cout<<"ivec:size"<<ivec.size()<<endl
		<<"ivec:capacity"<<ivec.capacity()<<endl;
	return 0;
}