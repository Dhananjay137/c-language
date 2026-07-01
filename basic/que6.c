#include <stdio.h>

// Write program to read a floating point number.
// Display the rightmost digit of the ingeral part of the number.

int main() {
    float num;
    int integral_part, rightmost_digit;

    // 1. Read a float from the user
    printf("Enter a floating-point number: ");
    scanf("%f", &num);

    // 2. Extract the integral part
    integral_part = (int)num;

    // Handle negative numbers 
    if (integral_part < 0) {
        integral_part = -integral_part;
    }

    // 3. Find the rightmost digit using modulo
    rightmost_digit = integral_part % 10;

    // 4. Display the result
    printf("The rightmost digit of the integral part is: %d\n", rightmost_digit);

    return 0;
}