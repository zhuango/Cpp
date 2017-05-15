#include<iostream>
#include<valarray>
using std::valarray;
using std::cout;
using std::endl;
int main()
{
	int inger[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	valarray<int> a(10);
	cout << a[9] << endl;
	cout << "a's sum: " << a.sum() << endl;
	cout << "a's size:" << a.size() << endl;


	valarray<int> b(10, 2);
	cout << b[0] << endl;

	valarray<int> c(inger, 8);
	for(int i = 0; i < 8; i++)
		cout << c[i] << " " ;
	cout << endl;

	return 0;
}
