#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#define MAXN 20002

using namespace std;

vector<vector<int>> gp(MAXN);
int dis[MAXN], res=0, record[MAXN] = {0, };

void bfs() {
    queue<int> q;
    q.push(1);
    dis[1] = 0;
    record[1] = 1;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int i=0; i<gp[cur].size(); i++) {
            int next = gp[cur][i];
            if (dis[next] == -1) {
                dis[next] = dis[cur] + 1;
                q.push(next);
                res = max(res, dis[next]);
                record[dis[next]] += 1;
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    gp.resize(n+1);
    for (int i=0; i<edge.size(); i++) {
        gp[edge[i][0]].push_back(edge[i][1]);
        gp[edge[i][1]].push_back(edge[i][0]);
    }
    
    fill(dis, dis+n+1, -1);
    
    bfs();
    
    return record[res];
}