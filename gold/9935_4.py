import sys
from collections import deque
input = sys.stdin.readline
li = deque(input().rstrip())
bom = input().rstrip()
sav = ''
while True:
    try:
        s = li.pop()
        sav += s
        
        if not len(li):
            if len(bom):
                li.extend(bom)
        
    except:
        if len(li):
            print("".join(li))
        else:
            print('FRULA')
        break