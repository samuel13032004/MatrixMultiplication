# test_benchmark.py

import pytest
from matrix_multiplication import multiply_matrices

@pytest.mark.benchmark
def test_multiply_matrices(benchmark):
    """
    Tests the multiply_matrices function with benchmarking.

    Args:
        benchmark (pytest_benchmark.BenchmarkFixture): Benchmark fixture provided by pytest-benchmark.
    """
    n = 10  # Matrix size
    result = benchmark(multiply_matrices, n)
    assert result is not None  # Check that the result is not None
