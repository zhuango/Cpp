#include<iostream>
#include<map>
#include<set>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::map;
using std::set;
using std::string;
using std::multimap;
using std::multiset;
using std::make_pair;
using std::pair;
int main()
{
	multimap<string,string> auther;
	auther.insert(make_pair("Barth John","Sot_Wed Factor"));
	auther.insert(make_pair("Barth John","Lost in the Funhouse"));
	multimap<string,string> authers;
	string search_item("Kazuo Ishiguro");
	multimap<string,string>::size_type cnt=authers.erase(search_item);
	string search_item1("Barth John");
	typedef multimap<string,string>::size_type sz_type;
	sz_type entries=auther.count(search_item1);//键为search_item1的元素有多少个
	multimap<string,string>::iterator iter=auther.find(search_item1);//multimap容器的find找的是第一个键是search_item1的元素
																	 //并且返回指向这个元素的迭代器
	for(sz_type i=0;i!=entries;++i,++iter)//count函数返回值控制输出个数，find函数返回从哪个元素开始输出
		cout<<iter->second<<endl;
	iter=auther.lower_bound(search_item1);
	while(iter!=auther.upper_bound(search_item1)){
		cout<<iter->second<<endl;
		++iter;
	}
	typedef multimap<string,string>::iterator mssi_type;
	pair<mssi_type,mssi_type> pairmm=auther.equal_range(search_item1);
	while(pairmm.first!=pairmm.second){
		cout<<pairmm.first->second<<endl;
		++pairmm.first;
	}
	return 0;
}