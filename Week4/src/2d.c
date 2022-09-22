#include <stdio.h>
<<<<<<< Updated upstream
void oneD(int *a, int size){
	for (int i = 0; i < size; i++){
		//printf("%d\t", a[i]);
		printf("%d\t", *(a+i));
	}
	printf("\n");
}
void twoD(int rows, int cols, int *b){
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			//printf("%d\t", b[i][j]);
			printf("%d\t", *(b + cols*i + j));
		}		
		printf("\n");
	}
}
int main(){
	int a[] = {1,2,3,4,5};
	int b[4][3] = {{1,2,3},{6,7,8},{11,12,13},{16,17,18}};
	
	int size_a = sizeof(a)/sizeof(a[0]);
	oneD(&a[0], size_a);
	
	int size_b_rows = sizeof(b)/sizeof(b[0]);
	int size_b_cols = sizeof(b[0])/sizeof(b[0][0]);
=======
void oneD(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d\t", a[i]);
		// printf("%d\t", *(a+i));
	}
	printf("\n");
}
void twoD(int rows, int cols, int b[rows][cols])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%d\t", b[i][j]);
			// printf("%d\t", *(*(b + cols*i + j)));
		}
		printf("\n");
	}
}
int main()
{
	int a[] = {1, 2, 3, 4, 5};
	int b[4][3] = {{1, 2, 3}, {6, 7, 8}, {11, 12, 13}, {16, 17, 18}};

	int size_a = sizeof(a) / sizeof(a[0]);
	oneD(a, size_a);

	int size_b_rows = sizeof(b) / sizeof(b[0]);
	int size_b_cols = sizeof(b[0]) / sizeof(b[0][0]);
>>>>>>> Stashed changes
	printf("b_row_size: %d\t b_col_size: %d\n", size_b_rows, size_b_cols);
	twoD(size_b_rows, size_b_cols, &b[0][0]);
	return 0;
}