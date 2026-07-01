#include <stdio.h>

int main() {
    char ch;

    // 1. Read a single character input from the user
    printf("Enter any character, number, or symbol: ");
    scanf("%c", &ch);

    // 2. Print its ASCII value immediately
    printf("\nASCII Value: %d\n", ch);

    // 3. Determine what type of input it is
    if (ch >= '0' && ch <= '9') {
        printf("Classification: It is a number (digit).\n");
    }
    else if (ch >= 'A' && ch <= 'Z') {
        printf("Classification: It is an uppercase alphabet character.\n");
    }
    else if (ch >= 'a' && ch <= 'z') {
        printf("Classification: It is a lowercase alphabet character.\n");
    }
    else {
        printf("Classification: It is a special character or symbol.\n");
    }

    return 0;
}