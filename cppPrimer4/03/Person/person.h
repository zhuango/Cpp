#ifndef _PERSON_H_
#define _PERSON_H_

class Person{
	public:
		Person(std::string n, std::string a) : name(n), addr(a){}
		std::string getName() const {return name;}
		std::string getAddr() const {return addr;}
	private:
		std::string name;
		std::string addr;
};

#endif
