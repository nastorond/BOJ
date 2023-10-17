import sys
from collections import deque

input = sys.stdin.readline
s = input().rstrip()
bom = input().rstrip()
sav = []

for alp in s:
    sav.append(alp)
    if alp == bom[-1] and ''.join(sav[-len(bom):]) == bom:
        del sav[-len(bom):]

if len(sav):
    print("".join(sav))
else:
    print('FRULA')