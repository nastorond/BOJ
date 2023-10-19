answer_sheet = {'zero': '0', 'one': '1', 'two': '2', 'three': '3', 'four': '4', 'five': '5', 'six': '6', 'seven': '7', 'eight': '8', 'nine': '9'}
def solution(s):
    answer = ''
    tmp = ''
    for i in s:
        if i.isdigit():
            answer += i
        else:
            tmp += i
            if answer_sheet.get(tmp, 0) != 0:
                answer += answer_sheet[tmp]
                tmp = ''
        
    return int(answer)