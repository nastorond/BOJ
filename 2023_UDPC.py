## A번 탁구 경기
# import sys
# input=sys.stdin.readline
# n=int(input())
# cnt1,cnt2=0,0
# while 1:
#     a=str(input())
#     if 'D' in a:
#         cnt1+=1
#     elif 'P' in a:
#         cnt2+=1
    
#     if cnt1+cnt2 == n:
#         break
#     elif cnt1-cnt2==2 or cnt2-cnt1==2:
#         break
# print('%d:%d' %(cnt1,cnt2))

## B번 UDPC 파티
import sys
v=list(map(str,sys.stdin.readline().rstrip()))
cnt_uc,cnt_dp=0,0
for i in v:
    if 'U' in i or 'C' in i:cnt_uc+=1
    else: cnt_dp+=1

if cnt_dp==0:print('U')
elif cnt_uc==1 and cnt_dp==1:print("DP")
elif cnt_uc<cnt_dp:
    if cnt_dp//2 < cnt_uc: print('U')
    else: print('DP')
elif cnt_uc>cnt_dp:
    print('UDP')