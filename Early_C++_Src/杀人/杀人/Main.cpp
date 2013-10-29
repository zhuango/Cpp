#include<iostream>
#include<deque>
using std::deque;
using std::cout;
using std::cin;
using std::endl;
int main()
{
	deque<int> fanren;
	int n;
	cout<<"请输入人数:"<<endl;
	cin>>n;
	for(int i=1;i<n;++i)
		fanren.push_back(i);
	cout<<"请输入死者编号:"<<endl;
	int die;
	cin>>die;
	deque<int>::iterator guy=fanren.begin();
	for(int i=0;;++i)
	{
		if((i+1)%die==0&&i>=n) {
			cout<<*(guy)<<"is killed!!!"<<endl;guy=fanren.erase(guy);}
		else guy++;
		if(guy==fanren.end()) guy=fanren.begin();
		if(fanren.size()==1) break;
	}
	cout<<*(fanren.begin())<<"is living!!!"<<endl;
	return 0;
}