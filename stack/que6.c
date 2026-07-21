#include<stdio.h>

int fun(int, int);
int fun2(int, int);
int fun3(int, int);
int lambda(int);

int main() {

  int m=4, n=2;

  int val = fun3(m,n);
  printf("fun(%d,%d): %d",m,n,val);

  // int val = lambda(num);
  // printf("lamda(%d): %d\n",num,val);

  return 0;
}

int fun(int x, int y) {
  if (x<y) return 0;

  return fun(x-y, y) + 1;
}

// Recursive function to calculate F(n, r)
int fun2(int n, int r) {
  // Base Case 1: Invalid inputs
  if (r<0 || r>n) return 0;
  
  // Base Case 2: Terminal conditions for combination math
  if (n == 0 || r == n) return 1;
  
  // Recursive Step
  return fun2(n-1,r) + fun(n-1,r-1);
}

int fun3(int m, int n) {
  if (m == 0 || m>=n>1) return 1;

  return fun3(m-1,n) + fun3(m-1,n-1);
}

// Enter n where n>1
int lambda(int n) {
  if (n==1) return 0;

  return lambda(n/2) + 1;
}
