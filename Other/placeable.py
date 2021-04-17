from itertools import permutations

def find_fulcrum(li: list):
    for i in range(len(li)):
        sum1 = sum(li[:i+1])
        sum2 = sum(li[i+1:])

        if sum1 == sum2:
            return True
    return False

def placeable(inn: list):
    permute = [list(val) for val in permutations(inn)]

    for val in permute:
        if(find_fulcrum(val)):
            return True
    return False


in_li = input().split()
inn = [int(var) for var in in_li]

print(bool(placeable(inn)))
