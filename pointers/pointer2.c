#include<stdio.h>
#include<string.h>

int main(){
  // static int a[] = {10,20,30,40,50};
  // static int *p[] = {a,a+3,a+4,a+1,a+2};

  // int **ptr = p;
  // ptr++;

  // printf("arr p: %d\n",**p);
  // printf("arr ptr: %d\n",**ptr);
  // printf("%d-%d: %d %d\n",ptr,p,ptr-p,**ptr);

  // int arr[3][3] ={{1,2,3},{4,5,6},{10,20,30}};
  // printf("%d %d %d\n",arr+3,*(arr+3),*(arr+2)+3);
  // for(int i=0; i<9; i++){
  //   printf("%d ",(*arr+i));
  // }
  // printf("\n");
  // printf("%d",&arr[2][0]);

  // int i;
  // int *pi = &i;
  // scanf("%d",pi);
  // printf("%d\n",i+5);

  // char a[2][3] = {{'a', 'b', 'c'},{'d', 'e', 'f'}};
  // char b[3][2];
  // char *p = *b;
  // printf("%c %c\n",**a,**(a+1));

  // int arr[3][3] ={{1,2,3},{4,5,6},{10,20,30}};
  // printf("%d %d\n",**arr,**(arr+2));

  char a[6] = "World";
  //printf("%s",a);

  // int i, j;
  // for(i = 0, j = 5; i < j; a[i++] = a[j--]);

  // printf("%s\n", a);

  // int arr[4]={1,2,3,4};
  
  // for(int i=0,j=3; i<j; arr[i++] = arr[j--]);
  // for(int i=0; i<4; i++){
  //   printf("%d ",arr[i]);
  // }
  printf("A TO Z: %d to %d\n",'A','Z');
  printf("a TO z: %d to %d\n",'a','z');
  char *s="string";
  printf("%s\n",s);
  printf("length of s: %d\n",strlen(s));
  return 0;
}