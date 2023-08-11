import sys

input = sys.stdin.readline


def solution(pos1, lis):
    up_limit_num = 0
    down_limit_num = 0
    for i in lis:
        if i < pos1:
            down_limit_num = i
        if i > pos1:
            up_limit_num = i
            break
        elif i == n:
            ans = 0
            return ans
    
    # 같으면 안되니까
    down_limit_num += 1
    cnt = 0
    for i in range(down_limit_num, pos1+1):
        for j in range(i+1, up_limit_num):
            if j >= pos1:
                cnt += 1

    return cnt


L = int(input())
num_list = list(map(int, input().split()))
n = int(input())
num_list.sort()

answer = solution(n, num_list)
print(answer)