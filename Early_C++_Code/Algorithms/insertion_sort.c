#include<stdio.h>
#include<stdlib.h>

void insert_sort(int array[], int num);

int main(void)
{
	int array[10] = {23, 35, 115, 55, 12, 34, 65, 23, 6, 10};
	int i;
	insert_sort(array, 10);

	for(i = 0; i < 10; i++)
		printf("%d ", array[i]);

	printf("\n");
	exit(EXIT_FAILURE);
}

void insert_sort(int array[], int num)
{
	int i, j, now;

	for(i = 1; i < num; i++){
		now = array[i];
		j = i - 1;
		while(j >= 0 && now < array[j]){
			array[j + 1] = array[j];
			j --;
		}
		array[j + 1] = now;
	}
}
