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

'''
N, M = map(int, input().split())
arr = [i+1 for i in range(N)]
res_arr = []
now_idx = M-1
while len(arr) > 1:
    res_arr.append(arr.pop(now_idx))
    now_idx += M-1
    now_idx %= len(arr)
res_arr.append(arr.pop())
res_arr = str(res_arr)
print('<'+res_arr[1:-1]+'>')
'''