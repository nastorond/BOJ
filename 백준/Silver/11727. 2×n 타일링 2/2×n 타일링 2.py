n = int(input())
paper = [0, 1, 3]
for i in range(3, n+1):
    paper.append(paper[i-1] + 2*paper[i-2])
print(paper[n] % 10007)