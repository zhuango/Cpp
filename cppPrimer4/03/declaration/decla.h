#ifndef _DECLA_H_
#define _DECLA_H_

class X;
class Y{
	public:
		Y(){std::cout << "Y" << std::endl;}

	private:
		X *px;
};

class X{
	public:
		X(){std::cout << "X" << std::endl;}
	private:
		Y py;
};

#endif
