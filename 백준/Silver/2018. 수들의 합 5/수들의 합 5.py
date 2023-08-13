# import sys

# input = sys.stdin.readline

# n = int(input())
# start = 1
# end = 2
# cnt = 0
# num_list = list(range(n+1))
# while start <= end:
#     ck = 0
#     # for i in range(start, end+1):
#     for i in num_list[start:end+1]:
#         ck += i
#     if ck == n:
#         cnt += 1
#         start += 1
#     elif ck < n:
#         end += 1
#     else:
#         start += 1
# print(cnt)

n = int(input())
cnt, ck = 0, 0
start, end = 0, 0

while end <= n:
    if ck < n:
        end += 1
        ck += end
    elif ck > n:
        ck -= start
        start += 1
    else:
        cnt += 1
        end += 1
        ck += end
print(cnt)