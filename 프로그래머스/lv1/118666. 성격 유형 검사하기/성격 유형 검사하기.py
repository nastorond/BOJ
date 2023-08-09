def solution(survey, choices):
    answer = ''
    mbti = {'R': 0, 'C': 0, 'J': 0, 'A': 0, 'T': 0, 'F': 0, 'M': 0, 'N': 0}
    scores = {1: 3, 2: 2, 3: 1, 4:0, 5:-1, 6: -2, 7: -3}
    
    for i in range(len(survey)):
        mbti_li = list(survey[i])
        mbti[mbti_li[0]] += scores[choices[i]]
        mbti[mbti_li[1]] -= scores[choices[i]]
        
    if mbti['R'] >= mbti['T']:
        answer += 'R'
    else:
        answer += 'T'
        
    if mbti['C'] >= mbti['F']:
        answer += 'C'
    else:
        answer += 'F'
        
    if mbti['J'] >= mbti['M']:
        answer += 'J'
    else:
        answer += 'M'
        
    if mbti['A'] >= mbti['N']:
        answer += 'A'
    else:
        answer += 'N'
        
    return answer