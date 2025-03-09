//Assignment 2

/* a. Write a program to allow user input size of a 1D-array and enter the value for each elements of this array.
example: Users input size of an array is: 6 and enter the array as following: -2, 11, -4, 13, -5, -2 */

#include <stdio.h>
#include <stdlib.h>

// Function to swap two integers using pointers (from Assignment 1)
void Swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to sort an array in ascending order using the Swap function
void ascendingSwap(int* arr, int num) {
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                Swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Function to find the maximum sum of a subarray
int maxSubArraySum(int* arr, int num) {
    int max_so_far = arr[0];
    int curr_max = arr[0];

    for (int i = 1; i < num; i++) {
        curr_max = (arr[i] > curr_max + arr[i]) ? arr[i] : curr_max + arr[i];
        max_so_far = (max_so_far > curr_max) ? max_so_far : curr_max;
    }
    return max_so_far;
}

int main() {
    int *arr;
    int num;
    int i;

    printf("How many numbers do you want to enter?: ");
    scanf("%d", &num);

    arr = (int*) calloc(num, sizeof(int)); // arr becomes an array of size num

    if (arr == NULL) {
        printf("Memory allocation failed\n"); // return 1 if failed
        return 1;
    }

    for (i = 0; i < num; i++) {
        printf("Please enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Check if the input is successful
    printf("You have entered: ");
    for (i = 0; i < num; i++) {
        printf("%d ", arr[i]); // print the value of the array element
    }
    printf("\n");

    // b. Print the sum of this array by using pointer.
    int sum = 0;
    for (i = 0; i < num; i++) {
        sum += arr[i];
    }
    printf("The sum of numbers is: %d\n", sum);

    // d. Calculate the max value of sum of a subarray of the original array
    int maxSum = maxSubArraySum(arr, num);


    // c. Sort this array in ascending order by using the function of Assignment 1.
    ascendingSwap(arr, num);

    // Print the sorted array
    printf("The sorted array is: ");
    for (i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("The max value of sum of a subarray is: %d\n", maxSum);
    
    free(arr); // free the allocated memory to avoid memory leak
    return 0;
}
