/*
	头文件包含，普通外部函数的定义
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using std::vector;
using std::ofstream;
using std::ifstream;
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::cerr;

void checkFile(ifstream &is,string file){
		if(!is){
		cerr<<"Can't open this file "
			<<file<<endl;
		exit(0);
	}
}

void checkFile(ofstream &os,string file){
		if(!os){
		cerr<<"Can't open this file "
			<<file<<endl;
		exit(0);
	}
}