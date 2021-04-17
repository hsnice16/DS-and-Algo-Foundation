import sys

def solveMatrix(p, n):
    m = [[0 for x in range(n)] for x in range(n)]

    for cl in range(2, n):
        for i in range(1, n-cl + 1):
            j = i + cl-1
            m[i][j] = sys.maxsize
            for k in range(i, j):
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]
                if q < m[i][j]:
                    m[i][j] = q

    return m[1][n-1]

n = int(input())
p_li = input().split()
p = [int(var) for var in p_li]

print(solveMatrix(p,n+1))
