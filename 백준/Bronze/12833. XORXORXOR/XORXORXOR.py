A, B, C = map(int, input().split())
ans = [A ^ B, (A ^ B) ^ B]
if C % 2:
    print(ans[0])
else:
    print(ans[1])