#include<stdio.h>
#include<stdlib.h>
void merge_sort(int array[], int num);

int main(void)
{
	int array[10] = {12, 23, 43, 23, 65, 765, 56, 34, 87, 200};
	int i;

	merge_sort(array, 10, 0, 9);

	for(i = 0; i < 10; i++)
		printf("%d ", array[i]);
	printf("\n");

	exit(EXIT_FAILURE);
}

void merge_sort(int array[], int num)
{
