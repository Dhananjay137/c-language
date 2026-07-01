#include<stdio.h>
#include <ctype.h>
// Write a program to read a character and print it.
// Also print its ASCII value.
// If the character is in lower case, printf it in upper case and vice versa.
// Repaat the process until a '*' is entered.

int main() {
  char c;
    
  while (1){
    printf("Enter character: ");
    scanf(" %c", &c);

    if (c == '*') {
      printf("Exit character detected. Goodbye!\n");
      break;
    }

    printf("  -> Character                  : %c\n",c);
    printf("  -> ASCII value                : %d\n",c);

    if(c>='a' && c<='z') 
      printf("  -> Converted to Uppercase: %c\n\n",toupper(c));
    else if(c>='A' && c<='Z')
      printf("  -> Converted to Lowercase: %c\n\n",tolower(c));
    else
      printf("  -> (Not a letter, cannot flip case)\n\n");

  }
  
  return 0;
}