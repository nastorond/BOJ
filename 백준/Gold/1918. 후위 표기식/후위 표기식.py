import sys
input = sys.stdin.readline

infix_list = input().rstrip()

icp = {'(': 3, '+': 1, '-': 1, '*': 2, '/': 2}
isp = {'(': 0, '+': 1, '-': 1, '*': 2, '/': 2}

postfix_fx = ''
stack = []

for x in infix_list:
    if x.isalpha():
        postfix_fx += x
    elif x == ')':
        while stack[len(stack)-1] != '(':
            postfix_fx += stack.pop()
        stack.pop()
    else:
        if not stack or icp[x] > isp[stack[-1]]:
            stack.append(x)
        elif icp[x] <= isp[stack[-1]]:
            while len(stack) > 0 and icp[x] <= isp[stack[-1]]:
                postfix_fx += stack.pop()
            stack.append(x)
if stack:
    while stack:
        postfix_fx += stack.pop()
print(postfix_fx)
