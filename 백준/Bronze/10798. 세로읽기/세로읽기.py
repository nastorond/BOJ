import sys

input = sys.stdin.readline

fld = []
max_val = 0
for _ in range(5):
    s = input().rstrip()
    max_val = max(len(s), max_val)
    fld.append(s)

ans = ''
for i in range(max_val):
    for j in range(5):
        try:
            ans += fld[j][i]
        except IndexError:
            pass
print(ans)