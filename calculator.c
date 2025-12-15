#include <stdio.h>
#include <stdlib.h>
// Simple calculator program
int main() {
    int choice, a, b, result;

    do {
        printf("\n========== CALCULATOR ==========\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            //code for addition
            case 1:
                printf("\n========== ADD ===========\n");
                printf("Enter first number: ");
                scanf("%d", &a);
                printf("Enter second number: ");
                scanf("%d", &b);
                result = a + b;
                printf("%d + %d = %d\n", a, b, result);
                break;
            //code de for subtraction
            case 2:
                printf("\n========== SUBTRACT ===========\n");
                printf("Enter first number: ");
                scanf("%d", &a);
                printf("Enter second number: ");
                scanf("%d", &b);
                result = a - b;
                printf("%d - %d = %d\n", a, b, result);
                break;
            //code for multiplication
            case 3:
                printf("\n========== MULTIPLY ===========\n");
                printf("Enter first number: ");
                scanf("%d", &a);
                printf("Enter second number: ");
                scanf("%d", &b);
                result = a * b;
                printf("%d * %d = %d\n", a, b, result);
                break;
            //code for division
            case 4:
                printf("\n========== DIVIDE ===========\n");
                printf("Enter first number: ");
                scanf("%d", &a);
                printf("Enter second number: ");
                scanf("%d", &b);
                if (b == 0) {
                    printf("Error: Cannot divide by zero!\n");
                } else {
                    result = a / b;
                    printf("%d / %d = %d\n", a, b, result);
                }
                break;
            //code for exit
            case 0:
                printf("\nGoodbye !\n");
                exit(0);
            //code for invalid choice
            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 0);

    return 0;
}
// End of file calculator.c