#include<iostream>

int main()
{
	using namespace std;
	char ch = 'M';
	int i = ch;
	cout << "Add ASCII code for " << ch << " is " << i << endl;

	cout << "Add one to the charachter code: " << endl;
	ch = ch + 1;
	i = ch;
	cout << "The ASCII code for " << ch << " is " << i << endl;

	cout << "Displaying char ch using cout.out(ch): ";
	cout.put(ch);

	cout.put('!');
	cout << endl << "Done" << endl;

	return 0;
}
