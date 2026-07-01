#include <stdio.h>
// Write a program that prints a floating point value in exponential format with following specification.

int main() {
  double num;

  // 1. Read a floating-point number from the user
  printf("Enter a floating-point number: ");
  if (scanf("%lf", &num) != 1) {
    printf("Invalid input.\n");
    return 1;
  }

  printf("\n--- Exponential Format Results ---\n");

  // a. Correct to 2 decimal places
  printf("2 decimal places: %.2e\n", num);

  // b. Correct to 4 decimal places
  printf("4 decimal places: %.4e\n", num);

  // c. Correct to 8 decimal places
  printf("8 decimal places: %.8e\n", num);

  return 0;
}