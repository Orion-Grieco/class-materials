#include <stdio.h>
typedef struct student{
	int studentid;
	float studentgpa;
	char *studentname;
} stud;
int main(){
	stud s[5];
	s[0].studentid = 101;
	s[0].studentname = "S1";
	s[0].studentgpa = 3.5;

	s[1].studentid = 102;
	s[1].studentname = "S2";
	s[1].studentgpa = 3.6;
	
	s[2].studentid = 103;
	s[2].studentname = "S3";
	s[2].studentgpa = 3.7;
	
	s[3].studentid = 104;
	s[3].studentname = "S4";
	s[3].studentgpa = 3.8;
	
	s[4].studentid = 105;
	s[4].studentname = "S5";
	s[4].studentgpa = 3.9;
	
	int size = sizeof s / sizeof s[0];
	for (int i  = 0; i < size; i++){
		printf("%d\t%f\t%s\n", s[i].studentid, s[i].studentgpa, s[i].studentname);	
	}


	return 0;
}