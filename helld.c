#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100];
    char name[50];
    int price;
    int unit;

    printf("Enter the name, price, and unit (e.g., Kitkat, 123, 16): ");
    
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Use sscanf to parse the input into name, price, and unit
        if (sscanf(input, "%49[^,], %d, %d", name, &price, &unit) == 3) {
            printf("Name: %s\n", name);
            printf("Price: %d\n", price);
            printf("Unit: %d\n", unit);
        } else {
            printf("Invalid input format.\n");
        }
    } else {
        printf("Error reading input.\n");
    }

    return 0;
}
