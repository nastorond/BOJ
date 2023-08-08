def solution(id_list, report, k):
    # 정리할 딕셔너리
    answer = dict()
    # 중복 신고를 없애기 위해 set 사용
    report = set(report)
    # 입력받은 id를 기반으로 기본 딕셔너리형 구성
    for i in id_list:
        answer[i] = {'report': [], 'reported': 0}
    # 각각 신고한 유저와 신고당한 횟수 표기
    for i in report:
        id, reported_id = i.split()
        answer[reported_id]['reported'] += 1
        answer[id]['report'].append(reported_id)
    # 정지되지 않은 유저 리스트 생성
    lis = []
    for i in id_list:
        if answer[i]['reported'] < k:
            lis.append(i)
    # 신고한 유저 중 정지당하지 않은 유저를 report 유저에서 지워주고
    # 남은 id를 바탕으로 신고메일을 받을 개수 생성
    ans = []
    for i in id_list:
        for j in lis:
            try:
                answer[i]['report'].remove(j)
            except:
                pass
        ans.append(len(answer[i]['report']))
    return ans