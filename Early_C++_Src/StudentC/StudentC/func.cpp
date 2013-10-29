#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define MAX_LINE 20

void flush(){
	char ch;
	while((ch = getc(stdin)) !='\n'){
		continue;
	}
}

void print(){
	FILE *p;
	int ch;

	if( (p = fopen("liu.txt","r")) == NULL){
		printf("Can't open this file\n");
		exit(1);
	}
	while((ch = getc(p)) != EOF){
		putc(ch,stdout);
	}
	if(fclose(p) != 0){
			fprintf(stderr,"Error in closing files\n");
	}
}

void add(){
	FILE *p;
	long length;
	char *file;
	char line[MAX_LINE];
	char s[MAX_LINE];
	if((p = fopen("liu.txt","r")) == NULL){
		printf("Can't open this file\n");
		exit(1);
	}
/*	while( fgets(line,MAX_LINE,stdin) != NULL && line[0] !='\n'){
		fputs(line,p);
	}
*/	
	*line = 0;
	printf("请输入学生编号: ");
	gets(s);
	strcat(line,s);
	strcat(line," ");

	printf("请输入学生姓名: ");
	gets(s);
	strcat(line,s);
	strcat(line," ");

	printf("请输入学生成绩: ");
	gets(s);
	strcat(line,s);
	strcat(line," ");

	fseek(p,0l,SEEK_END);
	length = ftell(p);
	file = (char *) malloc(sizeof(char) * (length+MAX_LINE));
	*file = 0;
	rewind(p);

	int count = 0;
	while(fgets(s,MAX_LINE,p) != NULL){
		
		if(count ==0 && (atoi(s) > atoi(line)) ){
			strcat(file,line);
			strcat(file,"\n");
			count = 1;
		}
		if(atoi(s) == atoi(line)){
			printf("已经有了学生%d了,不能重复插入!!!\n",atoi(s));
			return ;
		}
		strcat(file,s);
	}
	if(count == 0){
		strcat(file,line);
		strcat(file,"\n");
	}

	if(fclose(p) != 0){
		fprintf(stderr,"Error in closig files");
	}
	p = fopen("liu.txt","w");
	fputs(file,p);
	
	if(fclose(p) != 0){
		fprintf(stderr,"Error in closig files");
	}

}

void Delete(){
	FILE *newF;
	int n=0,tempN=0;
	long length;
	char *file;
	char hang[MAX_LINE];

	printf("Please input the num  that you want to delete: ");
	if(scanf_s("%d",&n) !=1){
		n=-1;
	}
	flush();
	if(n==-1){return ;}

	if( (newF = fopen("liu.txt","r")) == NULL){
		printf("Cant't open this file\n");
	}

	fseek(newF,0l,SEEK_END);
	length = ftell(newF);
	file = (char *) malloc(sizeof(char) * length);
	*file = 0;
	rewind(newF);


	while( fgets(hang,MAX_LINE,newF) != NULL){
		if(n == atoi(hang)){
			continue;
		}
		strcat(file,hang);
	}

	if(fclose(newF) != 0){
		fprintf(stderr,"Error in closig files");
	}
	
	if( (newF = fopen("liu.txt","w")) == NULL){
		printf("Can't open this file\n");
	}
	fputs(file,newF);
	if(fclose(newF) != 0){
		printf("something wrong to open this file\n");
	}
}

void find(){
	FILE *pf;
	int n;
	char line[MAX_LINE];
	printf("Plesse input the number you want to see: ");
	scanf("%d",&n);
	flush();

	if( (pf = fopen("liu.txt","r")) == NULL){
		printf("Can't open this file\n");
	}

	while(fgets(line,MAX_LINE,pf) != NULL){
		if(n == atoi(line) ){
			printf("find if !!!\n");
			puts(line);
			return ;
		}
	}
	printf("Can't find\n");
}