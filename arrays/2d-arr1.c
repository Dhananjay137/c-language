#include<stdio.h>

void fun(int arr[]);

int main(){
  
  int arr[][3] = {{4,12,56},{39,88,47}};
  //printf("%d",*(arr[0]+2));
  // printf("%d",*(*arr+0));
  printf("%d",*arr[1]);
  //fun(arr[-1]);

  int b[] = {1,6,8};
  // for(int i=0; i<6; i++)
  //   printf("%d ",*(*arr+i));

  //printf("%d",*b+1);

  // for(int i=0; i<2; i++){
  //   printf("\n");
  //   for(int j=0; j<3; j++)
  //     printf("%d ",arr[i][j]);
  // }
  return 0;
}

void fun(int arr[]){
  for(int i=0; i<3; i++)
    printf("%d ",&arr[i]);
}