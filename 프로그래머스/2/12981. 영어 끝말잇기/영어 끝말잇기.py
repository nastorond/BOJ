def solution(n, words):
    answer = []
    answer_sheet = {}
    cnt = 1
    
    preword = words[0]
    answer_sheet[preword] = 1
    for i in range(1, len(words)):
        if words[i][0] != preword[-1] or answer_sheet.get(words[i], 0) == 1:
            answer = [cnt%n+1, cnt//n+1]
            break
        # print(preword, words[i])
        preword = words[i]
        cnt += 1
        answer_sheet[words[i]] = 1
    else:
        answer = [0, 0]
    
    # print(answer_sheet)

    return answer