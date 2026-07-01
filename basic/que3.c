#include<stdio.h>
#include <ctype.h>

// Write a program to count the number of vowels in a text.

int main(){

  char text[100];
  int i=0, count=0;

  // 1. Read the text
  printf("Enter the text: ");
  scanf("%s",text);

  
  while(text[i]){
    // convert char to lower case according to base condition
    char lower_char = tolower(text[i]);

    // increment count if match condition
    if(lower_char == 'a' || lower_char == 'e' || lower_char == 'i' || lower_char == 'o' || lower_char == 'u')
      count++;

      // move to the next character
      i++;
  }

  // printf result
  printf("Number of vowels in %s is %d\n",text,count);
  
  return 0;
}