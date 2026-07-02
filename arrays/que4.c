#include <stdio.h>

int main()
{
  // Define a 2D array with 3 rows and 4 columns
  int matrix[3][4] = {
      {5, 10, 15, 20},
      {25, 30, 35, 40},
      {45, 50, 55, 60}};

  // Calculate dimensions dynamically
  int rows = sizeof(matrix) / sizeof(matrix[0]);       // Total size / size of one row
  int cols = sizeof(matrix[0]) / sizeof(matrix[0][0]); // Size of one row / size of one element
  int total_elements = rows * cols;

  int sum = 0;
  float mean;

  // Nested loops to traverse the 2D array
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      sum += matrix[i][j]; // Add each element to the sum
    }
  }

  // Calculate the mean (typecast sum to float to avoid integer division)
  mean = (float)sum / total_elements;

  // Print the results
  printf("Rows: %d, Columns: %d\n", rows, cols);
  printf("Total Elements: %d\n", total_elements);
  printf("Sum of all elements: %d\n", sum);
  printf("Mean of elements: %.2f\n", mean); // %.2f prints up to 2 decimal places

  return 0;
}