#include<stdio.h>
// Write a program to input the elements of two dimensional array.
// Then from this array, make two arrays one that stores all odd elements of the two-dimensional array and other that stores all even elements of the array.

int main() {
  int rows, cols;

  // Input dimensions of the 2D array
  printf("Enter number of rows: ");
  scanf("%d",&rows);
  printf("Enter number of columns: ");
  scanf("%d",&cols);

  int arr[rows][cols];
  int evenCount=0, oddCount=0;

  // Input elements of the 2D array and count even/odd elements
  printf("\nEnter elements of %dx%d array\n",rows,cols);
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      printf("Element [%d][%d]: ",i,j);
      scanf("%d",&arr[i][j]);

      // Count to determine the sizes of the 1D arrays
      if(arr[i][j] % 2 == 0){
        evenCount++;
      } else {
        oddCount++;
      }
    }
  }

  // Declare 1D arrays based on the counts
  int evenArray[evenCount];
  int oddArray[oddCount];

  int eIdx=0; // Index tracker for evenArray
  int oIdx=0; // Index tracker for oddArray

  // Separate the elements into respective 1D arrays
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if(arr[i][j]%2 == 0){
        evenArray[eIdx++] = arr[i][j];
      } else {
        oddArray[oIdx++] = arr[i][j];
      }
    }
  }

  // Print the results
  printf("\n--- Results ---\n");
    
  printf("Even elements array: ");
  if (evenCount == 0) {
    printf("None");
  } else {
    for (int i = 0; i < evenCount; i++) {
      printf("%d ", evenArray[i]);
    }
  }
  printf("\n");
    
  printf("Odd elements array: ");
  if (oddCount == 0) {
    printf("None");
  } else {
    for (int i = 0; i < oddCount; i++) {
      printf("%d ", oddArray[i]);
    }
  }
  printf("\n");
  
  return 0;
}