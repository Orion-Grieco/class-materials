/*
Why dynamic array? How is this different from variable length array?
-- Variable length array is stored in Stack.
-- Dynamic array using malloc is stored in Heap. More space compared to Stack!
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
  int size;
  printf("Enter the size of the array:");
  scanf("%d", &size);

  // This code below is for variable length array!*/

  int array[size];
  printf("#created array\n");

  for (int i = 0; i < size; i++)
    array[i] = 10 * i;
  for (int i = 0; i < size; i++)
    printf("%d\t", array[i]);
  printf("\n");

  // creating the memory block to store the dynamic array!
  /*
  int *arr1 = (int *)malloc(size * sizeof(int));

  // assigning values to each element in the array
  for (int i = 0; i <  size; i++)
    *(arr1+i) =  10*i;

  // printing values inside each element in the array
  for (int i = 0; i <  size; i++)
    printf("%d\t", arr1[i]);

  printf("\n");
  free(arr1);
  */

  return 0;
}
