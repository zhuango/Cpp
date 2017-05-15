#include<iostream>
using namespace std;

class Test{
	private:
		int data1;
		double data2;
	public:
		void setData1(int a){
			data1 = a;
		}
		void setData2(double b){
			data2 = b;
		}
		void printData1(){
			std::cout << "data1 = " << data1 << endl;
		}
		void printData2(){
			std::cout << "data2 = " << data2 << endl;
		}

		void set(Test &a){
			a.data1 = data1;
			a.data2 = data2;
		}
};

int main(void)
{
	Test a;
	a.setData1(1);
	a.setData2(10.3);

	Test b;
	a.set(b);
	b.printData1();
	b.printData2();

	return 0;
}
