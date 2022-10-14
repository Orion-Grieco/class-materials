#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void m1(int *beta, int alpha){
	for (int i = 0; i < alpha; i++){
		*(beta + i) = i+1;		
	}
}
void m2(int **delta, int gamma){
	for (int i = 0; i < gamma; i++){
		*(delta + i) = (int *) malloc(gamma*sizeof(int));
	}
}
void m3(int **delta, int *beta, int gamma){
	int count = 0;
	for (int i = 0; i < gamma; i++){
		for (int j = 0; j < gamma; j++){
			*(*(delta + i) + j) = *(beta + gamma*i + j);
		}
	}
}
void m4(int *beta, int alpha){
	for (int i = 0; i < alpha; i++){
		printf("%d\t", *(beta + i));		
	}
	printf("\n");
}
void m5(int **delta, int gamma){
	for (int i = 0; i < gamma; i++){
		for (int j = 0; j < gamma; j++){
			printf("%d\t", *(*(delta+i) + j));
		}
		printf("\n");
	}
}
int main(){
	int alpha = 16;
	int *beta = (int *) malloc(alpha*sizeof(int));
	int gamma = (int) sqrt(alpha);
	int *delta[gamma];
	m1(&beta[0], alpha);
	m2(&delta[0], gamma);
	m3(&delta[0], &beta[0], gamma);
	m4(&beta[0], alpha);
	m5(&delta[0], gamma);
	return 0;
}