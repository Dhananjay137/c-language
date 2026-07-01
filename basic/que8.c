#include<stdio.h>
// Define HRA and TA as constants (10% = 0.10, 5% = 0.05)
#define HRA_RATE 0.10
#define TA_RATE 0.05
// Write program to calculate salary of an employee given his basic pay (to be entered by the user).
// HRA=10% of the basic pay, TA=5% of basic pay.
// Define HRA and TA as constants and use them to calculate the salary of the employee.

int main() {
  float basic_pay, hra, ta, total_salary;

  // 1. Get the basic pay from the user
  printf("Enter the basic pay of the employee: ");
  if (scanf("%f", &basic_pay) != 1) {
    printf("Invalid input.\n");
    return 1;
  }

  // 2. Calculate HRA and TA using the constants
  hra = basic_pay * HRA_RATE;
  ta = basic_pay * TA_RATE;

  // 3. Calculate total salary
  total_salary = basic_pay + hra + ta;

  // 4. Display the detailed breakdown
  printf("\n--- Salary Breakdown ---\n");
  printf("Basic Pay:    $%.2f\n", basic_pay);
  printf("HRA (10%%):    $%.2f\n", hra);
  printf("TA (5%%):      $%.2f\n", ta);
  printf("------------------------\n");
  printf("Total Salary: $%.2f\n", total_salary);

  return 0;
}