#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_COLS 20
#define MAX_INPUT 1000
int read_column_number(int columns[],int max);
void rearrange(char *output,char const *input,
	int n_columns,int const columns[]);
int main(void)
{
	int n_columns;
	int columns[MAX_COLS];
	char input[MAX_INPUT];
	char output[MAX_INPUT];
	n_columns=read_column_number(columns,MAX_COLS);
	while(gets_s(input)!=NULL)
	{
		printf("Original input : %s\n",input);
		rearrange(output,input,n_columns,columns);
		printf("rearrange line : %s\n",output);
	}
	return EXIT_SUCCESS;
}
int read_column_number(int columns[],int max)
{
	int num=0;
	int ch;
	while(num<max && scanf_s("%d", &columns[num])==1
		&& columns[num]>=0)
		num+=1;
	if(num%2!=0)
	{
		puts("Last column number is out paired.");
		exit(EXIT_FAILURE);
	}
	while((ch=getchar())!=EOF &&ch!='\n');
	return num;
}
void rearrange(char *output,char const *input,
	int n_columns,int const columns[])
{
	int col;
	int output_col;
	int led;
	led=strlen(input);
	output_col=0;
	for(col=0;col<n_columns;col+=2)
	{
		int nchars=columns[col+1]-columns[col]+1;
		if(columns[col]>=led||
			output_col==MAX_INPUT-1)
			break;
		if(output_col+nchars>MAX_INPUT-1)
			nchars=MAX_INPUT - output_col-1;
		for(int i=output_col,j=columns[col],k=0;k<nchars;++i,++j,++k)
			*(output+i)=*(input+j);
		output_col+=nchars;
	}
	output[output_col]='\0';
}
