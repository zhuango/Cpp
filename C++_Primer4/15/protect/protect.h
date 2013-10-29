#ifndef _PROTECT_H_
#define _PROTECT_H_

class Test{
	private:
		int data;
	public:
		void print(){std::cout << "Parent" << std::endl;}
	protected:
		void print_pro(){std::cout << "Parent protected" << std::endl;}
};

class Test2 : public Test{
	private:
		int da;
	public:
		void print_child(){std::cout << "Child" << std::endl;}
		void print_prot(Test2 &a, Test &b){
			print_pro();
			//Or
			a.print_pro();
		//	b.print_pro();//Error: Base Class Object visit Base Class Protected
		}
};

#endif
