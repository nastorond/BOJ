import sys

input = sys.stdin.readline

def compare_dna(pos1, pos2):
    pos1_li = list(pos1)
    pos2_li = list(pos2)
    cnt_not_same = 0
    for _ in range(m):
        if pos1_li.pop() != pos2_li.pop():
            cnt_not_same += 1
    return cnt_not_same
def count_dna(pos1):
    dna_cnt_dict = {'A': 0, 'C': 0, 'G': 0, 'T': 0}
    for unit in pos1:
        dna_cnt_dict[unit] += 1
    max_val = max(dna_cnt_dict.values())
    for k, v in dna_cnt_dict.items():
        if v == max_val:
            return k
n, m = map(int, input().split())
dna_dict = dict()
dna_list = []
for _ in range(n):
    dna = input().rstrip()
    dna_list.append(dna)
    cnt = 0
    for i in dna:
        try:
            dna_dict[cnt].append(i)
        except KeyError:
            dna_dict[cnt] = [i]
        cnt += 1
ans1 = ''
for i in dna_dict.values():
    ans1 += count_dna(i)
ans2 = 0
for i in dna_list:
    ans2 += compare_dna(i, ans1)
print(ans1)
print(ans2)