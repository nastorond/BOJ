mn, mx = map(int, input().split())
li = [True for _ in range(mx-mn+1)]
for i in range(2, 10**6+1):
    sq = i * i
    fir = ((mn + sq -1)//sq)*sq
    for j in range(fir, mx+1, sq):
        li[j-mn] = False
print(sum(li))   





# mn, mx = map(int, input().split())

# li = [True for _ in range(mx - mn + 1)]

# for i in range(2, 10**6 + 1):
#     sq = i**i

#     fir = ((mn + sq - 1) // sq)*sq

#     for j in range(fir, mx+1, sq):
#         li[j-mn] = False

# print(sum(li))