#include"head.h"
#include"student.h"

int main(void){
	student stu;//新建一个student对象
	cout<<"欢迎来到学生成绩管理系统"<<endl;
	int n=0;
	//操作选项列表
	while(1){
		cout<<"1、浏览 2、添加 3、删除 4、查询 5、修改 6、退出 "<<endl;
		cout<<"请选择你要的服务: ";
		cin>>n;
		switch(n){
		case 1:stu.scan();break;		//浏览
		case 2:stu.add();break;			//添加
		case 3:stu.deleteStu();break;	//删除
		case 4:stu.find();break;		//查询
		case 5:stu.change();break;		//修改
		case 6:break;					//退出
		default: cout<<"这不是可用服务!!!"<<endl;break;
		}
		if(n == 6) {cout<<"Bye!"<<endl;break;}
	}
	return 0;
}

