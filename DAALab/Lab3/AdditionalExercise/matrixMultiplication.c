/*Write a program to implement matrix multiplication using brute-force technique
and analyze its time efficiency. Obtain the experimental result of order of growth.
Plot the result for the best and worst case.*/

#include <stdio.h>

// Global variable to count operations
int opcount = 0; 

// Function to multiply matrices and count operations
void multiply_matrices(int r1, int c1, int A[r1][c1], int r2, int c2, int B[r2][c2], int C[r1][c2]) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];  
                opcount += 2; // 1 multiplication + 1 addition
            }
        }
    }
}

// Function to take matrix input
void input_matrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Enter elements of %dx%d matrix:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void print_matrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int r1, c1, r2, c2;

    // Input matrix dimensions
    printf("Enter rows and columns for matrix A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns for matrix B: ");
    scanf("%d %d", &r2, &c2);

    // Check if multiplication is possible
    if (c1 != r2) {
        printf("Error: Matrix multiplication not possible (columns of A must equal rows of B).\n");
        return 1;
    }

    int A[r1][c1], B[r2][c2], C[r1][c2];

    // Take input for matrices A and B
    input_matrix(r1, c1, A);
    input_matrix(r2, c2, B);

    // Reset opcount before multiplication
    opcount = 0;

    // Multiply matrices
    multiply_matrices(r1, c1, A, r2, c2, B, C);

    // Print results
    printf("\nMatrix A:\n");
    print_matrix(r1, c1, A);

    printf("\nMatrix B:\n");
    print_matrix(r2, c2, B);

    printf("\nResultant Matrix C (A x B):\n");
    print_matrix(r1, c2, C);

    // Print operation count
    printf("\nTotal operations (multiplications + additions): %d\n", opcount);

    return 0;
}
