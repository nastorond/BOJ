"""
좌우 대칭 이므로 반으로 반쪽만 계산해주고 두배 해주면가능
가운대가 있는 경우엔 그 부분만 따로 계산
"""
# 재귀함수로 구현
def set_q(x,y, fld, n):
    global cnt
    global cnt_center

    # 체스판 밖이면 함수 종료
    if x == n:
        return
    
    # 첫번째 행은 유효성 체크를 할필요 없음
    if x == 0:
        # 대칭이므로 중간 까지만 진행
        for y_idx in range(n//2):
            fld[x][y+y_idx] = 1
            set_q(x+1, y, fld, n)
            fld[x][y+y_idx] = 0

        # 홀수일 경우 추가로 확인
        if n%2:
            if n == 1:
                cnt_center += 1
                return
            fld[x][n//2] = 1
            mono_set_q(x+1, y, fld, n)
    
    else:
        # 한칸씩 옆으로 이동하며 체크
        for y_idx in range(n):
            # 해당 위치가 가능할 때, 첫번째 행에서는 가능한지 확인하지 않아도 되므로
            if ck_avail(x, y_idx, fld, n):
                # 끝의 행에서 가능한 자리를 찾은 경우 더이상 같은 행에는
                # 없으므로 return 해 그 함수를 종료한다
                if x == n-1:
                    cnt += 1
                    return
                else:
                    # 아래 행으로 내려오기 전에 해당 위치를 1로 바꿔준다
                    fld[x][y_idx] = 1
                    # 다음 행으로 내려가서  탐색
                    set_q(x+1, y, fld, n)
                    # 끝난 뒤 자리를 비워준다
                    fld[x][y_idx] = 0


# 홀수는 따로 추가탐색
def mono_set_q(x, y, fld, n):
    global cnt_center

    for y_idx in range(n):
        # 해당 위치가 가능할 때, 첫번째 행에서는 가능한지 확인하지 않아도 되므로
        if ck_avail(x, y_idx, fld, n):
            # 끝의 행에서 가능한 자리를 찾은 경우 더이상 같은 행에는
            # 없으므로 return 해 그 함수를 종료한다
            if x == n-1:
                cnt_center += 1
                return
            else:
                # 아래 행으로 내려오기 전에 해당 위치를 1로 바꿔준다
                fld[x][y_idx] = 1
                # 다음 행으로 내려가서  탐색
                mono_set_q(x+1, y, fld, n)
                # 끝난 뒤 자리를 비워준다
                fld[x][y_idx] = 0


# 가능한지 확인하는 함수
def ck_avail(x, y, fld, n):
    # 위에서부터 퀸을 놓으면서 내려오니까 위에 세 방향만 확인
    for mi, mj in [[-1, 0], [-1, 1], [-1, -1]]:
        # di, dj를 기본값으로 세팅해준뒤
        di, dj = x, y
        while 1:
            # 한칸씩 위로 올라가며 확인한다
            di, dj = di + mi, dj + mj
            if 0 <= di <n and 0 <= dj < n:
                # 해당 구역이 채워져 있다면
                # 이 위치는 불가능 하다고 판단하고 return
                if fld[di][dj]:
                    return False
            # 체스판 밖으로 나가면 break
            else:
                break
    # 끝까지 돌면 True를 반환한다
    return True

cnt = 0
cnt_center = 0
def solution(n):
    global cnt
    global cnt_center

    answer = 0
    # 비어있는 체스판 생성
    chess_fld = [[0]*n for _ in range(n)]
    # 경우의 수를 세어줄 변수 선언
    set_q(0, 0, chess_fld, n)
    answer = (2*cnt) + cnt_center
    return answer