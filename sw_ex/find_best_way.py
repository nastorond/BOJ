import itertools as it

def cal_dis(x1,x2,y1,y2):
    return abs(x1+x2),abs(y1+y2)

n=int(input())

for _ in range(n):
    m=int(input())
    li=list(map(int,input().split()))
    comp = (li[0],li[1])
    hom = (li[2], li[3])
    points = li[4:]
    p=[]
    for i in range(0,len(points), 2):
        p.append((points[i],points[i+1]))
    
    # for i in it.permutations(p):
    #     print(*list(i))
    print(list(it.permutations(p))) ## 모든 경우의수 뽑아줌