/*1). Write a program to sort set of integers using bubble sort. Analyze its time 
efficiency. Obtain the experimental result of order of growth. Plot the result for 
the best and worst case. */

#include <stdio.h>

void bubble_sort(int arr[], int n,int *opcount) {
    int i,j;

    for ( i = 0; i < n - 1; i++) {
        for ( j = 0; j < n - i - 1; j++) {
                (*opcount)++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, arr[50],i;
    int opcount = 0;
    printf("Enter the size of the array");
    scanf("%d",&n);
    printf("Enter the array elements");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    bubble_sort(arr, n,&opcount);
    printf("Sorted array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("The operation count: %d",opcount);
    return 0;
}
