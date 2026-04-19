/*
n, m 격자 -> bfs / dfs 고려
여러덩이 -> 모든 칸을 상대로 특정 덩이만큼의 범위를 counting or check 후 flag 처리
수직으로 하나 뚫었을 때, 가장 많은 석유 -> 각 열에 해당하는 범위를 더한다 ? 라는 개념으로 접근
    -> BFS or DFS로 맵을 탐색하며 석유가 있는 부분의 열에 +1 해주는 방식으로 가장 큰 열 탐색
한번에 획득할 수 있는 가장 많은양의 석유 양 찾기

맵의 최대 크기 500 x 500
    BFS -> VE
        O(pow(500, 2)) = O(250,000) -> 시간 내
*/
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<bool>> vi; //! 방문 확인용
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; //! 방향
int n, m;   //! 행 / 열
vector<int> values; //! 각 위치 별 시추 가능 매장량 저장

/*
* @brief n, m을 기준으로 해당 좌표가 범위를 넘어가는지 검사
* @param pair<행, 열>
* @return bool
*/
bool bdCondition(pair<int,int> cur)
{
    return ((cur.first < 0 || cur.first >= n) || (cur.second < 0 || cur.second >= m));
}

/**
* @param stx = 시작 행
* @param sty = 시작 행
* @param land = 탐색 할 필드
*/
void bfs(int stx, int sty, vector<vector<int>>& land)
{
    queue<pair<int, int>> q;   //! q 선언
    q.push(make_pair(stx, sty));   //! 시작위치
    vi[stx][sty] = true; //! 시작위치 방문 처리
    vector<bool> viCols;
    viCols.resize(m, false);
    viCols[sty] = true; //! 시작 열 저장
    int res = 1; //! 이번 석유 덩이 크기 저장
    
    int x, y;
    while (!q.empty())  //! q 가 비어있지 않은 동안 반복
    {
        auto [x, y] = q.front(); q.pop(); //! 가장 앞 반환
        
        for (int i=0; i<4; ++i) //! 해당 위치를 기준으로 4방향 탐색
        {
            const int nx = x + dir[i][0]; //! 방문할 위치
            const int ny = y + dir[i][1];
            if (!bdCondition(make_pair(nx, ny)) && !vi[nx][ny] && land[nx][ny] == 1)
            {
                q.push(make_pair(nx, ny));
                vi[nx][ny] = true;
                viCols[ny] = true; //! 해당 열에서 이번 석유 덩이 발견 가능
                ++res;
            }
        }
    }
    
    if (res > 0)
    {
        //! 시추 가능량 합산
        for (int i=0; i<viCols.size(); ++i)
        {
            if (viCols[i]) values[i] += res;
        }
    }
}

int solution(vector<vector<int>> land) {
    int answer = 0;
        
    n = land.size();      //! 행 사이즈
    m = land[0].size();   //! 열 사이즈
    vi.resize(n, vector<bool>(m, false)); //! 방문처리 벡터 초기화
    values.resize(m, 0); //! 누적 값 벡터 초기화
    
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<m; ++j)
        {
            //! 방문한 적 없고, 석유가 있는 경우만 방문
            if (!vi[i][j] && land[i][j] == 1) bfs(i, j, land);
        }
    }
    
    for (auto& cur : values)
    {
        //! 최대값으로 갱신
        answer = answer < cur ? cur : answer;
        //! std::cout << cur << " "; //debug
    }
    
    return answer;
}