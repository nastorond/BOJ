def multi(a, b):
    c = [[0, 0], [0, 0]]
    mod = 1000000007
    c[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % mod
    c[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % mod
    c[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % mod
    c[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % mod
    return c
def div_con(a, pos1):
    if pos1 == 1:
        return a
    elif pos1 % 2:
        return multi(div_con(a, pos1 - 1), a)
    else:
        return div_con(multi(a, a), pos1//2)
n = int(input())
first = [[1, 1], [1, 0]]
if n < 3:
    print(1)
else:
    res = multi(div_con(first, n-2), first)
    print(res[0][0])