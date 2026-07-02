#include<stdio.h>
# define SIZE 4
// Write program that computes the product of the elements that are stored on the diagonal above the main diagonal.

int main() {
  int matrix[SIZE][SIZE] = {
      {5, 10, 15, 2},
      {25, 30, 35, 5},
      {45, 50, 55, 6},
      {45, 50, 55, 6}};

  int product=1;

  for (int i = 0; i < SIZE; i++)
  {
    for (int j = i+1; j < SIZE; j++)
    {
      product *= matrix[i][j];
    }
  }

  printf("Product: %d",product);
  
  return 0;
}