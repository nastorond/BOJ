n = int(input())
jd = dict()
for i in range(n):
    num = int(input())
    if num in jd:
        jd[num] += 1
    else:
        jd[num] = 1
    
result = sorted(jd.items(), key = lambda x:(-x[1],x[0]))
print(result[0][0])