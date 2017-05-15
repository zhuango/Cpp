#ifndef _PROTECTED_H_
#define _PROTECTED_H_

class Test{
	public:
		void print(){std::cout << "Parent print" << std::endl;}
	protected:
		void print_pro(){std::cout << "Parent protected" << std::endl;}
	private:
		int data;
};

class Test2 : public Test{
	public:
		void print_t(){
			std::cout << "Test2" << std::endl;
			print_pro();
		}

	private:
		int da;
};

#endif
