#ifndef _PROTECT_H_
#define _PROTECT_H_

class Test{
	private:
		int data;
	public:
		void print(){std::cout << "Parent" << std::endl;}
	protected:
		int i;
};

class Test2 : private Test{
	private:
		int dat;
	public:
		int get(){return i;}
		void use_print(Test2 &a){
			a.print();
//			int i  = 0;
//			i += a.data;//Error: visit parent private element
		}
};

class Test3 : protected Test{
	private:
		int data;
	public:
		int get(){return i;}
		void use_print(Test3 &a){
			a.print();
		}
};

#endif
