#include<stdio.h>
// Write program to read integer.
// Display the value of that integer in decimal, octal, and hexadecimal notations.
int main() {

  int num;

  // 1. Read the integer from the user
  printf("Enter Integer: ");
  scanf("%d",&num);

  // 2. Display the value in different notations
  printf("\n--- Notation Formats ---\n");
  printf("Decimal:      %d\n",num);
  printf("Octal:        %o\n",num);
  printf("Hexadecimal:  %x (lowercase)\n",num);
  printf("Hexadecimal:  %X (uppercase)\n",num);

  // Pro-tip: Using '#' prefixes octal with '0' and hex with '0x'
  printf("\n--- With Standard Prefixes ---\n");
  printf("Octal:        %#o\n",num);
  printf("Hexadecimal:  %#X\n",num);
  
  return 0;
}