#include <stdio.h>
#include <math.h>

// Prints the array in a nice way
void print_arr(int arr[], int n) {
    if(n < 1) return;
    printf("{");
    for(int i = 0; i < n-1; i++) {
        printf("%i, ",arr[i]);
    }
    printf("%i}\n", arr[n-1]);
}

// checks if element x exists in array arr of length n
int element_in_arr(int x, int arr[], int n) {
    for(int i = 0; i < n; i++) {
        if(x == arr[i]) {
            return 1;
        }
    }
    return 0;
}

void odd_multiples_operation(int x, int arr[], int n) {
    int seen[n];
    int seen_idx = 0;
    int odd_multiples[n];
    int odd_mul_idx = 0;

    for(int i = 0; i < n; i++) {
        // checks if element is an odd multiple of X
        if(arr[i] % x == 0 && arr[i] % 2 != 0) {
            // checks if element was seen before in the seen array
            int is_seen = element_in_arr(arr[i], seen, seen_idx);
            if(is_seen) {
                // if it was seen before, it will be put into the odd multiples array
                odd_multiples[odd_mul_idx] = arr[i];
                odd_mul_idx++;
            } else {
                // if it wasn't seen before, it will be put into the seen array
                seen[seen_idx] = arr[i];
                seen_idx++;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        // checks if element is in the odd multiples array, if so, perform a different operation
        int is_target = element_in_arr(arr[i], odd_multiples, odd_mul_idx);
        if(is_target) {
            // For example, you can take the square root or cube of the element
            arr[i] = pow(arr[i], 3); // Cube the element
        }
    }
}

int main()
{
    int x;
    int n;
    // takes input
    printf("Enter X: ");
    scanf("%i", &x);
    printf("Enter the length of the array: ");
    scanf("%i", &n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%i", &arr[i]);
    }
    printf("Your array: ");
    print_arr(arr, n);
    // runs main function
    printf("Processing array...\n");
    odd_multiples_operation(x, arr, n);
    printf("Output: ");
    print_arr(arr, n);
}