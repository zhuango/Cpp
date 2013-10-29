#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
class login{
public :
	login(){
		username = "liu";
		pwd="123";
	}
	bool clogin(string cusername,string cpwd){
		if(cusername==username && cpwd == pwd){
			return 1;
		};
		return 0;
	}
private:
	string username;
	string pwd;
};

class bank{
public :
	bank(){
		Money=0;
	}
	bank(double money){
		Money=money;
	}
	void save();
	void get();
	void show();
private:
	double Money;
};

void bank::save(){
	cout<<"您想存多少钱:"<<endl;
	double money;
	cin>>money;
	Money+=money;
}

void bank::get(){
	cout<<"您要取多少钱:"<<endl;
	double money;
	cin>>money;
	if((Money-money)<0){
		cout<<"您的余额不足!"<<endl;
		return ;
	}
	Money-=money;
}

void bank::show(){
	cout<<endl<<"您现有余额为:"<<Money<<endl;
}
int main(){
	login in;
	int n=3;
	while(true){
		cout<<endl<<"请输入用户名及密码"<<endl;
		string username;
		cout<<endl<<"用户名:";
		cin>>username;
		string pwd;
		cout<<endl<<"密码:";
		cin>>pwd;


		if(in.clogin(username,pwd)){
			n=3;
			bank user(12);
		
			while(true){
				cout<<endl<<"1、存钱"<<endl<<"2、取钱"<<endl<<"3、查询"<<endl<<"4、退出"<<endl;
				cout<<"请选择你需要的服务:";
				int i;
				cin>>i;
				switch(i){
					case 1:user.save();break;
					case 2:user.get();break;
					case 3:user.show();break;
					case 4:cout<<"成功退出！谢谢使用本系统!"<<endl;break;
					default:cout<<"没有此项服务"<<endl;break;
				}
				if(i==4) break;
			}
		}else{
			n--;
			if(n==0){cout<<"显然，你不知道密码!"<<endl;exit(0);}
			cout<<"您输入的密码或者用户名不正确!请重新输入！"<<endl;
			cout<<"提示:您还有"<<n<<"次机会"<<endl;
		}
	}
}