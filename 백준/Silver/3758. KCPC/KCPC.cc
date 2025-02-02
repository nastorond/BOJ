// silver 2 KCPC
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct stTeamInfo
{
    int teamID;             // team id
    int iScores;            // team score
    int iSubmitTime;        // submit time
    int iSubmitCnt;         // submit counting
    vector<int> iProbs;     // problems

public:
    void init()
    {
        iScores = 0;
        iSubmitTime = 0;
        iSubmitCnt = 0;
        iProbs.resize(101, 0);
    }
};

bool compare (stTeamInfo a, stTeamInfo b)
{
    if (a.iScores == b.iScores)
    {
        if (a.iSubmitCnt == b.iSubmitCnt) return a.iSubmitTime < b.iSubmitTime; 
        return a.iSubmitCnt < b.iSubmitCnt;
    }
    return a.iScores > b.iScores;
}

void logProcess(const int iSubmitTime, const int iTeamID, const int iNum, const int iScore, stTeamInfo& st)
{
    st.iSubmitCnt++;                            // 제출 횟수
    st.iSubmitTime = iSubmitTime;              // 제출 시간

    if (st.iProbs[iNum] > 0)
    {
        if (st.iProbs[iNum] < iScore)           // 기존 점수가 현 점수보다 낮은 경우만 진행
        {
            st.iScores += iScore - st.iProbs[iNum];
            st.iProbs[iNum] = iScore;
        }
    }
    else 
    {
        st.iScores += iScore;
        st.iProbs[iNum] = iScore;
    }

}

void solution ()
{
    int n, k, t, m;                         // 팀 수, 문재의 개수, 나의 팀 Id, 로그 엔트리 개수
    cin >> n >> k >> t >> m;
    vector<stTeamInfo> teamInfos;           // 팀 정보
    stTeamInfo stTmp;
    stTmp.init();
    for (int i=1; i<=n; i++)
    {
        stTmp.teamID = i;
        teamInfos.push_back(stTmp);
    }
    
    int iTeamID, iNum, iScore;
    for (int iSubmitTime=0; iSubmitTime<m; iSubmitTime++)     // 제출 순서대로 가중치 부여
    {
        cin >> iTeamID >> iNum >> iScore;
        logProcess(iSubmitTime, iTeamID, iNum, iScore, teamInfos[iTeamID-1]);
    }
    
    sort(teamInfos.begin(), teamInfos.end(), compare);

    for (int i=0; i<n; i++)
    {
        if (teamInfos[i].teamID != t) continue;
        cout << i+1 << "\n";
        break;
    }
}

int main ()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int tc; cin >> tc;

    while (tc--)
    {
        solution();
    }

    return 0;
}