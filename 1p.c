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

int all_multiple_of(int x, int* arr, int n) {
    // iterate through all the elements
    for(int i = 0; i < n; i++) {
        // check if each element is not divisable by X without any rest
        // if one of the elements didn't pass the test return 0 from the function
        if(arr[i] % x != 0) return 0;
    }
    // if all the elements have passed the test return 1
    return 1;
}

int main()
{
    int x;
    int n;
    // taking input from user
    printf("Enter X: ");
    scanf("%i", &x);
    printf("Enter the length of the array: ");
    scanf("%i", &n);
    int *arr = (int*)malloc(sizeof(int)*n);
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%i", &arr[i]);
    }
    printf("Your array: ");
    print_arr(arr, n);
    // calling main function and making decision based on the answer
    printf("Processing the array...\n");
    int result = all_multiple_of(x, arr, n);
    if(result) {
        printf("All the element are multiples of %i.\n", x);
    } else {
        printf("Not all the elements are multiples of %i\n", x);
    }
    free(arr);
}

// Flowchart: https://lucid.app/lucidchart/5dde2053-23dd-4fae-a853-0e38f9c469d2/edit?viewport_loc=-1031%2C282%2C1996%2C890%2C0_0&invitationId=inv_b14dd0a7-0cbc-4ed5-a744-c5b904e0431b