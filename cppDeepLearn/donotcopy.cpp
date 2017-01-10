class Test{
	public:
		Test(){};
	private:
		Test(const Test &);
		Test & operator =(const Test&);
};

int main()
{
	Test a;
	Test b;
//	Test c(a);
	Test d = b;
	return 0;
}

