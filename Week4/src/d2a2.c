#include <stdio.h>
#include <stdlib.h>
void filler(int **arr2, int rs, int cs)
{
	int count = 0;
	for (int i = 0; i < rs; i++)
	{
		for (int j = 0; j < cs; j++)
		{
			*(*(arr2 + i) + j) = count;
			count++;
		}
	}
}
void display(int **arr2, int rs, int cs)
{
	for (int i = 0; i < rs; i++)
	{
		for (int j = 0; j < cs; j++)
		{
			printf("%d\t", *(*(arr2 + i) + j));
		}
		printf("\n");
	}
}
int main()
{
	int rs = 4, cs = 4;
	int *arr2[rs];
	for (int i = 0; i < rs; i++)
		*(arr2 + i) = (int *)malloc(cs * sizeof(int));

	filler(&arr2[0], rs, cs);
	display(&arr2[0], rs, cs);
	return 0;
}