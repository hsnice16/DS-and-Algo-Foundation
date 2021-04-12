

def reversort(n: int, int_li: list) -> int:
    cost = 0
    for i in range(n-1):
        j = int_li.index(min(int_li[i:]), i)
        
        int_li[i:j+1] = reversed(int_li[i:j+1])
        cost += (j - i + 1)
        
    return cost


t = int(input())

for i in range(t):
    n = int(input())
    str_li = input()
    int_li = [int(val) for val in str_li.split()]

    print(f'Case #{i+1}: {reversort(n, int_li)}')
