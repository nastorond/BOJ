## 마인크래프트
import sys
input = sys.stdin.readline
n, m, b = map(int, input().split())
fld = [map(int, input().split()) for _ in range(n)]
print(min(fld))