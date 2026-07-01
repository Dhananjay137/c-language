#include <stdio.h>

// Write a program to read the address of a user.
// Display result by breaking it in multiple lines.

int main() {
    char address[200];

    printf("Enter your full address (separate parts with commas):\n");
    printf("Example: 123 Main St, Apt 4B, New York, NY 10001\n\n> ");
    
    // Read the full address including spaces safely
    fgets(address, sizeof(address), stdin);

    printf("\n--- Formatted Address ---\n");

    // Loop through the string and print character by character
    for (int i = 0; address[i] != '\0'; i++) {
        if (address[i] == ',') {
            printf("\n"); // Swap the comma for a newline block
            
            // Optional: If there is a space right after the comma, skip it 
            // so the next line doesn't start with an awkward blank space.
            if (address[i + 1] == ' ') {
                i++; 
            }
        } else {
            printf("%c", address[i]);
        }
    }

    return 0;
}