#include<iostream>
int main(void)
{
	using namespace std;
	int ch;
	int count = 0;

	while((ch = cin.get()) != '\0'){
		cout.put(char(ch));
		++count;
	}

	cout << endl << count << "character read\n";
	return 0;
}
