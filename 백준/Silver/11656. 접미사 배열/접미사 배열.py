s = input().rstrip()

result = []

for i in range(len(s)):
    cha = s[i:]
    result.append(cha)

result.sort()

for j in result:
    print(j)