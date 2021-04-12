from math import factorial
from itertools import  permutations

def reversort(n: int, c: int, int_li: list) -> int:
    cost = 0
    for i in range(n-1):
        j = int_li.index(min(int_li[i:]), i)
        
        int_li[i:j+1] = reversed(int_li[i:j+1])
        cost += (j - i + 1)
        
    return cost == c

def reversort_engr(n: int, c: int) -> str:

    if c >= (n-1) and c <= factorial(n):

        if c > n:
            int_li = [i for i in range(n, 0, -1)]
        else:
            int_li = [i+1 for i in range(n)]

        permute_li = permutations(int_li)

        for val_li in list(permute_li):
            if reversort(n, c, list(val_li)):
                return ' '.join([str(val) for val in val_li])

    return 'IMPOSSIBLE'

t = int(input())

for i in range(t):
    str_li = input()
    n, c = (int(val) for val in str_li.split())

    print(f'Case #{i+1}: {reversort_engr(n, c)}')
