#include <stdio.h>
int main(){
	int temp = 0;
	printf("Enter the current temperature:\n");
	scanf("%d", &temp);
	if (temp >= 65)
		printf("hot\n");
	else 
		printf("cold\n");
	return 0;
}