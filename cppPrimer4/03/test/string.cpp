#include<iostream>
#include<string>
using std::cout;
using std::string;
using std::endl;
using std::cin;

int main()
{
	string a = "NiMa";
	cout << a << endl;

	string b(a);
	cout << a << endl;
	
	string c("LiuZhuang");
	cout << c << endl;
	
	string d(10, 'f');
	cout << d << endl;

	cout << "Please input something!" << endl;
	cin >> d;
	cout << d << endl;

	d = d + "NiMaBi";
	cout << d << endl;
	return 0;
}
