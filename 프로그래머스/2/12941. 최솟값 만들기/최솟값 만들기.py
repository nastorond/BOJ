def solution(A,B):
    answer = 0
    A.sort()
    B.sort(reverse = True)
    while len(A) and len(B):
        min_val = A.pop()
        max_val = B.pop()
        answer += min_val * max_val
    return answer