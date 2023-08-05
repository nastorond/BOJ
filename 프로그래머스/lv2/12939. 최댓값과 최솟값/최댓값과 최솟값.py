def solution(s):
    s = list(map(int, s.split()))
    max_val = max(s)
    min_val = min(s)
    answer = f'{min_val} {max_val}'
    return answer