#include<stdio.h>
int main() {
  int a=54, b=33;

  a = a + b;
  b = a - b;
  a = a - b;

  printf("a: %d",a);
  printf("\nb: %d",b);
  return 0;
}