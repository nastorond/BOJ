import sys
input = sys.stdin.readline
a, k = map(int, input().split())
li = list(map(int, input().split()))
cnt = 0
flg = False
for i in range(a):
    for j in range(a-i-1):
        if li[j] > li[j+1]:
            li[j], li[j + 1] = li[j + 1], li[j]
            cnt += 1
        if cnt == k:
            print(li[j], li[j+1])
            flg = True
            break
    if flg:
        break
else:
    print(-1)