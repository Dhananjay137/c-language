#include<stdio.h>

int a = 3;

int f(int* p,int n);
int max(int a,int b);

void m(int *y);
void n(int *x);

void foo(char *a);

void test();
int testVal = 5;

void fun(int*, int*);
int i=0, j=1;

int fun2(int n, int *fp);
int count = 0;

int main(){
  int x = 15;
  printf("%d\n",fun2(5,&x));
  printf("count: %d\n",count);
  return 0;
}

int fun2(int n, int *fp){
  int t,f;
  if(n<=1){
    *fp = 1;
    
    return 1;
  }

  t = fun2(n-1,fp);
  f = t + *fp;
  *fp = t;
  
  return f;
}

void fun(int *p, int *q){
  printf("address of p: %d\n",p);
  printf("address of q: %d\n",q);
  p=q;
  printf("address of p after change: %d\n",p);
  *p=2;
}

void test(){
  printf("test value in test fun: %d\n",testVal);
  testVal += 10;
}

void foo(char *a){
  if(*a && *a != ' '){
    foo(a+1);
    putchar(*a);
  }
  
}

void m(int *y){
  int a = 1;
  printf("\ny: %d",y);
  printf("\ny by dereference: %d",*y);
  
  a = *y - a; 
  n(&a);
  printf("%d",a);
}

void n(int *x){
  *x = *x * a;
  printf("\n%d * %d",*x,a);
  printf("\n%d",*x);
}

int max(int a,int b){
  if(a>=b) return a;
  else return b;
}

int f(int* p,int n){
  if(n<=1) return 0;
  else return max(f(p+1,n-1),p[0]-p[1]);
}