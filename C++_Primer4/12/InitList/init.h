#ifndef _INTI_H_
#define _INIT_H_

class Test{
	private:
		const std::string ClassName;
		int data;
		double *ddata;
		std::ifstream &is;
		
	public:
		Test(std::ifstream &i) : ClassName("Test"), data(0), ddata(new double(0)), is(i){}
		void print(){
			char ch;
			while(is>>ch)
				std::cout << ch;
			std::cout << std::endl;
		}
};


#endif
