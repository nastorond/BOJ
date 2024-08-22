#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

bool maps[102][102], visited[102][102];
int dis[102][102];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void init(vector<vector<int>> rectangle) {
    for (int i = 0; i < rectangle.size(); i++) {
        for (int j = rectangle[i][0] * 2; j <= rectangle[i][2] * 2; j++) {
            for (int k = rectangle[i][1] * 2; k <= rectangle[i][3] * 2; k++) {
                maps[j][k] = true;
            }
        }
    }
    for (int i = 0; i < rectangle.size(); i++) {
        for (int j = rectangle[i][0] * 2 + 1; j < rectangle[i][2] * 2; j++) {
            for (int k = rectangle[i][1] * 2 + 1; k < rectangle[i][3] * 2; k++) {
                maps[j][k] = false;
            }
        }
    }
}

int findItem(int startX, int startY, int eX, int eY) {
    queue<pair<int, int>> q;
    visited[startX][startY] = true;
    q.push(make_pair(startX, startY));
    int res;
    
    
    int x, y, nx, ny;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        if (x==eX && y==eY) {
            res = dis[x][y] / 2;
            break;
        }
        
        for (int i=0; i<4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (maps[nx][ny] == 1 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                dis[nx][ny] = dis[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    return res;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    memset(visited, false, sizeof(visited));
    memset(maps, false, sizeof(maps));
    memset(dis, 0, sizeof(dis));
    
    init(rectangle);
    
    return findItem(characterX*2, characterY*2, itemX*2, itemY*2);
}