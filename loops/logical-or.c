#include<stdio.h>

// Logical OR operator evaluates left condition first.
// If the left condition evaluates to true, the entire || expression is guaranted to be true.
// Therefore, the computer skips evaluating the right condition entirely to save time.
// The code on the right side doesn't run at all.

int main() {
  int x=0, y=0;
  for(int z=0; z<5; z++){
    if((++x>2) || (++y>2)){
      x++;
    }
  }
  printf("%d %d",x,y);

  return 0;
}