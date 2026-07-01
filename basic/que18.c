#include<stdio.h>
// Write a program to add three floating point numbers.
// The result should contain only two digits after the decimal.

int main() {
  float a=4.4, b=23.4234, c= 2.332, sum;

  sum = a+b+c;

  printf("sum of three floating point number: %.2f\n\n",sum);

  return 0;
}