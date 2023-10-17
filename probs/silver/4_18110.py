import sys
from collections import deque
input = sys.stdin.readline
n = int(input())
if n:
    op_li = deque(int(input()) for _ in range(n))
    op_li = deque(sorted(op_li))
    num_p = round(n*0.15 + 0.00000000001)
    for i in range(num_p):
        op_li.pop()
        op_li.popleft()
    res = round(sum(op_li)/len(op_li) + 0.0000000001)
    print(res)
else:
    print(0)