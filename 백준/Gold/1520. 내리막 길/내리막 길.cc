#include <iostream>
#include <vector>
#define vvi vector<vector<int>>

using namespace std;

int N, M;
int ret = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool condition(int x, int y)
{
    return x < 0 || x > N-1 || y < 0 || y > M-1; 
}

int dp(int x, int y, vvi& fld, vvi& vi)
{
    if (x == N-1 && y == M-1) return 1;

    if (vi[x][y] != -1) return vi[x][y];

    vi[x][y] = 0;

    for (int i=0; i<4; i++)
    {
        int nX = x + dx[i];
        int nY = y + dy[i];
        if (!condition(nX, nY) && fld[nX][nY] < fld[x][y])
        {
            vi[x][y] += dp(nX, nY, fld, vi);
        }
    }

    return vi[x][y];
}

int main ()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    vvi downHill;
    vvi logs;

    cin >> N >> M;
    downHill.resize(N, vector<int>(M, 0));
    logs.resize(N, vector<int>(M, -1));

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            cin >> downHill[i][j];
        }
    }

    cout << dp(0, 0, downHill, logs) << "\n";

    return 0;
}