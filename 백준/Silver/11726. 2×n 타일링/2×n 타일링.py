import sys
# input = sys.stdin.readline

"""
tile[n] : 채우는 방법의 수
dp 문제는 한단계 한단계 가면서 해결해야 함
타일을 추가 했을 때 나머지를 바꾸는 방법의 수
맨 오른쪽 끝 위치를 기준으로 타일을 놓는 방법
맨 오른쪽 끝에 한개를 넣었을 때 tile[n-1]과 동일
두개를 넣었을 때 tile[n-2]와 동일한 가지 수
tile[n] = tile[n-1] + tile[n-2]
"""
n = int(input())
tile = [0, 1, 2]
for i in range(3, n+1):
    tile.append(tile[i-1] + tile[i-2])
print(tile[n] % 10007)
