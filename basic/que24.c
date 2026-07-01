#include<stdio.h>
// Write a program to add two floating point numbers using pointers and functions.

void add(float *,float *);

int main() {
  float x=3.5, y=4.5;
  add(&x,&y);

  return 0;
}

void add(float *a,float *b){
  printf("%f + %f = %f\n",*a,*b,*a + *b);
}
