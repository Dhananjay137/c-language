#include<stdio.h>
int temp = 20;

int fun(int start, int end);

void fun2(int i, int j);

void fx();

int funcp();

int pp(int a, int b);
int tob(int b, int* arr);

int bar(int n);
int foo(int n);

int r();

int count(int x,int y);

void convert(int n);

int jumble(int x, int y);

void fun3();

int (*fun4)(int *);
int *fun5(int *);
int fun6(int x);

int total (int v);

int foo2(int val );
int bar2(int val );

int main() {
  // int v =foo2(3);
  // printf("\nv: %d",v);

  int v2 = bar2(3);
  printf("\nv: %d",v2);
  
  return 0;
}

int foo2(int val ) {
  int x = 0;
  while (val > 0) {
    printf("%d",val);
    x = x + foo(val--);
  }
  return val ;
}
int bar2(int val ) {
  int x = 0;
  while (val > 0) {
    x = x + bar(val-1);
  }
  return val ;
}

int total (int v) {
  int count = 0;
  while (v) {
    count += v & 1;
    v >>= 1;
  }
  return count;
}

void fun3(){
  static int temp=10;
  printf("%d ",temp);
}

int count(int x, int y){
  static int c = 0;
  static int d = 0;
  if(y!=1) {
    if(x!=1) {
      //printf("*");
      c++;
      return count(x/2,y);
    } else {
      d++;
      printf("\n%d",d);

      y=y-1;
      return count(1024,y);
    }
  }
  return c;
}

int jumble(int x,int y){
  x = 2*x+y;
  return x;
}

void convert(int n){
  if(n<0){
    printf("%d",n);
  } else {
    convert(n/2);
    printf("%d",n%2);
  }
}

int r(){
  int static num = 7;
  return num--;
}

int pp(int a, int b){

  int arr[20];
  int i, tot=1, ex, len;
  ex = a;

  printf("a: %d, b: %d",a,b);
  len = tob(b, arr);
  printf("\nlen: %d",len);

  for(i=0; i<len; i++){
    printf("\na[%d]: %d",i,arr[i]);
    if(arr[i] == 1)
      tot=tot*ex;
    ex = ex * ex;
  }

  return tot;
}

int tob(int b, int* arr){
  int i;
  //printf("\nb in tob: %d",b);
  for(i=0; b>0; i++){
    //printf("\nb in tob at %dth: %d",i,b);
    if(b%2){
       arr[i]=1;
    } else {
      arr[i] =0;
    }
    b=b/2;
  }
  //printf("\ni in tob: %d",i);
  return i;
}

int funcp(){
  static int x=1;
  x++;
  return x;
}

void fx(){
  char a;
  if((a=getchar()) != '\n')
    fx();
  if(a != '\n')
  putchar(a);
}

void fun2(int i, int j){
  if(i<j){
    int i =0;
    while(i<10){
      j+=2;
      i++;
    }
  }
  printf("j: %d",j);
  printf("i: %d",i);
}

int fun(int start, int end){
  int length = end + 1 - start;
  printf("\nstart: %d, end: %d length%%3: %d",start,end,length%3);

  if((length<1) || (start<0) || (end<0)) return 0;
  if(length%3 == 0) {
    return fun(start+1, end);
  } else if(length%3 == 1) {
    return (1 + fun(start, end-1));
  } else {
    return fun(start+2, end);
  }
}

int bar(int n){
  if(n==1) return 0;
  else return 1+bar(n/2);
}

int foo(int n){
  if(n==1) return 1;
  else return 1+foo(bar(n));
}