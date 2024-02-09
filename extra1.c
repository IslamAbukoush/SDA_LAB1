#include <stdio.h>

void print_arr(int arr[], int n) {
    if (n < 1) return;
    printf("{");
    for (int i = 0; i < n - 1; i++) {
        printf("%i, ", arr[i]);
    }
    printf("%i}\n", arr[n - 1]);
}

int has_pair_sum_multiple_of(int x, int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((arr[i] + arr[j]) % x == 0) {
                printf("Pair found: (%i, %i)\n", arr[i], arr[j]);
                return 1; // Pair found
            }
        }
    }
    return 0; // No pair found
}

int main() {
    int x;
    int n;

    // Taking input from the user
    printf("Enter X: ");
    scanf("%i", &x);
    printf("Enter the length of the array: ");
    scanf("%i", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%i", &arr[i]);
    }

    printf("Your array: ");
    print_arr(arr, n);

    // Calling the main function and making a decision based on the answer
    printf("Processing the array...\n");

    int result = has_pair_sum_multiple_of(x, arr, n);

    if (result) {
        printf("There is at least one pair whose sum is a multiple of %i.\n", x);
    } else {
        printf("No pair found whose sum is a multiple of %i.\n", x);
    }

    return 0;
}
