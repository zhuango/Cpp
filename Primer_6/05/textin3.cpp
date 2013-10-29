#include<iostream>
int main()
{
	using namespace std;
	char ch;
	int count = 0;
	cin.get(ch);//attempt to read a char
	while(cin.fail() == false){// test for EOF
		cout << ch;
		++count;
		cin.get(ch);
	}

	cout << endl << count << "characters read\n";

	return 0;
}
