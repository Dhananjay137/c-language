#include <stdio.h>
// Write program that computes the sum of the elements that are stored on the main diagonal of a matrix using pointers.

int main()
{
  int matrix[3][3] = {
      {5, 10, 15},
      {25, 30, 35},
      {45, 50, 55}};
  
  int *ptr = &matrix[0][0];
  int sum=0;

  int rows = sizeof(matrix)/sizeof(matrix[0]);

  for (int i = 0; i < rows; i++)
  {
    sum += *(ptr + (i*rows) + i);
  }
  
  printf("%d\n",sum);

  return 0;
}