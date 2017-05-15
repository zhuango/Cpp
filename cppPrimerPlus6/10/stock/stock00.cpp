#include<iostream>
#include"stock00.h"

void Stock::acquire(const std::string & co, long n, double pr)
{
	company = co;
	if(n < 0){/* a number less than 0, set the shares 0 */
		std::cout << "Number of sharea can't be begative; "
			<< company << " shares set to 0.\n";
		shares = 0;
	}else/* greater than 0, So set the shares = n */
		shares = n;

	share_val = pr;/* set the share_val */
	set_tot();/* a private function that cal the total */
}

void Stock::buy(long num, double price)
{
	if(num < 0){/* a number less than 0??? */
		std::cout << "Number of shares purchased can't be negative. "
			<< "Transaction is aborted.\n";
	}else{/* buy something, change the shares and the share_val */
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	using std::cout;
	if(num < 0){/* sell a number less than 0, error? */
		cout << "Number os shares sold can't ne nagetive."
			<< "Transaction is aborted.\n";
	}else if (num > shares){
		cout << "Yout can't sell more than you have!"
			<< "Transaction is aborted.\n";
	}else{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

void Stock::show()
{
	std::cout << "Company : " << company
		<< "Shares : " << shares << '\n'
		<< "Shares Price : " << share_val << '\n'
		<< "Total Worth : $" << total_val << '\n';
}

