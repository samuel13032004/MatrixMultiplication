import random

def multiply_matrices(n):
    """
    Multiplies two n x n matrices filled with random numbers.

    Args:
        n (int): Size of the matrices.

    Returns:
        C (list): Resultant matrix after multiplication.
    """
    # Initialize matrices A and B with random values, and C with zeros
    A = [[random.random() for _ in range(n)] for _ in range(n)]
    B = [[random.random() for _ in range(n)] for _ in range(n)]
    C = [[0 for _ in range(n)] for _ in range(n)]

    # Matrix multiplication
    for i in range(n):
        for j in range(n):
            for k in range(n):
                C[i][j] += A[i][k] * B[k][j]

    return C
