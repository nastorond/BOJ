import sys
input = sys.stdin.readline
n = int(input())
for _ in range(n):
    lis = list(input().rstrip())
    ck = []
    for _ in range(len(lis)):
        s = lis.pop()
        if len(ck):
            if s == '(' and ck[len(ck)-1] == ')': ck.pop()
            else: ck.append(s)
        else: ck.append(s)
    if len(ck): print('NO')
    else: print('YES')