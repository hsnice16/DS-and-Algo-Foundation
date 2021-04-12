
def process(x: int, y: int, s: str, i: int, cost: int, temp: str):

    if i == len(s):
        return cost

    for j in range(i, len(s)):

        if s[j] == '?':
            print(s[:j])
            print(s[j+1:])
            return min(process(x, y, s[:j] + 'C' + s[j+1:], j, cost, temp), 
                    process(x, y, s[:j] + 'J' + s[j+1:], j, cost, temp))

        else:

            if len(temp) <= 1:
                temp += s[j]
            else:
                temp = temp[1] + s[j]

            if temp == 'CJ':
                return process(x, y, s, j+1, cost + x, temp)
            elif temp == 'JC':
                return process(x, y, s, j+1, cost + y, temp)

    return cost

def min_cost(x: int, y: int, s: str):

    cost = 0
    temp = ''
    i = 0

    return process(x, y, s, i, cost, temp)


t = int(input())

for i in range(t):
    li_in = input().split()

    # x : CJ , y : JC
    x, y, s = int(li_in[0]), int(li_in[1]), str(li_in[2])

    print(f'Case #{i+1}: {min_cost(x, y, s)}')
