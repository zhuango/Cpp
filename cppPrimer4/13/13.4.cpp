#include<iostream>
using namespace std;

struct NoName{
		NoName() : pstring(new std::string), i(0), d(0) { }
		NoName(const NoName &noname){
			pstring = new std::string(noname.getString());
			i = noname.i;
			d = noname.d;
		}
		~NoName(){delete pstring;}
		
		std::string getString() const {
			return *pstring;
		}
		void setString(std::string str){
			*pstring = str;
		}

		void printString(){
			std::cout << *pstring << endl;
		}

	private:
		std::string	*pstring;
		int		i;
		double		d;
};

int main()
{
	NoName a;
	a.setString("Liu");

	NoName b(a);

	a.printString();

	return 0;
}
