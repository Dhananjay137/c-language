#include<stdio.h>
#define n 7

int main(){
  int arr[n][n] = {0};
  int row = 2, col;

  arr[0][0] = arr[1][0] = arr[1][1] = 1;

  while(row < n){
    arr[row][0] = 1;
    for(col=1; col<=row; col++)
      arr[row][col] = arr[row-1][col-1] + arr[row-1][col];
    row++;
  }

  for(row = 0; row<n; row++){
    printf("\n");
    for(col=0; col<=row; col++)
      printf("\t %d",arr[row][col]);
  }
  return 0;
}