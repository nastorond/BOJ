import sys
from collections import deque

input = sys.stdin.readline
n = int(input())
dec = deque()
for _ in range(n):
    s = input().rstrip()
    if s[0] == '1' or s[0] == "2":
        order, num = map(int, s.split())
    else:
        order = int(s)

    if order == 1:
        dec.appendleft(num)

    elif order == 2:
        dec.append(num)

    elif order == 3:
        if len(dec):
            print(dec.popleft())
        else:
            print(-1)

    elif order == 4:
        if len(dec):
            print(dec.pop())
        else:
            print(-1)

    elif order == 5:
        print(len(dec))

    elif order == 6:
        if len(dec):
            print(0)
        else:
            print(1)

    elif order == 7:
        if len(dec):
            print(dec[0])
        else:
            print(-1)

    elif order == 8:
        if len(dec):
            print(dec[-1])
        else:
            print(-1)
