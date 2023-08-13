def solution(new_id):
    # 1. 모든 대문자를 대응되는 소문자로 치환
    new_id = new_id.lower()
    # 직전 문자 저장
    sav = ''
    # 새롭게 만들 아이디 선언
    id_new = ''
    # 하나 씩 순회하며
    for i in new_id:
        # 알파벳이 아니거나, 숫자가 아닐때 '-', '_', '.'이 아닌경우 단계를 건너뜀
        if not i.isalpha() and not i.isdigit():
            #if ord(i) != 45 and ord(i) != 95 and ord(i) != 46:
            if i not in ['-', '_', '.']:
                continue
        # 연속된 마침표가 나올경우 직전문자열을 초기화 하고 단계를 건너뜀
        if sav == '.' and i == '.':
            continue
        
        # 문자열 저장
        sav = i
        
        # 새로운 문자에 저장
        id_new += i
        
    # 양 끝에 있는 . 제거
    id_new = id_new.strip('.')
    
    # 길이가 1보다 작을경우 a 추가
    if len(id_new) < 1:
        id_new += 'a'
    
    # 길이가 15보다 길 경우 15가 될때까지 뒤에서부터 자른다
    if len(id_new) > 15:
        id_new = id_new[:15]
    
    # 자른 후 마지막이 . 이라면 제거
    id_new = id_new.rstrip('.')
    
    # 길이가 3보다 작으면 마지막 문자 반복해 추가
    # if len(id_new) < 3:
    while len(id_new) < 3:
        id_new += id_new[-1]

    return ''.join(id_new)