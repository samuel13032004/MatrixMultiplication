import pytest
import psutil
from matrix_multiplication import multiply_matrices

@pytest.mark.parametrize("n", [5, 10, 50, 100, 200, 500])
def test_multiply_matrices(benchmark, n):
    """
    Tests the multiply_matrices function with benchmarking and memory usage tracking.

    Args:
        benchmark (pytest_benchmark.BenchmarkFixture): Benchmark fixture provided by pytest-benchmark.
        n (int): The size of the matrix (n x n).
    """
    # Measure memory usage before execution
    mem_before = psutil.Process().memory_info().rss / (1024 * 1024)  # Convertir a MB

    # Benchmark the matrix multiplication
    result = benchmark(multiply_matrices, n)

    # Measure memory usage after execution
    mem_after = psutil.Process().memory_info().rss / (1024 * 1024)  # Convertir a MB

    # Ensure the result is not None
    assert result is not None

    # Ensure the result is not None
    memory_increase = mem_after - mem_before

    # Report memory usage
    print()
    print(f"Matrix size: {n} x {n}")
    print(f"Memory usage before: {mem_before:.2f} MB, after: {mem_after:.2f} MB")
    print(f"Memory increase: {memory_increase:.2f} MB")
