#ifndef _DONOTCOPY_H_
#define _DONOTCOPY_H_

class Test{
	public:
		Test(){};
	private:
		Test(const Test &);
		Test & operator =(const Test&);
};

#endif
