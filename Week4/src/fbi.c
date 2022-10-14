#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20 // size indicates total number of location numbers. 
void write(char *file){
	// write to file
	FILE *fp = fopen(file, "w+"); // w+ is for write mode for file writing
	int upper = 100000, lower = 10001;
	srand(time(0));
	for (int i = 1; i <= SIZE; i++){
		int location = (rand() / (double)RAND_MAX) * (upper - lower) + lower;
		if (i % 5 == 0 && (i > 1 && i < SIZE))
			fprintf(fp, "%d\n", location);	
		else
			fprintf(fp, "%d\t", location);	
	}
    fclose(fp);
}
void load(char *file, int *arr){
	// load all the locations (lat/long) from the file into the array arr. 
	int c = 0;
	int location = 0;
	int index = 0;
	FILE *fp = fopen(file, "rb"); // rb is for read mode for file reading
	while ((c=fgetc(fp)) != EOF) { // fgetc is for getting characters from file directly than std stream. 
        // develop your logic here to build each location and add it to the array.
 		if (c == '\t' || c == '\n') { /* Check for error in input */
			*(arr + index) = location;
			location = 0;
			index++;
 		}
 		else{
			 int digit = c -'0';
			 location = 10* location + digit;
		}
 	}
}
void transform(int *arr, int *twod, int rows){
	
	for(int i = 0; i < rows;i++){
		for(int j = 0; j < SIZE; j++){
			if (*(twod + 2*i) == *(arr + j)){
					*(twod + 2*i + 1) = *(twod + 2*i + 1) + 1;
			}
		}
	}

}
void report1(int *arr){
	
	for(int i = 0; i < SIZE;i++){
		printf("%d\t", *(arr + i));
	}
	printf("\n");
	
	
}

void report2(int *twod, int rows){
	
	for(int i = 0; i < rows;i++){
		printf("%d\t%d\n", *(twod + 2*i), *(twod + 2*i + 1));
	}
	
}
void identifySuspect(int *twod, int rows){
	int high_count = 0;
	int suspect_location = 0;
	/* add logic here */
	for(int i = 0; i < rows;i++){
		if (*(twod + 2*i + 1) > high_count){
			high_count = *(twod + 2*i + 1);
			suspect_location = *(twod + 2*i);
		}
	}
	printf("Suspect may be in: %d\n", suspect_location);
}
int main(){
	char *file = "data.txt";
	int *arr = (int *) malloc(SIZE*sizeof(int)); //dynamic array
	int zips = 5;
	int twod[5][2] = {{10001,0},{10002,0},{10003,0}, {10004,0}, {10005,0}};  // static array
	write(file);
	load(file, arr);
	printf("----------------------------------------------\n");
	report1(&arr[0]);
	printf("----------------------------------------------\n");
	transform(arr, &twod[0][0], zips);
	report2(&twod[0][0], zips);
	printf("----------------------------------------------\n");
	identifySuspect(&twod[0][0], zips);
	return 0;
}