# BOJ_1063 : 킹
import sys

input = sys.stdin.readline

# R : 한 칸 오른쪽으로
# L : 한 칸 왼쪽으로
# B : 한 칸 아래로
# T : 한 칸 위로
# RT : 오른쪽 위 대각선으로
# LT : 왼쪽 위 대각선으로
# RB : 오른쪽 아래 대각선으로
# LB : 왼쪽 아래 대각선으로

move_type = {'R': (1, 0), 'L': (-1, 0), 'B': (0, -1), 'T': (0, 1),
             'RT': (1, 1), 'LT': (-1, 1), 'RB': (1, -1), 'LB': (-1, -1)}

pos_king, pos_stone, n_movements = sys.stdin.readline().split()
movements = [sys.stdin.readline().strip() for _ in range(int(n_movements))]
board = [[0] * 8 for _ in range(8)]

pos_king = [ord(pos_king[0]) - 65, int(pos_king[1]) - 1]
pos_stone = [ord(pos_stone[0]) - 65, int(pos_stone[1]) - 1]

for move in movements:
    di, dj = move_type[move]
    ni_king, nj_king = pos_king[0] + di, pos_king[1] + dj
    if 0 <= ni_king < 8 and 0 <= nj_king < 8:
        if ni_king == pos_stone[0] and nj_king == pos_stone[1]:
            ni_stone, nj_stone = pos_stone[0] + di, pos_stone[1] + dj
            if 0 <= ni_stone < 8 and 0 <= nj_stone < 8:
                pos_stone = [ni_stone, nj_stone]
                pos_king = [ni_king, nj_king]
        else:
            pos_king = [ni_king, nj_king]

pos_king = [chr(pos_king[0] + 65), pos_king[1] + 1]
pos_stone = [chr(pos_stone[0] + 65), pos_stone[1] + 1]

print(f'{pos_king[0]}{pos_king[1]}')
print(f'{pos_stone[0]}{pos_stone[1]}')
