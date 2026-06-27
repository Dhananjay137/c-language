#include<stdio.h>

int main() {
  int arr[] = {2,3,4,2,4,5,6,32,643,2};

  // for(int i = 0; i<10; i++){
  //   printf("\n%d",arr[i]);
  // }
  int k = 2;
  int *address = arr + k;
  printf("\nadd: %d",*address);
  printf("\nAddress of array: %p %p %p",arr,&arr[0],&arr);
  printf("\n%d",*(arr+2));

  return 0;
}