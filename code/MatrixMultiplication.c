#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n = 1024;  // Matrix size
    double **A, **B, **C;

    // Allocate memory for matrices A, B, and C
    A = malloc(n * sizeof(double *));
    B = malloc(n * sizeof(double *));
    C = malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        A[i] = malloc(n * sizeof(double));
        B[i] = malloc(n * sizeof(double));
        C[i] = malloc(n * sizeof(double));
    }

    // Initialize random number generator
    srand(time(NULL));

    // Initialize matrices A and B with random values
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = (double)rand() / RAND_MAX;
            B[i][j] = (double)rand() / RAND_MAX;
            C[i][j] = 0;  // Initialize C with zeros
        }
    }

    clock_t startTime = clock();

    // Matrix multiplication
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    clock_t endTime = clock();
    double duration = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    printf("Time taken: %.6f seconds\n", duration);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}
