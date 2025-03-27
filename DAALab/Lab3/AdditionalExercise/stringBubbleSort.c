/*3) Write a program to sort a set of strings using Bubble Sort. Analyze its time
efficiency.
*/

#include <stdio.h>
#include <string.h>

#define MAX 100  // Maximum number of strings
#define LEN 100  // Maximum length of each string

void bubbleSort(char arr[][LEN], int n, int *opcount) {
    int i, j;
    char temp[LEN];
    
    *opcount = 0;  // Initialize operation count

    for (i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            (*opcount)++;  // Counting comparison
            
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                // Swap strings
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
                
                swapped = 1;
                (*opcount) += 3;  // Counting swap operations
            }
        }
        if (!swapped) break;  // Stop if no swapping is done
    }
}

int main() {
    int n, i, opcount;
    char arr[MAX][LEN];

    printf("Enter number of strings: ");
    scanf("%d", &n);
    getchar();  // Consume the newline character after scanf

    printf("Enter %d strings:\n", n);
    for (i = 0; i < n; i++) {
        fgets(arr[i], LEN, stdin);
        arr[i][strcspn(arr[i], "\n")] = '\0';  // Remove newline character
    }

    bubbleSort(arr, n, &opcount);

    printf("\nSorted strings:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    printf("\nTotal operations performed: %d\n", opcount);

    return 0;
}
