import pytest
from matrix_multiplication import multiply_matrices

@pytest.mark.parametrize("n", [5, 10, 50, 100, 200])
@pytest.mark.benchmark
def test_multiply_matrices(benchmark, n):
    """
    Tests the multiply_matrices function with benchmarking for multiple matrix sizes.

    Args:
        benchmark (pytest_benchmark.BenchmarkFixture): Benchmark fixture provided by pytest-benchmark.
        n (int): The size of the matrix (n x n).
    """
    result = benchmark(multiply_matrices, n)
    assert result is not None  # Check that the result is not None
