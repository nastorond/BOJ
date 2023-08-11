import sys

input = sys.stdin.readline

num = int(input())
if num > 1:
    num_list = list(map(int, input().split()))
    num_list.sort()
    print(num_list[0] * num_list[-1])
else:
    number = int(input())
    print(number**2)
