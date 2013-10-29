#include<stdio.h>
#include<malloc.h>
int main()
{
	int num=10;
	unsigned int size;
	size=sizeof(int);
	void *pt;
	void *i_calloc(size_t num_elements,size_t element_size);
	pt=i_calloc(num,size);
	return 0;
}

void *i_calloc(size_t num_elements,size_t element_size)
{
	int i;
	int *pt,*pi;
	pt=pi=(int *)malloc(num_elements*element_size);
	for(i=0;i<num_elements;++i)
	{
		pi=(pt+i);
		pi=NULL;
	}
	return pt;
}