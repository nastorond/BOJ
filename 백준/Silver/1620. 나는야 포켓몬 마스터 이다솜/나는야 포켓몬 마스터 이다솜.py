# BOJ_1620 : 나는야 포켓몬 마스터 이다솜
import sys

input = sys.stdin.readline
poke_name = dict()
poke_num = dict()

n, m = map(int, input().rstrip().split())
for num in range(1, n + 1):
    name = input().rstrip()
    poke_name[num] = name
    poke_num[name] = num

for _ in range(m):
    info = input().rstrip()
    if info.isdigit():
        print(poke_name[int(info)])
    else:
        print(poke_num[info])