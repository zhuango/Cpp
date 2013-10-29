#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::list;
using std::deque;
int main()
{
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	list<int> ilist;
	deque<double> ide(arr,arr+9);
	vector<char> ivec;
	deque<double>::iterator dter=ide.begin();
	while(dter!=ide.end())
		cout<<*(dter++);
	cout<<endl;
	for(int i=0;i<10;++i)
	ilist.push_back(i);
	list<int>::iterator iter=ilist.begin();
	while(iter!=ilist.end())
		cout<<*(iter++);
	cout<<endl;
	for(double i=0;i<10;++i)
		ide.push_back(i);
	dter=ide.begin();
	while(dter!=ide.end())
		cout<<*(dter++);
	cout<<endl;
	char i='a';
	for(int j=0;j<10;++j,++i)
		ivec.push_back(i);
	vector<char>::iterator vter=ivec.begin();
	while(vter!=ivec.end())
		cout<<*(vter++);
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	list<int> back(3);
	list<int>::iterator iter1=back.begin();
	while(iter1!=back.end())
		*(iter1++)=6;
	iter1=back.begin();
	while(iter1!=back.end())
	cout<<*(iter1++);
	cout<<endl;
	back.push_front(4);
	iter1=back.begin();
	while(iter1!=back.end())
		cout<<*(iter1++);
	cout<<endl;
	vector<string> svec;
	list<string> slist;
	string spouse("Beth");
	slist.insert(slist.begin(),spouse);
	svec.insert(svec.begin(),spouse);
	list<string> lst;
	list<string>::iterator ister2=lst.begin();
	string word;
	while(cin>>word)
		ister2=lst.insert(ister2,word);
	svec.insert(svec.end(),10,"Anna");
	string sarrsy[4]={"I","like","C++","vevy"};
	svec.insert(svec.end(),sarrsy,sarrsy+3);
	svec.insert(svec.begin(),sarrsy+1,sarrsy+2);
	vector<int> v(1);
	cout<<"v.size()返回值为"<<v.size()<<endl
		<<"v.empty()返回值 "<<v.empty()<<endl
		<<"v.max_size()返回值"<<v.max_size()<<endl;
	v.resize(10);
	cout<<"经过v.resize()后的v.size()返回值为"<<v.size()<<endl;
	v.resize(11,3);
	vector<int>::iterator bvterr=v.begin(),
							evterr=v.end();
	while(bvterr!=evterr)
		cout<<*(bvterr++);
	cout<<endl;
	deque<int> d;
	for(int i=0;i<10;++i)
		d.push_back(i);
	deque<int>::reference rede=*(d.begin());
	deque<int>::reference rede1=d.front();
	deque<int>::reference rede2=d.back();
	cout<<"d.at(0):"<<v.at(0)<<endl
		<<d[0]<<endl
		<<"*(d.begin()):"<<rede<<endl
		<<"d.front:"<<rede1<<endl
		<<"d.back:"<<rede2<<endl;
	return 0;
}