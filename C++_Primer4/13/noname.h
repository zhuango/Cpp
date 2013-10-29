#ifndef NONAME_H_
#define NONAME_H_

struct NoName{
		NoName() : pstring(new std::string), i(0), d(0) { }
		NoName(const NoName &noname){
			pstring = new std::string(noname.getString());
			i = noname.i;
			d = noname.d;
		}
		NoName & operator=(const NoName &noname){
			pstring = new std::string(noname.getString());
			i = noname.i;
			d = noname.d;

			return *this;
		}
		~NoName(){delete pstring;}
		
		std::string getString() const {
			return *pstring;
		}
		void setString(std::string str){
			*pstring = str;
		}
		
		void setStringChar(int index, char c){
			if(index >= pstring->size()){
				std::cout << index << " is too big, change anther number\n" << std::endl;
				return ;
			}
			(*pstring)[index] = c;
		}
		void printString(){
			std::cout << *pstring << endl;
		}

	private:
		std::string	*pstring;
		int		i;
		double		d;
};

#endif
