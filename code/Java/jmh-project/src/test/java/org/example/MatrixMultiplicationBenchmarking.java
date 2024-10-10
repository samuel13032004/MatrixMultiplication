package org.example;

import org.openjdk.jmh.annotations.*;

import java.util.Random;
import java.util.concurrent.TimeUnit;

@BenchmarkMode(Mode.AverageTime)
@OutputTimeUnit(TimeUnit.MILLISECONDS)
@Warmup(iterations = 5, time = 1, timeUnit = TimeUnit.SECONDS)
@Measurement(iterations = 10, time = 1, timeUnit = TimeUnit.SECONDS)
@Fork(1)
public class MatrixMultiplicationBenchmarking {

	@State(Scope.Thread)
	public static class Operands {

		@Param({"5", "10", "50", "100", "200", "500", "1000"})
		private int n;

		private double[][] a;
		private double[][] b;
		private long memoryUsed; // Variable to store memory usage

		// Method to initialize the matrices before each benchmark
		@Setup(Level.Trial)
		public void setup() {
			a = new double[n][n];
			b = new double[n][n];
			Random random = new Random();

			// Initialize the matrices with random values
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					a[i][j] = random.nextDouble();
					b[i][j] = random.nextDouble();
				}
			}

			// Measure memory usage after initializing the matrices
			memoryUsed = measureMemory();
		}

		// Method to measure memory usage
		private long measureMemory() {
			System.gc(); // Force garbage collection
			return Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
		}
	}

	// Benchmark to perform matrix multiplication
	@Benchmark
	public void multiplication(Operands operands) {
		double[][] result = new MatrixMultiplication().execute(operands.a, operands.b);

		// Print memory usage only once for each size
		if (operands.memoryUsed > 0) {
			// Convert memory from bytes to megabytes
			double memoryUsedMB = operands.memoryUsed / (1024.0 * 1024.0);
			System.out.println("Matrix size: " + operands.n + "x" + operands.n +
					" | Memory used: " + String.format("%.2f", memoryUsedMB) + " MB");
			// To avoid printing multiple times, set to 0 after printing
			operands.memoryUsed = 0;
		}
	}
}
