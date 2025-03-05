/*Assignment 1 Write a function which swaps two integer using pointer in C language:
Swap(int* x, int* y). Write a simple program to test this function.*/

#include <stdio.h>
void Swap(int* x, int* y){
   int temp = *x;
   *x = *y;
   *y = temp;
}

int main(){
    int a, b; a = 10; b = 5;
    int* x = &a;
    int* y = &b;
    printf("%d %d\n",*x, *y);
    Swap(x, y);
    printf("%d %d\n", *x, *y);
    return 0;
}