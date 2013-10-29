#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define NULL 0
typedef struct ta_tag{
	ta_tag *next;
	int pos;
}ta;

ta *create(int n,ta *head){
	ta *p1=(ta *) malloc(sizeof(ta));
	p1=head;
	if(p1==NULL){printf("p1创建失败!!!");exit(0);}

	ta *p2=(ta *) malloc(sizeof(ta));
	p2=head;
	if(p2==NULL){printf("p2创建失败!!!");exit(0);}

	p1->pos=n;
	for(int i=1;i<n;++i){
		p1->next = ++p2;
		p1=p2;
		p1->pos = n-i;
	}
	p1->next=NULL;
	return head;
}

int main(void){
	ta *taX;
	ta *taY;
	ta *taZ;
	int n=0;

	printf("***************汉诺塔问题*****************\n");
	printf("请输入盘数目: ");
	scanf("%d",&n);

	taX = (ta *) malloc(n*sizeof(ta));
	if(taX==NULL) {printf("塔X创建失败!!!\n");exit(0);}
	taX=create(n,taX);

	taY = (ta *) malloc(sizeof(ta));
	if(taY==NULL) {printf("塔Y创建失败!!!\n");exit(0);}

	taZ = (ta *) malloc(sizeof(ta));
	if(taZ==NULL) {printf("塔Z创建失败!!!\n");exit(0);}

//	void hanoi(int n,ta *taX,ta *taY,ta *taZ);
//	hanoi(n,taX,taY,taZ);
//	ta *create(ta head);
	if(taZ==NULL){printf("没有数据!\n");return 0;}
	printf("数据为:\n");
	while(taZ!=NULL){
		printf("%d ",taZ->pos);
		taZ = taZ->next;
	}
	printf("结束!\n");
	return 0;
}

void hanoi(int n,ta *taX,ta *taY,ta *taZ){
	void move(ta *taX,int pos,ta *taZ);
	if(n==1){
		move(taX,1,taZ);
	}else {
		hanoi(n-1,taX,taZ,taY);
		move(taX,n,taZ);
		hanoi(n-1,taY,taX,taZ);
	}
}

void move(ta *taX,int n,ta *taZ){
	ta *p = (ta *) malloc(sizeof(ta));
	taZ->next =p;
	p->pos = (taX+n-1)->pos;
	p->next = NULL;

	free(taX+n);
}