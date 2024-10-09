#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Array of sizes to test
    int sizes[] = {5, 10, 50, 100, 200, 500, 1000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    // Seed for random number generation
    srand(time(NULL));

    // Variable to track total memory usage
    size_t total_memory_usage = 0;

    for (int s = 0; s < num_sizes; s++) {
        int n = sizes[s];

        // Calculate memory usage for matrices A, B, and C
        size_t memory_per_matrix = n * n * sizeof(double);  // Memory for one matrix
        size_t memory_total = 3 * memory_per_matrix;  // Memory for A, B, and C

        // Accumulate total memory usage
        total_memory_usage += memory_total;

        // Allocate memory for matrices A, B, and C
        double **A = malloc(n * sizeof(double *));
        double **B = malloc(n * sizeof(double *));
        double **C = malloc(n * sizeof(double *));
        for (int i = 0; i < n; i++) {
            A[i] = malloc(n * sizeof(double));
            B[i] = malloc(n * sizeof(double));
            C[i] = malloc(n * sizeof(double));
        }

        // Initialize matrices A and B with random values and C with zeros
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = (double)rand() / RAND_MAX;
                B[i][j] = (double)rand() / RAND_MAX;
                C[i][j] = 0;
            }
        }

        // Start timing
        clock_t startTime = clock();

        // Matrix multiplication
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        // End timing
        clock_t endTime = clock();
        double duration = (double)(endTime - startTime) / CLOCKS_PER_SEC;

        // Print the result for the current matrix size
        printf("Matrix size: %d x %d, Time taken: %.6f seconds, Memory used: %.2f MB\n",
               n, n, duration, (double)memory_total / (1024 * 1024));

        // Free allocated memory
        for (int i = 0; i < n; i++) {
            free(A[i]);
            free(B[i]);
            free(C[i]);
        }
        free(A);
        free(B);
        free(C);
    }

    // Print total memory usage for all executions
    printf("Total memory used for all matrix sizes: %.2f MB\n", (double)total_memory_usage / (1024 * 1024));

    return 0;
}

