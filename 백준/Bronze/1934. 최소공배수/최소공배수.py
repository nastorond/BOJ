import sys
input = sys.stdin.readline
n = int(input())
arr=[]
ans = 0
for _ in range(n):arr.append(list(map(int,input().split())))
for i in arr:
    a=i[0];b=i[1]
    if a == 1 or b == 1: ans = a*b
    else:
        while a!=0:
            b=b%a
            a,b=b,a
        gcd=b
        ans=i[0]*i[1]//gcd
    print(ans)