# include "stdio.h"
#include<malloc.h>
#include<conio.h>

struct student
{
  char num;
  struct student *list;
};
struct student *in()
{
  struct student *h,*p1,*p2;
  
  h=p1=(struct student*)malloc(sizeof(struct student));
  p2=(struct student*)malloc(sizeof(struct student));
  printf("please input interger\n");
  char a='a';
  while( a!='!')
  {
  scanf_s("%c",&a);
p2=(struct student*)malloc(sizeof(struct student));
  p1->num=a;
  p1->list=p2;
  p1=p2;
    

  
  }
  printf("\n");
p1->list=NULL;
  return h;
}

int main ()
{
	struct student *l;
l=in();
while(l)
{
printf("%c",l->num);
l=l->list;
}
return 0;
}