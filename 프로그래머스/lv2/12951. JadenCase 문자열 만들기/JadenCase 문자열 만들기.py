def solution(s):
    s = s.split(' ')
    for i in range(len(s)):
        # if s[i][:2].isdigit():
        #     pass
        # else:
        s1 = s[i][:1].upper()
        s2 = s[i][1:].lower()
        s[i] = s1 + s2
    answer = ' '.join(s)
    return answer