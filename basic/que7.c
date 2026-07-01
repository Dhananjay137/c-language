#include <stdio.h>
#include <math.h>
// Write program to calculate simple interest and compound interest.

int main() {
    double principal, rate, time;
    double simple_interest, compound_interest, amount;

    // 1. Input Principal, Rate, and Time
    printf("Enter the principal amount: ");
    scanf("%lf", &principal);

    printf("Enter the annual interest rate (in %%): ");
    scanf("%lf", &rate);

    printf("Enter the time period (in years): ");
    scanf("%lf", &time);

    // 2. Calculate Simple Interest
    simple_interest = (principal * rate * time) / 100.0;

    // 3. Calculate Compound Interest (Compounded Annually)
    // Formula: Amount = P * (1 + R/100)^T
    amount = principal * pow((1 + rate / 100.0), time);
    compound_interest = amount - principal;

    // 4. Display the results (rounded to 2 decimal places)
    printf("\n============ RESULTS ============\n");
    printf("Simple Interest:        %.2lf\n", simple_interest);
    printf("Total Amount (with SI): %.2lf\n", principal + simple_interest);
    printf("---------------------------------\n");
    printf("Compound Interest:      %.2lf\n", compound_interest);
    printf("Total Amount (with CI): %.2lf\n", amount);
    printf("=================================\n");

    return 0;
}