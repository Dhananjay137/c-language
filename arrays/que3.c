#include<stdio.h>
// Write program to interchange the second element with the second last element.

int main() {
  int arr[10] = {1,2,3,4,5,6,7,8,9,20};
  int len = sizeof(arr)/sizeof(arr[0]);

  for (int i = 0; i < len; i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");

  arr[1] = arr[1] + arr[len-2];
  arr[len-2] = arr[1] - arr[len-2];
  arr[1] -= arr[len-2];

  for (int i = 0; i < len; i++)
  {
    printf("%d ",arr[i]);
  }
  
  
  return 0;
}