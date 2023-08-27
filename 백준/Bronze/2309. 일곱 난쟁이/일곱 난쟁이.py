import sys

input = sys.stdin.readline

h = [int(input()) for _ in range(9)]

ans = []
for n1 in range(len(h)):
    for n2 in range(n1 + 1, len(h)):
        for n3 in range(n2 + 1, len(h)):
            for n4 in range(n3 + 1, len(h)):
                for n5 in range(n4 + 1, len(h)):
                    for n6 in range(n5 + 1, len(h)):
                        for n7 in range(n6 + 1, len(h)):
                            if h[n1] + h[n2] + h[n3] + h[n4] + h[n5] + h[n6] + h[n7] == 100:
                                ans = [h[n1], h[n2],  h[n3],  h[n4], h[n5], h[n6], h[n7]]
                                break
ans.sort()
for i in ans: print(i)