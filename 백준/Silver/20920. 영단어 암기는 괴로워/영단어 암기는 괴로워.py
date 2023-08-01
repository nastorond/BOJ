import sys
input = sys.stdin.readline
n, m = map(int, input().split())
words = {}
for i in range(n):
    s = input().rstrip()
    if len(s) >= m:
        if words.get(s):
            words[s] += 1
        else:
            words[s] = 1
li = [(k, v) for k, v in words.items()]

for i in range(len(li)):
    li[i] += (len(li[i][0]),)

res = sorted(li, key=lambda x: (-x[1], -x[2], x[0]))


for i in res:
    print(i[0])
