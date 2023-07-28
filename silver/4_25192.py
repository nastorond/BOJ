## 인사성 밝은 곰곰이
import sys
input = sys.stdin.readline
n = int(input())
user_dict = dict()
cnt = 0
for _ in range(n):
    nm = input().rstrip()
    if nm == 'ENTER':
        user_dict.clear()
    elif user_dict.get(nm) == None:
        user_dict.update({nm: 1})
        cnt += 1
print(cnt)