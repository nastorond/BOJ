n = int(input())
list_n = list(bin(n))
list_n = list_n[::-1]

list_n.pop()
list_n.pop()

ans = 0
for i in range(len(list_n)):
    if list_n[i] == '1':
        ans += 3**i

print(ans)