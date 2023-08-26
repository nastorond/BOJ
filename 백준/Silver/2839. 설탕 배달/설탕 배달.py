import sys
n = int(sys.stdin.readline())
arr=[]
for i in range(0,3000):
    for j in range(0,3000):
        if 5*i + 3*j == n:
            arr.append(i+j)
if len(arr) != 0:
    print(min(arr))
else:
    print(-1)