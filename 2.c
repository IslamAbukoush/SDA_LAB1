#include <stdio.h>

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

void sqr_repeated_multiples_of(int x, int arr[], int n) {
    int seen[n];
    int seen_idx = 0;
    int duplicates[n];
    int dup_idx = 0;


    for(int i = 0; i < n; i++) {
        // checks if element is a multiple of X
        if(arr[i] % x == 0) {
            // checks if element was seen before in the seen array
            int is_seen = element_in_arr(arr[i], seen, seen_idx);
            if(is_seen) {
                // if it was seen before it will be put into the duplicates array
                duplicates[dup_idx] = arr[i];
                dup_idx++;
            } else {
                // if it wasn't seen before it will be put into the seen array
                seen[seen_idx] = arr[i];
                seen_idx++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        // checks if element is in the duplicates array, if so square it
        int is_target = element_in_arr(arr[i], duplicates, dup_idx);
        if(is_target) {
            arr[i] = arr[i] * arr[i];
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
    sqr_repeated_multiples_of(x, arr, n);
    printf("Output: ");
    print_arr(arr, n);
}

// print_arr, element_in_arr, main flowchart: https://lucid.app/lucidchart/fa9409c5-b5b8-45f5-af97-4189339147de/edit?viewport_loc=-510%2C-300%2C2995%2C1336%2C0_0&invitationId=inv_246b53b9-cbe4-4318-aff9-e8d7306d3538
// sqr_repeated_multiples_of flowchart: https://lucid.app/lucidchart/ba7e08c5-5e1f-4e29-bc46-1b32a64717b7/edit?viewport_loc=-1291%2C-1112%2C2694%2C1202%2C0_0&invitationId=inv_503da816-733e-4ee2-b643-fb16ea2ae7a2
