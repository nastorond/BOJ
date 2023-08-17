import sys
from collections import deque
n,k=map(int,sys.stdin.readline().split())
li=deque(str(i) for i in range(1,n+1))
ans=[]
for i in range(n):
    for j in range(k-1):
        li.append(li.popleft())
    ans.append(li.popleft())
sys.stdout.write('<'+', '.join(ans)+'>\n')