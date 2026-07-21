#include<stdio.h>
#include<string.h>

void reverse_str(char *str);

int main() {
  char name[20] = "jay";
  
  reverse_str(name);
  return 0;
}

void reverse_str(char *str){
  // Base case
  if (*str == '\0') return;
  
  reverse_str(str+1);
  
  putchar(*str);
}