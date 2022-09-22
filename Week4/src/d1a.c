#include <stdio.h>
#include <stdlib.h>
void filler(int *arr1, int size)
{
	for (int i = 0; i < size; i++)
	{
		*(arr1 + i) = i;
	}
}
void display(int *arr1, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d\n", *(arr1 + i));
	}
}
int main()
{
	int size = 10;
	int *arr1 = (int *)malloc(size * sizeof(int));
	filler(arr1, size);
	display(arr1, size);
	return 0;
}