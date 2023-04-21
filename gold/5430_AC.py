import sys
from collections import deque
input=sys.stdin.readline
out=sys.stdout.write
test_case=int(input())
for _ in range(test_case):
    p=deque(input().rstrip())
    n=int(input())
    li=deque(input().rstrip()[1:-1].split(','))
    ##아무것도 없어도 len이 1로 잡힘, 입력 저렇게도 가능
    cnt,flag=0,0
    if n==0:li=[]
    for j in p:
        if j=='R':
            cnt+=1
        elif j=='D':
            if len(li)<1:flag=1;out('error\n');break
            else:
                if cnt%2==0:li.popleft()
                else:li.pop()
    if flag==0:
        if cnt%2==0:out('['+','.join(li)+']\n')
        else:
            li.reverse()
            out('['+','.join(li)+']\n')