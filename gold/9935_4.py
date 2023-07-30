import sys
from collections import deque

input = sys.stdin.readline
st = input().rstrip()
li = deque(st)
bom = input().rstrip()
sav = ''

while li:
    s = li.pop()
    s += sav
    sav = s

    if bom == sav[:len(bom)]:
        sav = sav.replace(bom, '', 1)
        li.extend(list(sav))
        sav = ''
        
if len(sav):
    print("".join(sav))
else:
    print('FRULA')