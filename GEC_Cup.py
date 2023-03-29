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

## B번-특별한 작은 분수
import sys
out=sys.stdout.write
x,N = map(int,sys.stdin.readline().split())

for i in range(N):
    if x%2==0:
        x=x//2
        x=x^6
    else: x=x*2;x=x^6
out(str(x))