#include<stdio.h>

int main() {
  int x =1, y=2, z=3;

  // y = y+1;
  // z = x+y;
  // x = x+1;

  z = (x++) + (++y);

  
  printf("x: %d",x);
  printf("\ny: %d",y);
  printf("\nz: %d",z);
  
  return 0;
}