def solution(k, m, score):
    score.sort()
    answer = 0
    while len(score)>=m:
        tmp = []
        for _ in range(m):
            tmp.append(score.pop())
        answer += min(tmp)*m
    return answer