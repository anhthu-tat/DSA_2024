//Assignment 2

/* a. Write a program to allow user input size of a 1D-array and enter the value for each elements of this array.
example: Users input size of an array is: 6 and enter the array as following: -2, 11, -4, 13, -5, -2 */

#include <stdio.h>
#include <stdlib.h>
int main(){
    int *arr;
    int num;
    int i;
    printf("How many numbers do you want to enter?: ");
    scanf("%d", &num);
    arr = (int*) calloc (num, sizeof(int)); //arr becomes an array of size num

    if(arr == NULL){
        printf("Memory allocation failed\n"); //return 1 if failed
        return 1;
    }

    for(i = 0; i < num; i++){
        printf("Please enter number %d ", i+1);
        scanf("%d", &(arr[i]));
    }

    /*check if the input is success
    printf("You have entered: ");
    for(i = 0; i < num; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");*/
    
    free(arr); //free the allocated memory to avoid memory leak
    return 0;
}
