n = int(input())

if n == 1:
    print(0)
else:
    n = 2 * (3**(n-2))
    n = n % 1000000009
    print(n)