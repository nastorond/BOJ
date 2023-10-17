## A 가지교배
# import sys
# input=sys.stdin.readline
# n=int(input())
# egg_spe=list(input().split())
# m,k=map(int,input().split())
# cnt=0
# for i in range(m):
#     a=[]
#     for j in list(map(int,input().split())):
#         a.append(egg_spe[j-1])
#     if 'P' in a:pass
#     else:cnt+=1
# if cnt:sys.stdout.write('W')
# else:sys.stdout.write('P')

## B 가지 산사태
import sys
input=sys.stdin.readline
n,m,k=map(int,input().split())
ck=0
overflo=0
a=0
for i in range(m):
    a,b=map(int,input().split())
    if ck<k:
        ck+=b
        a=i
    else:overflo+=1

if overflo==0:sys.stdout.write('-1')
else:sys.stdout.write(str(a+1)+' '+'1')