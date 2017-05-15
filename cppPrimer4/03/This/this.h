#ifndef _THIS_H_
#define _THIS_H_

class A{
	public:
		A():data(100){}
		A &getSelf(){return *this;}
		void print_data(){std::cout << data << std::endl;}
	private:
		int data;
};

#endif
