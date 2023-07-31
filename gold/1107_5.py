# import sys
#
# input = sys.stdin.readline
# Num = int(input().rstrip())
# N = int(input())
# if N:
#     li = list(input().split())
# else:
#     li = []
#
# mn_mx, mn_mn = abs(Num - 100), abs(Num - 100)
#
# if int(Num) == 100:
#     print(0)
# else:
#     for i in range(Num, 500000 * 2):
#         for j in str(i):
#             if j in li:
#                 break
#         else:
#             mn_mx = i
#             break
#
#     for i in range(Num, -1, -1):
#         for j in str(i):
#             if j in li:
#                 break
#         else:
#             mn_mn = i
#             break
#
#     res_mn = abs(Num - mn_mn) + len(str(mn_mn))
#     res_mx = abs(Num - mn_mx) + len(str(mn_mx))
#
#     print(min(res_mn, res_mx, abs(Num - 100)))

import sys
input = sys.stdin.readline
target = int(input())
n = int(input())
broken = list(map(int, input().split()))
min_cnt = abs(100 - target)
for nums in range(1000001):
    nums = str(nums)

    for j in range(len(nums)):
        if int(nums[j]) in broken:
            break
        elif j == len(nums) - 1:
            min_cnt = min(min_cnt, abs(int(nums) - target) + len(nums))

print(min_cnt)
