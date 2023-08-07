from collections import deque

n,k = map(int, input().split())
li = deque(i for i in range(1,n+1))
cnt = 0
res=[]
while 1:
    cnt += 1
    sav = li.popleft()
    if cnt%k == 0:
        res.append(sav)
    else:
        li.append(sav)
    if len(li)==0: break
print('<', end = '')
print(*res, sep=', ', end='')
print('>')