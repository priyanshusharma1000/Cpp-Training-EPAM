// Topic: Pointer Arithmetic Using 3d Array
// This file is created by Priyanshu Sharma!
#include <stdio.h>
int main() {
    // 3D Array Declaration (2 x 2 x 3)
    int arr[2][2][3] = {
        { {1, 2, 3}, {4, 5, 6} },
        { {7, 8, 9}, {10, 11, 12} }
    };

    // Pointer to the first element of the array
    int *ptr = (int *)arr;  

    // Total number of elements in the 3D array
    int total_elements = 2 * 2 * 3;  

    // Using pointer arithmetic to access elements
    printf("Accessing elements using pointer arithmetic:\n");
    for (int i = 0; i < total_elements; i++) {
        printf("Element %d: %d\n", i, *(ptr + i)); 
    }

    // Accessing elements using explicit pointer arithmetic
    printf("\nAccessing elements with pointer offset calculation:\n");
    for (int i = 0; i < 2; i++) { // Loop over first dimension
        for (int j = 0; j < 2; j++) { // Loop over second dimension
            for (int k = 0; k < 3; k++) { // Loop over third dimension
                // Formula to compute the memory location of arr[i][j][k]
                int index = i * (2 * 3) + j * 3 + k;  
                printf("arr[%d][%d][%d] = %d, Using Pointer: *(ptr + %d) = %d\n",
                       i, j, k, arr[i][j][k], index, *(ptr + index));
            }
        }
    }

    return 0;
}
