import sys
sys.setrecursionlimit(10 ** 6)
input=sys.stdin.readline
n,m,r=map(int,input().split())
gp=[[] for _ in range(n+1)]
vt=[0]*(n+1)
cnt=1

def dfs(gp,e,vt):
    global cnt
    vt[e]=cnt
    for i in gp[e]:
        if vt[i]==0:
            cnt+=1
            dfs(gp,i,vt)

for _ in range(m):
    i,j=map(int,input().split())
    gp[i].append(j)
    gp[j].append(i)
for i in range(n):gp[i].sort()
dfs(gp,r,vt)
for i in range(1,n+1):print(vt[i])