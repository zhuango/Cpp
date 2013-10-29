#include<iostream>
#include<vector>
#include<set>
#include<string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::set;
int main()
{
	vector<int> ivec;
	for(vector<int>::size_type i=1;i!=11;++i){//向容器内添加元素
		ivec.push_back(i);
		ivec.push_back(i);
	}
	set<int> iset(ivec.begin(),ivec.end());//初始化set<int>容器，无重复，例如插入：1 1 2 2 3；实际只插入1 2 3；
	cout<<ivec.size()<<endl;
	cout<<iset.size()<<endl;
	set<string> set1;
	set1.insert("the");//插入元素
	set1.insert("and");
	set<int> iset2;
	iset2.insert(ivec.begin(),ivec.end());//无重复插入元素段，例如插入：1 1 2 2 3；实际只插入1 2 3；
	set<int>::iterator a=iset.find(1);
	set<int>::iterator b=iset.find(11);
	int c=iset.count(1);
	int d=iset.count(11);
	set<int>::iterator set_it=iset.find(1);
	cout<<*set_it<<endl;//对set关联容器解引用得到是是key
	return 0;
}