#include<iostream>
#include<vector>
#include<iterator>
using std::iterator;
using std::vector;
using std::cout;
using std::endl;

class Node{
	public:
		Node(vector<int> & _a){a = _a;}
		void work(){
			a[0] = 10;
			for(vector<int>::iterator iter = a.begin();iter != a.end(); ++iter){
				cout<< *iter <<" ";
			}
		}
	private:
		vector<int> a;
};

int main(void){
	vector<int> v(3,1);
	Node n(v);
	n.work();
	for(vector<int>::iterator iter = v.begin();iter != v.end(); ++iter){
		cout<< *iter <<" ";
	}
	cout<<endl;
	return 0;

}
