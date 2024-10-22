#include <stdio.h>

void add(double numbers[], int count);
void subtract(double numbers[], int count);
void multiply(double numbers[], int count);
void divide(double numbers[], int count);

int main() {
    int choice, n;

    while (1) {
        printf("\nBasic Calculator Menu:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Exit condition
        if (choice == 5) {
            printf("Exiting the calculator. Goodbye!\n");
            break;
        }

        // Input the number of operands
        printf("Enter the number of operands: ");
        scanf("%d", &n);
        
        double numbers[n]; // Array to store the numbers

        // Input numbers
        printf("Enter %d numbers:\n", n);
        for (int i = 0; i < n; i++) {
            printf("Number %d: ", i + 1);
            scanf("%lf", &numbers[i]);
        }

        // Perform the chosen operation
        switch (choice) {
            case 1:
                add(numbers, n);
                break;
            case 2:
                subtract(numbers, n);
                break;
            case 3:
                multiply(numbers, n);
                break;
            case 4:
                divide(numbers, n);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Function to add n numbers
void add(double numbers[], int count) {
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    printf("Result: Sum = %.2lf\n", sum);
}

// Function to subtract n numbers
void subtract(double numbers[], int count) {
    double result = numbers[0];
    for (int i = 1; i < count; i++) {
        result -= numbers[i];
    }
    printf("Result: Difference = %.2lf\n", result);
}

// Function to multiply n numbers
void multiply(double numbers[], int count) {
    double product = 1;
    for (int i = 0; i < count; i++) {
        product *= numbers[i];
    }
    printf("Result: Product = %.2lf\n", product);
}

// Function to divide n numbers
void divide(double numbers[], int count) {
    if (count == 0 || numbers[0] == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return;
    }
    
    double result = numbers[0];
    for (int i = 1; i < count; i++) {
        if (numbers[i] == 0) {
            printf("Error: Division by zero is not allowed.\n");
            return;
        }
        result /= numbers[i];
    }
    printf("Result: Quotient = %.2lf\n", result);
}