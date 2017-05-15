#ifndef _CAST_H_
#define _CAST_H_

class First{
	private:
		int a;
		double b;
	public:
		First():a(0), b(0){}
		First(int av, double bv): a(av), b(bv){}
		void print(){
			std::cout << "a = " << a << std::endl << "b = " << b << std::endl;
		}
};

class Second{
	private:
		int a;
		double b;
	public:
		Second(): a(1), b(1){}
		Second(int av, double bv): a(av), b(bv){}
		void print(){
			std::cout << "a = " << a << std::endl << "b = " << b << std::endl;
		}
};

#endif
