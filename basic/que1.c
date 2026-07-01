#include<stdio.h>

// Write a program to read 10 integers.
// Display these numbers by printing three numbers in a line separated by commas.

int main(){
  int a[10], i=0;

  // 1. Read 10 integers form the users.
  printf("Enter 10 integer: ");
  for(i=0; i<10; i++)
  scanf("%d",&a[i]);

  printf("\nDisplaying numbers (3 per line):\n");

  // 2. Display the numbers.
  for(i=0; i<10; i++){
    printf("%d",a[i]);

    // If it's multiple of 3, printf a newline.
    if((i+1)%3 == 0){
      printf("\n");
    }
    // Otherwise, separate numbers in the same row with a comma and tab.
    else {
      printf(",\t");
    }
  }

  return 0;
}