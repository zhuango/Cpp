#include<iostream>
#include<fstream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::ofstream;
using std::ifstream;
using std::string;
int main()
{
	ofstream os;
	os<<"Goodbye!"<<endl;
	string ifile("MATLAB±Ê¼Ç.txt"),ofile("out.txt");
	ifstream infile(ifile.c_str());
	ofstream outfile(ofile.c_str());
	if(!infile){
		cerr<<"error: unable to open input file"
			<<ifile<<endl;
		return -1;
	}
	while(infile){
		infile>>ofile;
		outfile<<ofile
			<<endl;
	}
	infile.clear();
	outfile.clear();
	infile.close();
	outfile.close();
	/*if(!infile){
		cerr<<"error:unable to open input file: "
			<<ifile<<endl;
		return -1;
	}
	*/
	return 0;
}