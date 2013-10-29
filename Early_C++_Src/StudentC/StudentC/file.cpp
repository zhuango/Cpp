#include<stdio.h>
//#include<
#include "func.h"
int main(int argc,char *argv[]){
	char n;
	while(1){
		printf("******学生信息管理系统*****\n");
		printf("*1、添加         2、删除  *\n");
		printf("*3、浏览         4、查询  *\n");
		printf("*5、退出                  *\n");
		printf("***************************\n");
		printf("请选择您需要的服务:  ");
		n = getc(stdin) ;
		flush();
		if(n<'1' || n>'5'){
			printf("Please input the right comend!\n");
			continue;
		}
		switch(n){
			case '1':add();	break;
			case '2':Delete();break;
			case '3':print();	break;
			case '4':find();	break;
			default:break;
		}
		if(n=='5'){
			printf("Bye!\n");
			break;
		}
	}
	return 0;
}