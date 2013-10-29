#ifndef _MUTABLE_H_
#define _MUTABLE_H_

class Test{
	private:
		mutable size_t count;//Can be changed in const function
		//size_t count;
	public:
		Test():count(0){}
		Test(int init): count(init){}
		void print()const {
			count++;
			std::cout << count << std::endl;
		}
};

#endif
