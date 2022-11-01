#include <stdbool.h> 
#include <stdio.h>
void printline(){
  for(int i =0; i < 50; i++){
    printf("-");
  }
  printf("\n");
}
void start(){
  int first = 0;
  int second = 0;
  int third = 0;
  printf("Is it raining? (1 for yes; and 0 for no)\n");
  scanf("%d", &first);
  printf("Do you have an umbrella? (1 for yes; and 0 for no)\n");
  scanf("%d", &second);
  printf("Do you have a raincoat? (1 for yes; and 0 for no)\n");
  scanf("%d", &third);
  if (first && (second && third)){
    printf("get ready to leave\n");
  }
  else if (first && (second||third)){
    printf("avoid getting wet!\n"); 
  }
  else if (first && !(second||third)){
    printf("stay home\n"); 
  }
  else if (!first){
    printf("no rain, have fun!\n"); 
  }

}

int main(){
  printf("Welcome to the logic gates program\n");
  printline();
  start();

  return 0;
}