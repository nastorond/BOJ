import sys
input=sys.stdin.readline
n=int(input())
li=list(map(int,input().split()))
cnt=0
for i in li:
    if i==1:cnt+=1
    else:
        for j in range(2,int(i**0.5)+1):
            if i%j==0:cnt+=1;break
sys.stdout.write(str(n-cnt))