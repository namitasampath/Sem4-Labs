/*2). Write a program to implement brute-force string matching. Analyze its time 
efficiency. */

#include <stdio.h>
#include <string.h>

void brute_force_string_matching(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    int opcount = 0; 
int i =0;
    for ( i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            opcount++; // Count each comparison
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            printf("Pattern found at index %d\n", i);
        }
    }
    printf("Total operations: %d\n", opcount);
}

int main() {
    char text[100], pattern[100];
    printf("Enter the text: ");
    gets(text);
    printf("Enter the pattern: ");
    gets(pattern);
    brute_force_string_matching(text, pattern);
    return 0;
}
