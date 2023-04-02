import sys
ans=0
for i in range(4):
    a=sys.stdin.readline().rstrip()
    if 'Es' in a:
        ans+=int(a[3:])*21
    elif 'Stair' in a:
        ans+=int(a[6:])*17
print(ans)