import sys
from collections import deque
input=sys.stdin.readline
out=sys.stdout.write
test=int(input())
for _ in range(test):
    p=deque(input().rstrip())
    n=int(input())
    s=input().rstrip()
    li=deque()
    for i in s:
        if i.isnumeric():li.append(i)
    for j in p:
        if j=='R':
            for _ in range(len(li)):
                li.appendleft(li.popleft())
            print(li)
        if j=='D':
            if len(li)>1:li.popleft()
            else:out('error\n')
    li=list(map(int,li))
    if len(li)>1:print(li)
    else:pass