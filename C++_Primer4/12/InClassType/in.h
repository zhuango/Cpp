#ifndef _IN_H_
#define _IN_H_

class Test{
	private:
		int data;
	public:
		Test():data(10){}
		Test(int d): data(d){}
		typedef int index;
		index getdata() const;
};

index Test::getdata()const
{
	return data;
}

#endif
