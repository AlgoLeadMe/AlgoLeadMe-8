def matrixmult(A, B, mod):  # 행렬 곱 계산
    n = len(A)
    C = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                C[i][j] += A[i][k] * B[k][j]
                C[i][j] %= mod
    return C

def matrixpow(M, N, mod):  # 행렬 거듭제곱 계산 (M의 N승)
    n = len(M)
    result = [[1 if i == j else 0 for j in range(n)] for i in range(n)]  # 단위 행렬
    base = M
    
    while N:  # N이 0이 될 때까지 반복
        if N % 2 == 1:
            result = matrixmult(result, base, mod)
        base = matrixmult(base, base, mod)
        N //= 2
    
    return result

mod = 1000000007

M = [[1, 1],
     [1, 0]]

n = int(input())

result = matrixpow(M, n-1, mod)
print(result[0][0])