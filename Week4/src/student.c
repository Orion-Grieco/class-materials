#include <stdio.h>
#include <stdlib.h>
struct student
{
  int studentID;
  char *studentName;
  float studentGPA;
};

int main()
{
  struct student s1;
  struct student *s2;
  // int size = 10;
  s2 = &s1;
  // using struct directly
  s1.studentID = 1001;
  s1.studentName = "Andrew";
  s1.studentGPA = 3.8;
  // using pointer to struct

  // processing the struct
  printf("%d\t%s\t%f\n", s1.studentID, s1.studentName, s1.studentGPA);
  printf("%d\t%s\t%f\n", s2->studentID, s2->studentName, s2->studentGPA);

  s2->studentID = 1002;
  s2->studentName = "David";
  s2->studentGPA = 3.5;

  printf("%d\t%s\t%f\n", s1.studentID, s1.studentName, s1.studentGPA);
  printf("%d\t%s\t%f\n", s2->studentID, s2->studentName, s2->studentGPA);

  return 0;
}