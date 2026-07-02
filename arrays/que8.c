#include <stdio.h>
// Write program to add two 3*3 matrix using pointers.

#define SIZE 3

int main()
{
  int total_elements = SIZE*SIZE;

  int matrix1[SIZE][SIZE] = {
      {5, 10, 15},
      {25, 30, 35},
      {45, 50, 55}};
  
  int matrix2[SIZE][SIZE] = {
      {5, 10, 15},
      {25, 30, 35},
      {45, 50, 55}};
  
  int result[SIZE][SIZE];
  
  int *ptr1 = &matrix1[0][0];
  int *ptr2 = &matrix2[0][0];
  int *ptr3 = &result[0][0];

  for (int i = 0; i < total_elements; i++)
  {
    *ptr3++ = *ptr1++ + *ptr2++;
  }
  
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      printf("%d ",result[i][j]);
    }
    printf("\n");
    
  }
  
  return 0;
}