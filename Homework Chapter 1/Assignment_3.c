#include <stdio.h>
#include <stdlib.h>

//b. Print the sum of this 2D-array by using pointer
int sumArray(int **A, int arrNum){
    int sum = 0;
    for (int i = 0; i < arrNum; i++) {
        for (int j = 0; j < arrNum - 1; j++) {
            sum += A[i][j];
        }
    }
    return sum;
}

//c. If we consider 2D-array as a matrix, please print the transpose of this matrix
void transposeMatrix(int **A, int arrNum){
    int i, j;
    for (i = 0; i < arrNum - 1; i++) {
        for (j = 0; j < arrNum; j++) {
            printf("%d ", A[j][i]);
        }
        printf("\n");
    }
}

int main(){
    int arrNum;
    printf("Enter the number of 2D array you want: ");
    scanf("%d", &arrNum); 
    int **A;
    int i, j;
    A = (int **) calloc(arrNum, sizeof(int *)); 
    //*A is a 1D array (size the user want to input)

    for(i = 0; i < arrNum; i++){
        A[i] = (int *) calloc (arrNum - 1, sizeof(int));
        //Each element of array points to an array of arrNum - 1 int variables
    }

    for (i = 0; i < arrNum; i++) {
        printf("Please enter numbers for array %d:\n", i + 1);
        for (j = 0; j < arrNum - 1; j++) {
            printf("Enter number %d: ", j + 1);
            scanf("%d", &A[i][j]); 
        }
    }

    // Check if the input is successful
    printf("You have entered: \n");
    for (i = 0; i < arrNum; i++) {
        for (j = 0; j < arrNum - 1; j++) {
            printf("%d ", A[i][j]); 
        }
        printf("\n");
    }
    
    printf("The sum of the array is: %d\n", sumArray(A, arrNum));
    printf("The transpose of the matrix is: \n");
    transposeMatrix(A, arrNum);

    // Free allocated memory
    for (i = 0; i < arrNum; i++) {
        free(A[i]);
    }
    free(A);

    return 0;
}