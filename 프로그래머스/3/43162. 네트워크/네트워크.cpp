#include <string>
#include <vector>
#include <queue>

using namespace std;

int res=0;
bool vis[200] = {false, };

void bfs (int cur, vector<vector<int>> com) {
    queue<int> q;
    q.push(cur);
    vis[cur] = true;
    res++;
    
    while (!q.empty()) {
        int next = q.front();q.pop();
        for (int i=0; i<com[next].size(); i++) {
            int tmp = com[next][i];
            if (tmp && !vis[i]) {
                q.push(i);
                vis[i] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i=0; i<n; i++) {
        if (!vis[i]) {
            bfs(i, computers);
        }
    }
    
    return res;
}