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

// swaps the value of two integers
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void merge(int arr[], int l, int m, int r) {
    int r_len = r - m;
    int l_len = m - l + 1;
    int l_seg[l_len];
    int r_seg[r_len];
    for(int i = 0; i < l_len; i++) {
        l_seg[i] = arr[l+i];
    }
    for(int i = 0; i < r_len; i++) {
        r_seg[i] = arr[m+i+1];
    }
    for(int i = 0, j = 0, k = l; k <= r; k++) {
        if((j >= r_len) || (l_seg[i] <= r_seg[j] && i < l_len)) {
            arr[k] = l_seg[i];
            i++;
        } else {
            arr[k] = r_seg[j];
            j++;
        }
    }
}
void merge_sort_recursive(int arr[], int l, int r) {
    if(l >= r) return;
    int m = (l + r)/2; 
    merge_sort_recursive(arr, l, m);
    merge_sort_recursive(arr, m+1, r);
    merge(arr, l, m, r);
}
void merge_sort(int arr[], int n) {
    merge_sort_recursive(arr, 0, n-1);
}

int main()
{
    // take input from user
    printf("Enter the length of the array: ");
    int n;
    scanf("%i", &n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%i", &arr[i]);
    }
    printf("Your array: ");
    print_arr(arr, n);
    // runs main function
    printf("Sorting array...\n");
    merge_sort(arr, n);
    printf("Sorted array: ");
    print_arr(arr, n);
}