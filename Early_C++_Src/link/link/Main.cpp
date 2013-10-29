#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct stu_tag{
        int  i;
        stu_tag  *next;
}student;

int main(){
        int n;
        printf("清输入您要创建的链表长度\n");
        scanf("%d",&n);
        student *head = (student *) malloc(sizeof(student));
        student *p1=head;
        student *p2;
        for(int i=0;i<n;++i){
                p1->i = i;
                p2=(student *) malloc(sizeof(student));
                p1->next = p2;
                p1=p2;
                p2=p2->next;
        }
        for(int i=0;i<n;++i){
                printf("%d ",head->i);
                head=head->next;
        }
        return 0;
}

