#include <stdio.h>
#include <stdlib.h>

// Prints the array in a nice way
void print_arr(int *arr, int n) {
    if(n < 1) return;
    printf("{");
    for(int i = 0; i < n-1; i++) {
        printf("%i, ",arr[i]);
    }
    printf("%i}\n", arr[n-1]);
}

// swaps the value of two integers
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void insertion_sort(int *arr, int n) {
    for(int i = 1; i < n; i++) {
        int index = i;
        while(index > 0 && arr[index] < arr[index - 1]) {
            swap(&arr[index], &arr[index-1]);
            index--;
        }
    }
}

int main()
{
    // take input from user
    printf("Enter the length of the array: ");
    int n;
    scanf("%i", &n);
    int *arr = (int*)malloc(sizeof(int)*n);
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%i", &arr[i]);
    }
    printf("Your array: ");
    print_arr(arr, n);
    // runs main function
    printf("Sorting array...\n");
    insertion_sort(arr, n);
    printf("Sorted array: ");
    print_arr(arr, n);
    free(arr);
}