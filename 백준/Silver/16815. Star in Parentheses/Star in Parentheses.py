import sys
input = sys.stdin.readline
s = list(input().rstrip())
stack = 0
for i in s:
    if i == '(':
        stack += 1
    elif i == ')':
        stack -= 1
    else:
        break
print(stack)
