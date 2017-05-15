#ifndef _NAME_H_
#define _NAME_H_

typedef std::string Type;
Type initVal()
{
	std::cout << "NiMa" << std::endl;
	return "OK";
}
class Test{
	public:
		typedef double Type;
		::Type setVal(::Type);
		::Type initVal(){val = 0;}
	private:
		int val;
};

Type Test::setVal(::Type d)
{
	std::string val;
	val = d + ::initVal();
	return val;
}

#endif
