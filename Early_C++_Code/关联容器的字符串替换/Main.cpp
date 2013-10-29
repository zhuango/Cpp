#include<iostream>
#include<string>
#include<map>
#include"tihuan.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::map;
using std::pair;
int main()
{
	map<string,string>  mat;
	cout<<"ÇëÊäÈëÄúÒª·­ÒëµÄ×Ö·û´®"<<endl;
	mat.insert(map<string,string>::value_type("'em","them"));
	mat.insert(map<string,string>::value_type("cuz","because"));
	mat.insert(map<string,string>::value_type("gratz","grateful"));
	mat.insert(map<string,string>::value_type("i","I"));
	mat.insert(map<string,string>::value_type("nah","no"));
	mat.insert(map<string,string>::value_type("pos","supposed"));
	mat.insert(map<string,string>::value_type("sez","said"));
	mat.insert(map<string,string>::value_type("tanx","thanks"));
	mat.insert(map<string,string>::value_type("wuz","was"));
	string words;
	map<string,string>::iterator msst;
	while(cin>>words){
		msst=mat.find(words);
		if(mat.find(words)!=mat.end()) cout<<msst->second<<" ";
		else  cout<<words<<" ";

	}
	cout<<endl;
	return 0;
}