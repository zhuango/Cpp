#include<iostream>
#include<deque>
#include<algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::deque;
int main()
{
	deque<int> ideq;
	for(int i=0;i<10;i++)
		ideq.push_back(i);
	deque<int>::iterator diter=ideq.begin(),
							diter2=ideq.end();
	while(diter!=diter2)
		cout<<*(diter++);
	cout<<endl;
	deque<int>::iterator del=ideq.begin();
	ideq.erase(del);//删除第一个元素
	diter=ideq.begin();
	while(diter!=ideq.end())
		cout<<*(diter++);
	cout<<endl;
	ideq.erase(ideq.begin()+1,ideq.end());//删除第二个到最后的元素
	diter=ideq.begin();
	while(diter!=ideq.end())
		cout<<*(diter++);
	cout<<endl;
	for(int i=2;i<9;i++)
		ideq.push_back(i);//重新加入元素
	diter=ideq.begin();
	while(diter!=ideq.end())
		cout<<*(diter++);
	cout<<endl;
	ideq.pop_back();//删除最后一个元素
	diter=ideq.begin();
	while(diter!=ideq.end())
		cout<<*(diter++);
	cout<<endl;
	ideq.pop_front();//删除头元素
	diter=ideq.begin();
	while(diter!=ideq.end())
		cout<<*(diter++);
	cout<<endl;
	diter=find(ideq.begin(),ideq.end(),5);
	ideq.erase(diter);//删除ideq容器范围内第一个是5的数
	diter=ideq.begin();
	while(diter!=ideq.end())
		cout<<*(diter++);
	cout<<endl;
	ideq.clear();
	cout<<ideq.size()
		<<endl;
	return 0;
}