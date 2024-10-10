package org.example;

import java.util.Random;

public class MatrixMultiplication {
    public static void main(String[] args) {
        int n = 10;  // Matrix size
        double[][] A = new double[n][n];
        double[][] B = new double[n][n];
        double[][] C = new double[n][n];

        Random rand = new Random();

        // Initialize matrices A and B with random values
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = rand.nextDouble();
                B[i][j] = rand.nextDouble();
            }
        }

        long startTime = System.nanoTime();

        // Matrix multiplication
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        long endTime = System.nanoTime();
        long duration = endTime - startTime;

        System.out.printf("Time taken: %.6f seconds\n", duration / 1e9);
    }
}
