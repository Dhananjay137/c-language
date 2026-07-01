#include <stdio.h>
#include <string.h>

// Write program to prepare a grocery bill. Enter the name of the items purchased, quantity in which it is purchased, and its price per unit.
// then display the bill in the following format:

#define MAX_ITEMS 3

int main() {
    // Arrays to store details for multiple items
    char item_name[MAX_ITEMS][30];
    int quantity[MAX_ITEMS];
    float price_per_unit[MAX_ITEMS];
    float total_per_item[MAX_ITEMS];
    float grand_total = 0.0;

    // 1. Input data for items
    printf("--- Enter Grocery Items Purchased ---\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("\nItem %d:\n", i + 1);
        printf("  Name: ");
        // Read item name (using scanf with %s for single-word items)
        scanf("%s", item_name[i]);
        
        printf("  Quantity: ");
        scanf("%d", &quantity[i]);
        
        printf("  Price per unit: ");
        scanf("%f", &price_per_unit[i]);

        // Calculate the individual total for this item
        total_per_item[i] = quantity[i] * price_per_unit[i];
        
        // Add to the grand total
        grand_total += total_per_item[i];
    }

    // 2. Display the formatted bill
    printf("\n===================================================\n");
    printf("                  GROCERY BILL                    \n");
    printf("===================================================\n");
    
    // Header row with specific spacing:
    // %-15s = Left-aligned text, 15 characters wide
    // %10s  = Right-aligned text, 10 characters wide
    printf("%-15s %10s %12s %10s\n", "Item Name", "Quantity", "Price/Unit", "Total");
    printf("---------------------------------------------------\n");

    // Print each item row using the same column width specifiers
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("%-15s %10d %12.2f %10.2f\n", 
               item_name[i], 
               quantity[i], 
               price_per_unit[i], 
               total_per_item[i]);
    }

    printf("---------------------------------------------------\n");
    // Print the grand total aligned to the far right column
    printf("%-39s %10.2f\n", "Grand Total:", grand_total);
    printf("===================================================\n");

    return 0;
}