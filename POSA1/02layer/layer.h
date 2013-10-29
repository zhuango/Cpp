#ifndef LAYER_H_
#define LAYER_H_

class layer1{
	public:
		virtual void l1service() = 0;
};

class layer2{
	public:
		virtual void l2service() = 0;
		void setLowerlayer(layer1 *ll){level11 = ll;}
	protected:
		layer1 *level11;
};

class layer3{
	public:
		virtual void l3service() = 0;
		void setLowerlayer(layer2 *ll){level12 = ll;}
	protected:
		layer2 *level12;
};

class Test1 : public layer1{
	public:
		virtual void l1service(){
			cout << "This is layer1 working" << endl;
		}
};

class Test2 : public layer2{
	public:
		virtual void l2service(){
			cout << "This is layer2 working" << endl;
			level11->l1service();
			cout << "This is layer2 finished" << endl;
		}
};

class Test3 : public layer3{
	public:
		virtual void l3service(){
			cout << "This is layer3 working" << endl;
			level12->l2service();
			cout << "This is layer3 finished" << endl;
		}
};

#endif
