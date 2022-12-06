#include <stdio.h>
int main(){
	char *str = "MIPS is awesome!";
	int i = 0, size = 0;
	while (str[i] != 0){
		size++;
		i++;
	}
	printf("Size of the string is: %d\n", size);
	return 0;
}