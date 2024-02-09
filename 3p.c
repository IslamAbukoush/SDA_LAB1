#include <stdio.h>
#include <stdlib.h>

// Prints the array in a nice way
void print_arr(int* arr, int n) {
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

void bubble_sort(int* arr, int n) {
    // starts from n and goes down to 0 to avoid sorting already sorted elements
    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j < i; j++) {
            // checks if element is greater than the element next to it
            if(arr[j] > arr[j+1]) {
                // if so, swap them
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main()
{
    // take input from user
    printf("Enter the length of the array: ");
    int n;
    scanf("%i", &n);
    int* arr = (int*)malloc(sizeof(int)*n);
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%i", &arr[i]);
    }
    printf("Your array: ");
    print_arr(arr, n);
    // runs main function
    printf("Sorting array...\n");
    bubble_sort(arr, n);
    printf("Sorted array: ");
    print_arr(arr, n);
    free(arr);
}

// bubble_sort, swap, main flowchart: https://lucid.app/lucidchart/a50e7896-9c51-4da7-bd8f-6961d0048679/edit?viewport_loc=-810%2C-737%2C4471%2C1994%2C0_0&invitationId=inv_1d2834ac-961c-4c97-b46b-dc1576b2a950
// print_arr flowchart: https://lucid.app/lucidchart/fa9409c5-b5b8-45f5-af97-4189339147de/edit?viewport_loc=-510%2C-300%2C2995%2C1336%2C0_0&invitationId=inv_246b53b9-cbe4-4318-aff9-e8d7306d3538
