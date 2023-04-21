## A번 당신은 운명을 믿나요?
# import sys
# out=sys.stdout.write
# S=list(sys.stdin.readline().rstrip())
# ansk=""
# ansy=""
# for i in S:
#     if i=='K' and ansk=='':ansk+=i
#     elif i=='O'and ansk=='K':ansk+=i
#     elif i=='R'and ansk=='KO':ansk+=i
#     elif i=='E'and ansk=='KOR':ansk+=i
#     elif i=='A'and ansk=='KORE':ansk+=i

#     if i=='Y'and ansy=='':ansy+=i
#     elif i=='O'and ansy=='Y':ansy+=i
#     elif i=='N'and ansy=='YO':ansy+=i
#     elif i=='S'and ansy=='YON':ansy+=i
#     elif i=='E'and ansy=='YONS':ansy+=i
#     elif i=='I'and ansy=='YONSE':ansy+=i

#     if ansk=="KOREA":out(ansk);break
#     elif ansy=="YONSEI":out(ansy);break

## B번 Parity Constraint Closest Pair



## C번 어깨동무
import sys
input=sys.stdin.readline
n,k=map(int,input().split())
h=list(map(int,input().split()))
li=[0]*101
for i in range(1,len(h)):
    if abs(h[i-1]-h[i]):li[abs(h[i-1]-h[i])]+=1
cnt=0
while 1:
    if sum(li)<=k:break
    else: li[cnt]=0
    cnt+=1

# cnt=0 시간초과
# while 1:
#     cnt+=1
#     if len(li)>k:li=[i for i in li if i!=cnt]
#     else:break

sys.stdout.write(str(cnt))
