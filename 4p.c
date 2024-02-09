#include <stdio.h>

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

void selection_sort(int* arr, int n) {
    // starts from n and goes down to 0 to avoid sorting already sorted elements
    for(int i = n-1; i >= 0; i--) {
        // initializes the index of the minimum element to the first element
        int min_idx = 0;
        for(int j = 0; j <= i; j++) {
            // checks if element is less than the current minimum element
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // moves the minimum element to the end of the array(before the other minimums, ith pos)
        swap(&arr[min_idx], &arr[i]);
    }
}

int main()
{
    // takes input from user
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
    printf("Processing array...\n");
    selection_sort(arr, n);
    print_arr(arr, n);
    free(arr);
}

// selection_sort, swap, main for flowchart: https://lucid.app/lucidchart/c4a67fe5-a2db-40da-bc9f-292f08d661c6/edit?viewport_loc=-459%2C-525%2C1818%2C811%2C0_0&invitationId=inv_c70c62bf-29e6-4d63-98a1-2907ce0d306a
// print_arr flowchart: https://lucid.app/lucidchart/fa9409c5-b5b8-45f5-af97-4189339147de/edit?viewport_loc=-510%2C-300%2C2995%2C1336%2C0_0&invitationId=inv_246b53b9-cbe4-4318-aff9-e8d7306d3538