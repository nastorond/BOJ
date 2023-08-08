def solution(id_list, report, k):
    answer = dict()
    report = set(report)
    for i in id_list:
        answer[i] = {'report': [], 'reported': 0}
    for i in report:
        id, reported_id = i.split()
        answer[reported_id]['reported'] += 1
        answer[id]['report'].append(reported_id)
    lis = []
    for i in id_list:
        if answer[i]['reported'] < k:
            lis.append(i)
    ans = []
    for i in id_list:
        for j in lis:
            try:
                answer[i]['report'].remove(j)
            except:
                pass
        ans.append(len(answer[i]['report']))
    return ans