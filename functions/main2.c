#include<stdio.h>

void swap(int *a,int *b);
void swap2(int *a,int *b);

double test(double);

int main(){
  // int i=0,val;
  // val = ++i%2;
  // printf("val: %d",val);

  int x=4,y=34;
  // printf("befor swap -> x: %d, y: %d\n",x,y);
  // swap(&x,&y);
  // printf("after swap -> x: %d, y: %d\n",x,y);

  // swap2
  //swap2(&x,&y);

  // double val = test(44);
  // printf("%f",val);

  printf("%d",2048/10);
  return 0;
}

double test(double a){
  return a++;
}

void swap2(int *a,int *b){
  printf("a: %d\n",a);
  printf("b: %d\n",b);
 
  printf("a: %d\n",a);
}

void swap(int *a,int *b){
  static int *temp;

  printf("Before swap -> a: %d, b: %d\n",*a,*b);
  temp = a;
  printf("temp after assign form a: %d\n",temp);
  a = b;
  b = temp;
  printf("after swap -> a: %d, b: %d\n",*a,*b);
  //printf("temp at last: %d\n",temp);
}