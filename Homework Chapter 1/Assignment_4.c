#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Worker {
    int id;
    char full_name[100];
    int age;
    float salary;
};

void Input(struct Worker *worker) {
    printf("Enter the ID: ");
    scanf("%d", &worker->id);
    getchar(); 
    
    printf("Enter the full name: ");
    scanf("%[^\n]", worker->full_name);
    
    printf("Enter the age: ");
    scanf("%d", &worker->age);
    
    printf("Enter the salary: ");
    scanf("%f", &worker->salary);
}

void Print(struct Worker *worker) {
    printf("ID: %d, Name: %s, Age: %d, Salary: %.2f\n",
        worker->id, worker->full_name, worker->age, worker->salary);
}

int main() {
    int n;
    struct Worker demo;
    printf("What is the size of your 1D-array: ");
    scanf("%d", &n);
    struct Worker* arr = (struct Worker*) calloc(n, sizeof(struct Worker));
    
    if (arr == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Please enter information for employee %d:\n", i+1);
        Input(&arr[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("Information of employee %d: ", i+1);
        Print(&arr[i]);
    }

    free(arr);
    return 0;
}
