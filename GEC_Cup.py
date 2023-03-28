## A번-특별한 학교 이름
# import sys
# na=str(sys.stdin.readline())
# ncls = 'North London Collegiate School'
# bha='Branksome Hall Asia'
# kis='Korea International School'
# sja='St. Johnsbury Academy'

# if 'NLCS' in na:
#     print(ncls)
# elif 'BHA' in na:
#     print(bha)
# elif 'KIS' in na:
#     print(kis)
# else:
#     print(sja)

## B번-특별한 작은 분수 실패
import sys
x0,N = map(int, sys.stdin.readline().split())
cnt=0
ans=0
while cnt!=N:
    cnt+=1
    if x0==0:
        ans=0;break
    elif x0%2==0: x0=x0//2
    else: x0=2*x0
    x0=x0^6
    ans=x0
print(ans)
