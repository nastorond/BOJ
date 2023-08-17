import sys
from collections import deque
n=int(sys.stdin.readline())
li=deque(i for i in range(1,n+1))
while len(li)>1:
    li.popleft()
    li.append(li.popleft())
sys.stdout.write(str(li[0]))