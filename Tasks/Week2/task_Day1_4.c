// Topic: Memory Managment In C
// This file is created by Priyanshu Sharma!
#include <stdio.h>
#include <stdlib.h> // Required for malloc, calloc, realloc, free

int main() {
    int *ptr1, *ptr2, *ptr3;
    int i, n;

    // Using malloc to allocate memory for 5 integers
    ptr1 = (int *)malloc(5 * sizeof(int)); 
    if (ptr1 == NULL) {
        printf("Memory allocation failed for malloc\n");
        return 1;
    }
    printf("Memory allocated using malloc:\n");
    for (i = 0; i < 5; i++) {
        ptr1[i] = i + 1; // Assign values
        printf("%d ", ptr1[i]);
    }
    printf("\n");

    // Using calloc to allocate memory for 5 integers (all initialized to 0)
    ptr2 = (int *)calloc(5, sizeof(int)); 
    if (ptr2 == NULL) {
        printf("Memory allocation failed for calloc\n");
        return 1;
    }
    printf("\nMemory allocated using calloc (initialized to 0):\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", ptr2[i]); // All should be 0 initially
    }
    printf("\n");

    // Increasing the memory allocated using realloc
    printf("\nIncreasing memory size using realloc...\n");
    ptr3 = (int *)realloc(ptr2, 10 * sizeof(int)); // Expanding memory to store 10 integers
    if (ptr3 == NULL) {
        printf("Memory reallocation failed\n");
        free(ptr1); // Free previously allocated memory before exiting
        return 1;
    }
    
    // Assigning new values to the additional memory
    for (i = 5; i < 10; i++) {
        ptr3[i] = 1; // Assigning new values
    }

    printf("Memory after realloc (previous values retained, new values added):\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", ptr3[i]);
    }
    printf("\n");

    // Freeing allocated memory
    free(ptr1); // Free memory allocated with malloc
    free(ptr3); // Free memory allocated with realloc (previously calloc)
    
    printf("\nMemory successfully freed!\n");

    return 0;
}
//priyanshu sharma!
