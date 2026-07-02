#include<stdio.h>
// Write program to read an array of 10 integers
// Display all the pairs of elements whose sum is 50.

int main() {
  int n=10, arr[10], i;

  for ( i = 0; i < n; i++)
  {
    printf("Enter the number %d: ",i+1);
    scanf("%d",&arr[i]);
  }

  for ( i = 0; i < n; i++)
  {
    for (int j = i+1; j < n-1; j++)
    {
      if(arr[i] + arr[j] == 50)
        printf("arr[%d] = %d & arr[%d] = %d\n",i,arr[i],j,arr[j]);
    }
  }
  
  


  return 0;
}