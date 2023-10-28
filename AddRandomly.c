#include <stdio.h>
#include <stdlib.h>

// Function to compare two numbers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int numCount = 100; // Number of random numbers
    int numbers[numCount];

    // Generate and store 100 random numbers
    for (int i = 0; i < numCount; i++) {
        numbers[i] = rand();
    }

    // Sort the numbers in descending order
    qsort(numbers, numCount, sizeof(int), compare);

    // Print the sorted numbers
    printf("Sorted Numbers (largest to smallest):\n");
    for (int i = 0; i < numCount; i++) {
        printf("%d\n", numbers[i]);
    }

    return 0;
}
