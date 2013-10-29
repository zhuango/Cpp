#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
int main()
{
	string str;
	while(getline(cin, str)){
		cout << str << endl;
	}

	return 0;
}
