#include<stdio.h>
// Write a program to print 'Programming in c is Fun' using pointers.

int main() {
  // Allocate a character array to store the string literal.
  char text[] = "Programming in c is Fun.";

  // Declare a pointer variable that can hold the memory address of char.
  char *ptr;

  // Assign the memory address of the first character of the array to ptr.
  ptr = text;
  
  // Loop runs as long as the character inside the current memory address is NOT '\0' (null)
  while (*ptr)   
  {
    // Dereference the pointer (*ptr) to print the actual character stored at that address
    printf("%c",*ptr);

    // Increment the pointer to move to the next character's memory address
    ptr++;
  }

  return 0;
}