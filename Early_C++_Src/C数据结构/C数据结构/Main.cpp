 // main1-1.cpp 检验基本操作bo1-1.cpp的主函数
#include<iostream>
using std::cout;
using std::endl;
#include"c1.h" // 要将程序中所有#include命令所包含的文件拷贝到当前目录下
 // 以下2行可根据需要选用一个（且只能选用一个），而不需改变基本操作bo1-1.cpp
 typedef int ElemType; // 定义抽象数据类型ElemType在本程序中为整型
 //typedef double ElemType; // 定义抽象数据类型ElemType在本程序中为双精度型
 #include"c1-1.h" // 在此命令之前要定义ElemType的类型
// 在此命令之前要包括c1-1.h文件（因为其中定义了Triplet）

   // bo1-1.cpp 抽象数据类型Triplet和ElemType(由c1-1.h定义)的基本操作(8个)
 Status InitTriplet(Triplet &T,ElemType v1,ElemType v2,ElemType v3)
 { // 操作结果:构造三元组T,依次置T的三个元素的初值为v1,v2和v3
   if(!(T=(ElemType *)malloc(3*sizeof(ElemType))))
     exit(OVERFLOW);
   T[0]=v1,T[1]=v2,T[2]=v3;
   return OK;
 }

 Status DestroyTriplet(Triplet &T)
 { // 操作结果：三元组T被销毁
   free(T);
   T=NULL;
   return OK;
 }

 Status Get(Triplet T,int i, ElemType &e)
 { // 初始条件：三元组T已存在，1≤i≤3。操作结果：用e返回T的第i元的值
   if(i<1||i>3)
     return ERROR;
   e=T[i-1];
   return OK;
 }

 Status Put(Triplet T,int i,ElemType e)
 { // 初始条件：三元组T已存在，1≤i≤3。操作结果：改变T的第i元的值为e
   if(i<1||i>3)
     return ERROR;
   T[i-1]=e;
   return OK;
 }

 Status IsAscending(Triplet T)
 { // 初始条件：三元组T已存在。操作结果：如果T的三个元素按升序排列，返回1，否则返回0
   return(T[0]<=T[1]&&T[1]<=T[2]);
 }

 Status IsDescending(Triplet T)
 { // 初始条件：三元组T已存在。操作结果：如果T的三个元素按降序排列，返回1，否则返回0
   return(T[0]>=T[1]&&T[1]>=T[2]);
 }

 Status Max(Triplet T,ElemType &e)
 { // 初始条件：三元组T已存在。操作结果：用e返回T的三个元素中的最大值
   e=T[0]>=T[1]?T[0]>=T[2]?T[0]:T[2]:T[1]>=T[2]?T[1]:T[2];
   return OK;
 }

 Status Min(Triplet T,ElemType &e)
 { // 初始条件：三元组T已存在。操作结果：用e返回T的三个元素中的最小值
   e=T[0]<=T[1]?T[0]<=T[2]?T[0]:T[2]:T[1]<=T[2]?T[1]:T[2];
   return OK;
 }

 void main()
 {
   Triplet T;//整型指针
   ElemType m;//整型
   Status i;//整型
   i=InitTriplet(T,5,7,9);
 //i=InitTriplet(T,5.0,7.1,9.3); // 当ElemType为双精度型时,可取代上句
   printf("调用初始化函数后，i=%d(1:成功) T的三个值为：",i);
   cout<<T[0]<<' '<<T[1]<<' '<<T[2]<<endl;
   // 为避免ElemType的类型变化的影响，用cout取代printf()。注意结尾要加endl
   i=Get(T,2,m);
   if(i==OK)
     cout<<"T的第2个值为："<<m<<endl;
   i=Put(T,2,6);
   if(i==OK)
     cout<<"将T的第2个值改为6后，T的三个值为："<<T[0]<<' '<<T[1]<<' '<<T[2]<<endl;
   i=IsAscending(T); // 此类函数实参与ElemType的类型无关,当ElemType的类型变化时,实参不需改变
   printf("调用测试升序的函数后，i=%d(0:否 1:是)\n",i);
   i=IsDescending(T);
   printf("调用测试降序的函数后，i=%d(0:否 1:是)\n",i);
   if((i=Max(T,m))==OK) // 先赋值再比较
     cout<<"T中的最大值为："<<m<<endl;
   if((i=Min(T,m))==OK)
     cout<<"T中的最小值为："<<m<<endl;
   DestroyTriplet(T); // 函数也可以不带回返回值
   cout<<"销毁T后，T="<<T<<"(NULL)"<<endl;
 }

