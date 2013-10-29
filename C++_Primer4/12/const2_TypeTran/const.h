#ifndef _CONST_H_
#define _CONST_H_

class Test{
	private:
		int data;
	public:
		Test(int d):data(d){}
		const Test & display()const;
		Test & display();
//		Test & display()const;//Error for returning a no-const object in a const function
		void set(int d);
};

const Test & Test::display() const
{
	std::cout << data << std::endl;

	return *this;
}

Test & Test::display()
{
	return 
		const_cast<Test &>(
			static_cast<const Test &>(*this).display()
		);
}

void Test::set(int d)
{
	data = d;
}

#endif
