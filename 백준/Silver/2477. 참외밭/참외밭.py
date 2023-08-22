melon = int(input())
values = [input().split() for _ in range(6)]
height = []
width = []
cycle = []

for x, y in values:
    x, y = int(x), int(y)
    if x == 1 or x == 2:
        width.append(y)
    else:
        height.append(y)
    cycle.append(y)

max_h = max(height)
max_w = max(width)

max_h_idx = cycle.index(max_h)
max_w_idx = cycle.index(max_w)

min_val_1 = cycle[(max_h_idx + 3) % 6]
min_val_2 = cycle[(max_w_idx + 3) % 6]

box = max_h * max_w - (min_val_2 * min_val_1)

print(box * melon)