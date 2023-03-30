## 1316 그룹단어체커
# import sys
# input=sys.stdin.readline
# anscnt = 0
# N=int(input())
# for i in range(N):
#     s =list(input())
#     if len(s) == 1:
#         anscnt = anscnt+1
#     else:
#         err = 0
#         for j in range(len(s)-1):
#             if s[j] != s[j+1]:
#                 word = s[j+1:]
#                 if word.count(s[j]) > 0 :
#                     err = err +1
#         if err == 0:
#             anscnt = anscnt + 1
# print(anscnt)

## 1712 손익분기점
# A, B, C= map(int,input().split())
# if (C-B) < 0 or (C-B) == 0:
#     i = -1
# else:
#     i = A/(C-B) +1
# print('%d' %(i))

## 2292 벌집
# N = int(input()) - 1
# i = 1
# while N>0:
#     N = N - (6*i)
#     i=i+1
# print(i)

## 1193 분수찾기
# import sys
# input = sys.stdin.readline
# N = int(input())
# i=1
# if N == 1:
#     print("1/1")
# else:
#     while N>0:
#         N = N-i
#         i = i+1
#     cnt = i-1
#     N = N + cnt
#     M = cnt + 1 - N 
#     if cnt%2 == 0:
#         print("%d/%d" %(N,M))
#     else :
#         print("%d/%d" %(M,N))

## 2869 달팽이는 올라가고 싶다
# import sys
# import math
# input = sys.stdin.readline
# A, B, V= map(int,input().split())
# x = (V-B)/(A-B)
# x = math.ceil(x) ## 소숫점 올림처리 이렇게하면 크거나 같다는 조건에 충족 가능
# print(x)

## 10250 ACM 호텔
# import sys
# input = sys.stdin.readline
# T = int(input())
# Ans = []
# for i in range(T):
#     H, W, N = map(int,input().split())
#     y = N%H       ## 나머지 = 층수 0이 되는 경우의 수를 고려해야함
#     x = N//H + 1  ## 몫 = 호수
#     if y == 0:
#         y = H
#         x = x-1
#     if x>9: ## 10 -> 9 변경
#         Ans.append("%d%d" %(y,x))
#     else :
#         Ans.append("%d0%d" %(y,x))
# for i in range(T):
#     print(Ans[i])
## 변수명을 동적으로 할당해서 뽑아내서 프린트 찍어주면 될것으로 보임 
## 11/15 왜안대냐 have to make equation agin
## 동적할당대신 이중배열 사용
## 몫과 나머지가 0일 경우 고려
## 11/16 식 다 틀렸으니까 처음부터 다시
## 진짜 모르겠다 이제
## 출력방식이 문제인가
## if의 조건이 문제


## 2775 부녀회장이 될테야
# import sys
# input = sys.stdin.readline
# T = int(input())
# ansf = []
# ansb = []
# for i in range(T):
#     af = int(input()) -1
#     ansf.append(af)
#     ab = int(input()) -1
#     ansb.append(ab)
# # V = [[0]*14]*14 # 이렇게하면 shallow copy 가 진행되어 모든 항목이 동일하게 복사됨
# V = [[0 for i in range(14)] for i in range(14)]
# for i in range(14):
#     V[i][0] = 1
# for i in range(1,14):
#     V[0][i] = V[0][i-1] + 1 + i # 2차원 벡터라고 했을때 위 행은 1부터 14 그러므로 +1 해줘야 맞음
# for i in range(1,14):
#     for j in range(1,14):
#         V[i][j] = V[i][j-1] + V[i-1][j]
# # for i in range(1,13):
# #     V[i][1] = V[i-1][1]+1
# # ans = []
# # for i in range(T):
# #     af = int(input())
# #     ab = int(input())
# #     # print(V[af][ab]) ## 런타임에러??
# #     ans.append(V[af][ab]) ## 컴파일 에러

# for i in range(T):
#     ans1=ansf[i]
#     ans2=ansb[i]
#     print(V[ans1][ans2]) # 맞긴했는데 맘에 안든다


## 행렬 [] 없이 출력 *arr
## 행렬 내림차순 정렬 arr.sort(reverse=True)

## 10757 큰 수 A+B
# a,b = map(int,input().split())
# print(a+b)

## 5086 배수와 약수
# import sys
# import math
# input = sys.stdin.readline
# while 1:
#     a, b = map(int, input().split())
#     if a == 0 and b == 0:
#         break
#     elif b/a == math.ceil(b/a):
#         print('factor')
#     elif a/b == math.ceil(a/b):
#         print("multiple")
#     else :
#         print("neither")

## 2501 약수구하기
# import sys
# input = sys.stdin.readline
# a, b = map(int, input().split())
# cnt = 0
# ans = 0
# n =1
# while 1:
#     if a%n == 0:
#         cnt += 1
#         ans = n
#     else:
#         pass

#     if cnt == b:
#         break
#     elif a<n:
#         ans = 0
#         break
#     n+=1
# print(ans)

## 9506 약수들의 합
# import sys
# input = sys.stdin.readline
# a = 0
# while a!=-1:
#     if a==0:
#         pass
#     else:
#         n=1
#         v=[]
#         while 1:
#             if a%n == 0:
#                 v.append(n)
#                 n+=1
#             elif a<n:
#                 break
#             else:
#                 n+=1
#             # print(n)
#         v.remove(v[len(v)-1])
#         # print(a, n, v)
#         ans = str(a)
#         ans = ans + " = 1"
#         if sum(v) == a:
#             v.remove(1)
#             for i in range(len(v)):
#                 ans = ans + " + "
#                 ans = ans + str(v[i]) ## 문자열 더하기
#             print(ans)
#         else:
#             print("%d is NOT perfect." %(a))
#     a = int(input())

## 24262 알고리즘 수업 - 알고리즘의 수행 시간 1
# import sys
# input = sys.stdin.readline
# n=int(input())
# print(1)
# print(0)

## 24263 알고리즘 수업 - 알고리즘의 수행 시간 2
# import sys
# input = sys.stdin.readline
# n = int(input())
# print(n)
# print(1)

## 24264 알고리즘 수업 - 알고리즘의 수행 시간 3
# import sys
# input = sys.stdin.readline
# n = int(input())
# print(n*n)
# print(2)

## 24265 알고리즘 수업 - 알고리즘의 수행 시간 4
# import sys
# input = sys.stdin.readline
# n = int(input())
# ans = 0
# for i in range(n-1) :
#     ans = ans+i+1
# print(ans)
# print(2)

## 24266 알고리즘 수업 - 알고리즘의 수행 시간 5
# import sys
# input = sys.stdin.readline
# n = int(input())
# print(n*n*n)
# print(3)

## 24267 알고리즘 수업 - 알고리즘의 수행 시간 6
# import sys
# input = sys.stdin.readline
# n = int(input())
# # v=list(range(0,n-1)) ##리스트 만들기
# # v1=list(range(2,n)) ## i+1 부터 시작하니까 2회반복부터 시작
# ans = (((n-2)*(n-1)*n)/6) ## 1부터 n까지 중복없이 순서 상관없이 3개씩 뽑는 경우의 수 nCr
# print(int(ans))
# print(3)
## nCr = n!/((n-r)!*r!)

## 24313 알고리즘 수업 - 점근적 표기 1
# import sys
# input = sys.stdin.readline
# a1, a0= map(int, input().split())
# c = int(input())
# n = int(input()) #순서대로 입력되네
# f = a1*n + a0
# o = c*n
# cnt = 0
# while n<100:
#     if f>o:
#         cnt += 1
#     n+=1
# if cnt == 0 and a1<=c:
#     print(1)
# else:
#     print(0)
# if f<=o and a1<=c:
#     print(1)
# else:
#     print(0)
##### a1이 c보다 작으면 a0가 음수일때 안될 가능성이 있음

## 2750 수 정렬하기
# import sys
# input = sys.stdin.readline
# a = int(input())
# v=[]
# for _ in range(a):
#     b = int(input())
#     v.append(b)
# v.sort(reverse=False)
# for _ in range(a):
#     print(v[_])
# ## 왜 print(v.sort(reverse=False))는 None으로 나오냐

## 2587 대표값 2
# import sys
# input = sys.stdin.readline
# v=[]
# for _ in range(5):
#     b = int(input())
#     v.append(b)
# v.sort()
# print(int(sum(v)/5))
# print(v[2])

## 25305 커트라인
# import sys
# input = sys.stdin.readline
# n, k = map(int, input().split())
# v = list(map(int, input().split())) ## 입력값 리스트로 받기
# v.sort(reverse=True)
# print(v[k-1])

## 2751 수 정렬하기 2
# import sys
# input = sys.stdin.readline
# n = int(input())
# v=[]
# for _ in range(n):
#     b = int(input())
#     v.append(b)
# v.sort(reverse=False)
# for i in range(n):
#     print(v[i])

## 10989 수 정렬하기 3
# import sys
# input = sys.stdin.readline
# n=int(input())

## 입력 받는 과정에서 메모리를 너무 많이 할당해서 실패
# v=[]
# for _ in range(n):
#     b=int(input())
#     v.append(b)

## sort 내장함수 사용 메모리 초과
# v=[]
# for _ in range(n):
#     b=int(input())
#     v.append(b)
# v.sort(reverse=False)
# for i in range(n):
#     print(v[i])

# ##Counting Sort 메모리 초과
# ## 얘는 성분이 자연수일 때만 가능하다는 한계가 있긴함
# v=[]
# for _ in range(n):
#     b=int(input())
#     v.append(b)
# count = [0] * (max(v) + 1)
# for num in v:
#     count[num] += 1
# for i in range(1, len(count)):
#     count[i] += count [i-1]
# result = [0] * (len(v))
# for num in v:
#     idx = count[num]
#     result[idx - 1] = num
#     count[num] -= 1
# for i in range(n):
#     print(result[i])

## Counting Sort Dictionary 사용 메모리 초과
# v=[]
# for _ in range(n):
#     b=int(input())
#     v.append(b)
# count = {}
# for num in v:
#     if num in count:
#         count[num] += 1
#     else:
#         count[num] = 1
# result = []
# for num in range(max(v) + 1):
#     while num in count and count[num] != 0:
#         result.append(num)
#         count[num] -= 1
# for i in range(n):
#     print(result[i])

## 이것도 계수정렬
# arr = [0]*10000
# for i in range(n):
#     a = int(input())
#     arr[a-1] += 1
# for i in range(10000):
#     if arr[i] != 0:
#         for j in range(arr[i]):
#             print(i+1)

## 2108 통계학
# import sys
# input = sys.stdin.readline
# n = int(input())
# v = []
# arr = [0]*n
# for _ in range(n):
#     v.append(int(input()))
# # v = [input() for _ in range(n)] ## 이렇게도 입력 가능 근데 문자열임
# ans1 = round(sum(v)/n)
# print(ans1)
# v.sort(reverse=False)
##ans2 = v[round(n/2)] ## 0이 안나옴 예제는 왜된겨
# ans2 = v[len(v)//2]
# print(ans2)
# ## 리스트를 3개이용한 개복잡한 거 시도하다 실패
# # if n==1:
# #     print(v[0])
# # elif n==3:
# #     print(v[1])
# # else:
# #     for i in range(n):
# #         if i == n-1:
# #             pass
# #         elif v[i] == v[i+1]:
# #            arr[i] += 1
# #            a=2
# #            while n-1 > i+a:
# #                if v[i]==v[i+a]:
# #                    arr[i]+=1
# #                a+=1
# #     cnt = []
# #     if max(arr)>0:
# #         for i in range(len(arr)):
# #             if i==len(arr)-1:
# #                 pass
# #             elif arr[i]==max(arr):
# #                 while len(arr)>i+m:
# #                     m=1
# #                     if arr[i]==arr[i+m]:
# #                         cnt[i]+=1
# #                         cnt[i+m]+=1
# #                     m+=1
# #                     ## 미완
# # 3번째 문제
# cnt=[0]*8001
# for i in range(len(v)):
#     cnt[4000+v[i]] += 1
# max_cnt = max(cnt)
# # cnt_idx = list(filter(lambda e:cnt[e] == max_cnt), range(len(cnt))) ## filter를 사용한 특정값의 인덱스 도출 얘는 왜 안되냐
# cnt_idx = [i for i, ele in enumerate(cnt) if ele == max_cnt] ## enumerate를 사용한 방법
# if len(cnt_idx) > 1:
#     print(cnt_idx[1]-4000)
# else:
#     print(cnt_idx[0]-4000)
# # 4번째꺼
# print(max(v) - min(v))

## 1427 소트인사이드
# import sys
# input = sys.stdin.readline
# n=str(input())
# list = list(n)
# list.remove(list[len(list)-1])
# cnt=''
# for i in range(len(list)):
#     list[i] = int(list[i])
# list.sort(reverse=True)
# for i in range(len(list)):
#     cnt = cnt+str(list[i])
# print(cnt)

## 11650 좌표 정렬하기
# import sys
# input = sys.stdin.readline
# n = int(input())
# co = []
# for _ in range(n):
#     a = list(map(int, input().split()))
#     co.append(a)

# #  이건 내가 한거 만든거 (안댐)
# # for i in range(n):
# #     if i == n-1:
# #         pass 
# #     elif co[i][0] > co[i+1][0]:
# #         sav = co[i]
# #         co[i] = co[i+1]
# #         co[i+1] = sav
# # for i in range(n):
# #     if i == n-1:
# #         pass
# #     elif co[i][0] == co[i+1][0]:
# #         if co[i][1] > co[i+1][1]:
# #             sav = co[i]
# #             co[i] = co[i+1]
# #             co[i+1] = sav

# co.sort(key=lambda x:(x[0],x[1]))
# # 키값을 매개변수로 가지는 sort는 key를 기준으로 오름차순 정렬이됨
# # lambda 식 또한 사용 가능
# for i in range(n):
#     print(co[i][0], co[i][1])

## 11651 좌표 정렬하기 2
# import sys
# input = sys.stdin.readline
# n = int(input())
# co = []
# for _ in range(n):
#     a = list(map(int, input().split()))
#     co.append(a)

# co.sort(key=lambda x:(x[1], x[0]))

# for i in range(n):
#     print(co[i][0], co[i][1])

## 1181 단어 정렬
# import sys
# input = sys.stdin.readline
# n = int(input())
# word = []
# for _ in range(n):
#     word.append(input().strip()) 
# # strip을 해주면 문자열 입력의 앞뒤를 잘라줌
# word = list(set(word))
# word.sort(key=lambda x:(len(x), (x)))
# # word.sort()
# # word.sort(key = len) ## 이게 더 빠름
# ##  lambda에서 기준을 넣을때 우선시 되는것부터 넣으면 되는듯?
# for i in range(len(word)):
#     print(word[i]) #, end='\b'

## 10814 나이순 정렬
# import sys
# input = sys.stdin.readline
# n = int(input())
# info = []
# for i in range(n):
#     a = list(input().split())
#     a[0] = int(a[0])
#     a.append(int(i))
#     info.append(a)
# info.sort(key=lambda x:(x[0], x[2]))
# for i in range(n):
#     print(info[i][0],info[i][1])

## 18870 좌표 압축
## 좌표압축 알고리즘을 통한 rank list 생성
# import sys
# input = sys.stdin.readline
# n = int(input())
# co = list(map(int, input().split()))
# sorted_co = list(set(co))
# sorted_co.sort()
# ans_dic = {}
# for i in range(len(sorted_co)):
#     ans_dic[sorted_co[i]] = int(i)
# for i in co:
#     print(ans_dic[i], end = ' ')
# print(*ans_dic.values())

''''
out = sys.stdout.write
out(f"{변수명} ")
out(f"\n")
3가지 -> print(), f"",  "{1} {2} {%.3f}".format(변수1, 변수2, 변수3)

1차원 한정 [a,b,c,d,e]
원하는 출력 = a b c d e
print(*ans_dic)

"[a, a, a, a, a, a]"  -> aaaaaa
"".join(변수명)
'''
## 뒤에 % 나와도 상관없는듯? 시발
## 아래는 시간복잡도가 높아서 시간초과뜸
# for i in range(n):
#     for j in range(len(sorted_co)):
#         if co[i]==sorted_co[j]:
#             co[i]=int(j)

# # arr = []
# # for i in co:
# #     arr.append(sorted_co.index(i))
# # ans=''
# # for i in range(n):
# #     ans = ans + str(arr[i]) + " "
# ## print("".join(arr))
# # print(ans)

## 2798 블랙잭
# import sys
# input = sys.stdin.readline
# num, lim = map(int, input().split())
# num_list = list(map(int, input().split()))
# ans = 0
# for i in range(num):
#     for j in range(num):
#         for k in range(num):
#             if k+2 > num-1 or j+1 > num-1:
#                 break
#             elif i == j+1 or i==k+2 or j+1==k+2:
#                 pass
#             else:    
#                 sum = num_list[i] + num_list[j+1] + num_list[k+2]
#                 if sum < lim:
#                     if ans < sum:
#                         ans = sum
#                     else:
#                         pass
#                 elif sum == lim:
#                     ans = lim
#                     break
# print(ans)

## 2231 분해합
# import sys
# input = sys.stdin.readline
# n = int(input())
# # list = list(map(int, str(n)))
# ## 숫자 리스트로 쪼개기
# cnt = 1
# ans = 0
# cnt_ck=[]
# while cnt<n:
#     list_cnt = list(map(int, str(cnt)))
#     cnt_sum = cnt+sum(list_cnt)
#     if cnt_sum == n:
#         cnt_ck.append(cnt)
#         ans = cnt_ck[0]
#     cnt = cnt+1
# print(ans)

# 7568 덩치
# import sys
# input = sys.stdin.readline
# n = int(input())
# info = []
# for _ in range(n):
#     info.append(list(map(int, input().split())))
# for i in info:
#     cnt = 1
#     for j in info:
#         if i[0] < j[0] and i[1] < j[1]:
#             cnt += 1
#     print(cnt, end=' ')

# ## 실패작
# sorted_info = sorted(info.keys(), key=lambda x:(x[0],[1]), reverse=True)
# cnt = 1
# oth_cnt = 1
# for i in range(n):
#     if i+1 == n:
#         pass
#     elif sorted_info[i][1] > sorted_info[i+1][1] and sorted_info[i][0] > sorted_info[i+1][0]:
#         if cnt == oth_cnt:
#             pass
#         elif sorted_info[i-1][1] < sorted_info[i][1] or sorted_info[i-1][0] == sorted_info[i][0]:
#             cnt = cnt
#         else:
#             cnt = oth_cnt
#         info[sorted_info[i]] = cnt
#         cnt += 1
#         oth_cnt += 1
#     elif sorted_info[i][1] < sorted_info[i+1][1]:
#         info[sorted_info[i]] = cnt
#         oth_cnt += 1

# if sorted_info[n-2][1] < sorted_info[n-1][1]:
#     info[sorted_info[n-1]] = cnt
# else: 
#     info[sorted_info[n-1]] = n
# print(*info.values())

# for i in info.keys():
#     print(info[i], end = " ")
# while True:
#     cnt = 0
#     if info[cnt]
# print(info)

## 27866 문자와 문자열
# import sys
# input = sys.stdin.readline
# word = list(input())
# n = int(input())
# print(word[n-1])

## 2355 시그마
# import sys
# input = sys.stdin.readline
# a, b = map(int, input().split())
# if a>b:
#     ans = a
#     a = b
#     b = ans
# print(((b+1)*b//2)-((a-1)*a//2))

# ## // 정수몫

# a,b = map(int,input().split())
# if a>b:
#     a,b=b,a
# print(b*(b+1)//2-a*(a-1)//2)

## 19532 수학은 비대면강의 입니다
# import sys
# a, b, c, d, e, f = map(int,sys.stdin.readline().split())
# for x in range(-999, 1000):
#     for y in range(-999, 1000):
#         if a*x + b*y == c and d*x + e*y == f:
#             print("%d %d" %(x,y))

## 10172 개
# print("|\_/|")
# print("|q p|   /}")
# print("( 0 )\"\"\"\\")
# print("|\"^\"`    |")
# print("||_/=\\\__|")

## 1018 체스판 다시 칠하기
# import sys
# N, M = map(int,sys.stdin.readline().split())
# arr = []
# for _ in range(N):
#     arr.append(list(sys.stdin.readline().rstrip()))

# answer_W = [['W' for _ in range(M)] for _ in range(N)]
# for i in range(1,N,2):
#     for j in range(0,M,2):
#         answer_W[i][j] = 'B'
# for i in range(0,N,2):
#     for j in range(1,M,2):
#         answer_W[i][j] = 'B'

# answer_H = [['B' for _ in range(M)] for _ in range(N)]
# for i in range(1,N,2):
#     for j in range(0,M,2):
#         answer_H[i][j] = 'W'
# for i in range(0,N,2):
#     for j in range(1,M,2):
#         answer_H[i][j] = 'W'

# mx = 1e9

# for i in range(M-7):

#     for j in range(N-7):
#         cnt_H = 0
#         cnt_W = 0
#         for c in range(i,i+8):
#             for k in range(j,j+8):
#                 if arr[k][c] != answer_H[k][c]:cnt_H+=1
#                 if arr[k][c] != answer_W[k][c]:cnt_W+=1 
#         mx=min(cnt_H,cnt_W,mx)

# print(mx)

## 1436 영화감독 숌
# import sys
# n = int(sys.stdin.readline())
# num = 666
# arr = []
# cnt = 0
# while True:
#     if '666' in str(num): 
#         arr.append(num)
#         cnt+=1
#         if cnt==10000:
#             break
#     num += 1

# print(arr[n-1])

## 2839 설탕배달
# import sys
# n = int(sys.stdin.readline())
# arr=[]
# for i in range(0,3000):
#     for j in range(0,3000):
#         if 5*i + 3*j == n:
#             arr.append(i+j)
# if len(arr) != 0:
#     print(min(arr))
# else:
#     print(-1)

## 25314 코딩은 체육과목 입니다
# import sys
# n = int(sys.stdin.readline())
# n = n//4
# for _ in range(n):
#     print('long', end=" ")
# print('int')

## 25206 너의 평점은
# import sys
# score = []
# ans = []
# cnt = 0
# for _ in range(20):
#     score.append(list(sys.stdin.readline().rstrip().split()))
# for i in score:
#     if i[2] == 'A+': ans.append(float(i[1])*4.5);cnt=cnt+float(i[1])
#     elif i[2] == 'A0': ans.append(float(i[1])*4);cnt=cnt+float(i[1])
#     elif i[2] == 'B+': ans.append(float(i[1])*3.5);cnt=cnt+float(i[1])
#     elif i[2] == 'B0': ans.append(float(i[1])*3);cnt=cnt+float(i[1])
#     elif i[2] == 'C+': ans.append(float(i[1])*2.5);cnt=cnt+float(i[1])
#     elif i[2] == 'C0': ans.append(float(i[1])*2);cnt=cnt+float(i[1])
#     elif i[2] == 'D+': ans.append(float(i[1])*1.5);cnt=cnt+float(i[1])
#     elif i[2] == 'D0': ans.append(float(i[1])*1);cnt=cnt+float(i[1])
#     elif i[2] == 'F': cnt=cnt+float(i[1])
# print("{:.6f}".format(sum(ans)/cnt))

## 1934 최소공배수
# ##최소공배수는 두 수의 곱 나누기 최대공약수로 구할 수 있다
# import sys
# input = sys.stdin.readline
# n = int(input())
# arr=[]
# cnt = 1 
# ans = 0
# for _ in range(n):arr.append(list(map(int,input().split())))
# for i in arr:
#     a=i[0];b=i[1]
#     if a == 1 or b == 1: ans = a*b
#     else:
#         while a!=0: ## 최대공약수 구하는 알고리즘
#             b=b%a
#             a,b=b,a
#         gcd=b
#         ans=i[0]*i[1]//gcd
#         # for j in range((max(a,b)),(a*b)+1): ## 시간초과
#         #     if j%a==0 and j%b==0:
#         #         ans=j
#         #         break

#         # while True: ## 안댐
#         #     if (a*cnt)%b == 0:
#         #         ans=a*cnt
#         #         break
#         #     cnt += 1
#     print(ans)

## 13241 최소공배수
# import sys
# a, b = map(int, sys.stdin.readline().split())
# c,d = a,b
# while c!=0:
#     d=d%c
#     c,d=d,c
# gcd = d
# print(a*b//gcd)

## 1735 분수합
# import sys
# input = sys.stdin.readline
# a,c = map(int, input().split())
# b,d = map(int, input().split())
# e=a*d+b*c
# f=c*d
# num1,num2=e,f
# while num1!=0:
#     num2=num2%num1
#     num1,num2=num2,num1
# gcd = num2
# e=e/gcd
# f=f/gcd
# print('%d %d' %(e,f))

## 2485 가로수
# import sys
# input = sys.stdin.readline
# n = int(input())
# arr=[]
# for _ in range(n):arr.append(int(input()))
# answer=[]
# for i in range(len(arr)-1):answer.append(arr[i+1]-arr[i])
# answer_set = list(set(answer))
# gcd_=1
# for j in range(1,len(answer_set)):
#     a,b=answer_set[j],answer_set[j-1]
#     while a!=0:
#         b=b%a
#         a,b=b,a
#     answer_set[j]=b
# gcd_=answer_set[len(answer_set)-1]
# ans = 0
# for i in answer:
#     c=i//gcd_-1
#     ans=ans+c
# print(ans)

## 4134 다음 소수
# import sys
# import math
# input = sys.stdin.readline
# n = int(input())

# def ck_prime(x):
#     if x==0 or x==1:return False
#     for i in range(2,int(math.sqrt(x))+1):
#         if x%i==0:
#             return False
#     return True

# for _ in range(n):
#     num=int(input())
#     while True: 
#     ## 시간초과
#     #     cnt=0
#     #     for i in range(2,int(math.sqrt(num))+1):
#     #         if num%i==0:
#     #             cnt+=1
#     #     if cnt!=0:
#     #         num+=1
#     #     else:
#     #         print(num)
#     #         break
#         if ck_prime(num):
#             print(num)
#             break
#         else:
#             num+=1

## 1929 소수구하기
# import sys
# M,N = map(int, sys.stdin.readline().split())

# def find_primes(b): ## 에라토스테네스의 체 구현
#     arr = []
#     primes=[]
#     for i in range(2,b+1):arr.append(i)
#     while True:
#         primes.append(arr[0])
#         a=arr[0]
#         for i in arr:
#             if i%a==0:
#                 arr.remove(i)
#         if len(arr)==0:
#             break
#     return primes

# def prime_list(b): ## 에라토스테네스의 체 구현2
#     sieve = [True]*b
#     for i in range(2,int(b**0.5)+1):
#         if sieve[i] == True:
#             for j in range(i+i,b,i):
#                 sieve[j] = False
#     return [i for i in range(2,b) if sieve[i] == True]


# def ck_prime(a):
#     if a==1:
#         return False
#     for i in range(2,int(a**0.5)+1): ##a**0.5랑 똑같음
#         if a%i==0:
#             return False
#     return True

# for i in range(M,N+1):
#     if ck_prime(i):
#         print(i,end=' ')

## 4948 베르트랑 공준
# import sys

# def prime_list(a,b): ## 에라토스테네스의 체 구현2
#     sieve = [True]*b
#     for i in range(2,int(b**0.5)+1):
#         if sieve[i] == True:
#             for j in range(i+i,b,i):
#                 sieve[j] = False
#     return [i for i in range(a+1,b) if sieve[i] == True]

# while True:
#     n=int(input())
#     if n==0:
#         break
#     elif n==1:
#         print(1)
#     else:
#         print(len(prime_list(n,2*n)))

## 2525 오븐 시계
# import sys
# input = sys.stdin.readline
# A,B = map(int,input().split())
# C=int(input())
# A=A+C//60
# B=B+C%60
# A=A+B//60
# B=B%60
# A=A%24
# print("%d %d" %(A,B))

## 2480 주사위 세개
# import sys
# a,b,c = map(int,sys.stdin.readline().split())
# if a==b and b==c:
#     print(10000+a*1000)
# elif a==b or b==c or a==c:
#     li=[]
#     li.append(a)
#     li.append(b)
#     li.append(c)
#     li.sort()
#     print(1000+li[1]*100)
# else:
#     ma=max(a,b,c)
#     print(ma*100)

## 10807 개수 세기
# import sys
# input = sys.stdin.readline
# n=int(input())
# li=list(map(int,input().split()))
# find_num=int(input())
# cnt=0
# for i in li:
#     if i == find_num:
#         cnt+=1
# print(cnt)

## 10810 공 넣기
# import sys
# input = sys.stdin.readline
# N,M = map(int,input().split())
# arr=[0]*N
# for i in range(M):
#     a,b,c=map(int,input().split())
#     if a==b:arr[a-1]=c
#     else:
#         for j in range(a-1,b):arr[j]=c
# print(*arr)

## 10813 공 바꾸기
# import sys
# input=sys.stdin.readline
# N,M=map(int,input().split())
# arr=[i+1 for i in range(N)]
# for _ in range(M):
#     i,j=map(int,input().split())
#     sav=arr[i-1]
#     arr[i-1]=arr[j-1]
#     arr[j-1]=sav
# print(*arr)

# def list_prime(a): ## 얘는 진짜 왜 안되냐
#     sieve = [True]*a
#     for i in range(2,int(a**0.5)+1):
#         if sieve[i]==True:
#             for j in range(i+i,a, i):
#                 sieve[j]==False
#     return [i for i in range(2,a) if sieve[i]==True]

## 17103 골드바흐 파티션
# import sys
# ipnut = sys.stdin.readline
# out = sys.stdout.write
# n = int(input())
# li=[]

# def prime_list(b): ## 에라토스테네스의 체 구현2
#     sieve = [True]*b
#     for i in range(2,int(b**0.5)+1):
#         if sieve[i]==True:
#             for j in range(i+i,b,i):
#                 sieve[j] = False
#     return [i for i in range(2,b) if sieve[i] == True],sieve

# for _ in range(n):li.append(int(input()))

# arr,ck=prime_list(max(li))
# ck[0],ck[1]=False,False

# for i in li:
#     cnt = 0
#     for j in range(len(arr)):
#         if i < arr[j]:break
#         elif ck[i-arr[j]]:cnt+=1

#     if i//2 in arr:
#         out(str(cnt//2 + 1)+'\n')
#     else:
#         out(str(cnt//2)+'\n')

## 10872 팩토리얼
# import sys

# def fac(n): ## 이게 왜 되냐
#     ans=1
#     if n>0:
#         ans = n*fac(n-1)
#     return ans

# n=int(sys.stdin.readline())
# print(fac(n))

## 10870 피보나치 수 5
# import sys

# def fibo(n):
#     ans = 1
#     if n > 2:
#         ans = fibo(n-1) + fibo(n-2)
#     return ans

# n=int(sys.stdin.readline())
# if n==0:sys.stdout.write('0')
# else:sys.stdout.write(str(fibo(n)))

## 2747 피보나치 수
# import sys

# def fibo(n):
#     if n==0: return arr[0]
#     elif n==1: arr[1]=1; return arr[1]
#     else:
#         if arr[n-1]!=0 and arr[n-2]!=0:
#             arr[n] = arr[n-1]+arr[n-2]
#             return arr[n]
#         else:
#             arr[n]=fibo(n-1)+fibo(n-2); return arr[n]

# # def fibo(n):
# #     if n==0: return 0
# #     if n==1: return 1
# #     if n==2: return 1
# #     if dp[n]: return dp[n]

# #     dp[n] = fibo(n-1) + fibo(n-2) 
# #     return dp[n]

# n=int(sys.stdin.readline())
# arr=[0]*(n+1)
# sys.stdout.write(str(fibo(n)))

## 25501 재귀의 귀재
# import sys
# input=sys.stdin.readline
# out = sys.stdout.write

# def recursion(s, l, r):
#     if l >= r: return 1,l+1
#     elif s[l] != s[r]: return 0,l+1
#     else: return recursion(s, l+1, r-1)

# def isPalindrome(s):
#     a,b = recursion(s, 0, len(s)-1)
#     return a,b

# n=int(input())
# for _ in range(n):
#     S=input().rstrip()
#     a,b=map(str,isPalindrome(S))
#     out(a+' '+b+"\n")

## 24060 알고리즘 수업 - 병합 정렬 1
# import sys
# input = sys.stdin.readline

# def merge_sort(a,p,r):
#     if p<r:
#         q=(p+r)//2
#         merge_sort(a,p,q)
#         merge_sort(a,q+1,r)
#         return merge(a,p,q,r)

# def merge(A,p,q,r):
#     global cnt, res
#     i=p;j=q+1
#     tmp=[]
#     while(i<=q and j<=r):
#         if A[i]<=A[j]:tmp.append(A[i]);i+=1
#         else: tmp.append(A[j]);j+=1
#     while i<=q:tmp.append(A[i]);i+=1
#     while j<=r:tmp.append(A[j]);j+=1
#     i=p;t=0
#     while i<=r:
#         cnt +=1
#         if cnt==K:
#             res=tmp[t]
#         A[i]=tmp[t]
#         i+=1
#         t+=1
#     return res

# global cnt, res
# cnt = 0
# res = -1
# A,K=map(int,input().split())
# li=list(map(int,input().split()))
# print(merge_sort(li,0,A-1))

## 4779 칸토어 집합
import sys
input=sys.stdin.readline
out=sys.stdout.write

def khan(n):
    
    if n[0]!=n[1]:
        return n
    else: 
        return khan(n)

# n=[]
# while True: EOF 파일의 끝에서 입력을 멈춘다
#     try:
#         a = map(int, input().split())
#         n.append(a)
#     except EOFError:
#         break
n=int(input())
arr=['\n']*3**n
print(khan(arr))