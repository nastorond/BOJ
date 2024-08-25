#include <string>
#include <vector>
#include <cstring>
#include <queue>
 
using namespace std;
 
vector<vector<pair<int, int>>> empties;
vector<vector<pair<int, int>>> puzzles;
bool visited[51][51];
int N, answer = 0;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
 
vector<pair<int, int>> preprocess(vector<pair<int, int>> pos) {
    int min_i=N, min_j=N;
    for (int i = 0; i < pos.size(); i++) {
        min_i = min_i > pos[i].first ? pos[i].first : min_i;
        min_j = min_j > pos[i].second ? pos[i].second : min_j;
    }
 
    for (int i = 0; i < pos.size(); i++) {
        pos[i].first -= min_i;
        pos[i].second -= min_j;
    }
    return pos;
}
 
vector<pair<int, int>> bfs(int i, int j, int value, vector<vector<int>> &map) {    
    vector<pair<int, int>> res;
    queue<pair<int, int>> q;
    
    visited[i][j] = true;
    q.push(make_pair(i, j));
    res.push_back(make_pair(i, j));
 
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
 
        for (int mv = 0; mv < 4; mv++) {
            int ny = y + dy[mv];
            int nx = x + dx[mv];
            
            if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            if (visited[ny][nx] || map[ny][nx] != value) continue;
            
            visited[ny][nx] = true;
            q.push(make_pair(ny, nx));
            res.push_back(make_pair(ny, nx));
        }
    }
    return res;
}
 
void rotate(vector<pair<int, int>> &pos) {
    int row = 0;
    for (int i = 0; i < pos.size(); i++) {
        row = row < pos[i].first ? pos[i].first : row;
    }
 
    for (int i = 0; i < pos.size(); i++) {
        int y = pos[i].first;
        int x = pos[i].second;
        pos[i].first=x;
        pos[i].second = row  - y;
    }
}
 
void matching() {
    vector<bool> puzzle_visit(puzzles.size(), false);
 
    for (vector<pair<int, int>> empty : empties) {
        for(int puzzle_idx=0; puzzle_idx<puzzles.size(); puzzle_idx++){
            if (puzzle_visit[puzzle_idx])continue;
            
            vector<pair<int, int>> puzzle = puzzles[puzzle_idx];
            if (empty.size() != puzzle.size())continue;
 
            bool flg = false;
            for (int r = 0; r < 4; r++) {
                int k = 0;
 
                for (int i = 0; i < empty.size(); i++) {
                    for (int j = 0; j < puzzle.size(); j++) {
                        if (empty[i].first == puzzle[j].first && empty[i].second == puzzle[j].second) {
                            k++;
                            continue;
                        }
                    }
                }
                if (k != empty.size()) {
                    rotate(puzzle);
                    continue;
                }
                answer += empty.size();
                puzzle_visit[puzzle_idx] = true;
                flg = true;
                break;
            }
            if (flg)break;
        }
    }
}
 
int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    N = game_board.size();
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (game_board[i][j] == 0 && !visited[i][j])
                empties.push_back(preprocess(bfs(i, j, 0, game_board)));
        }
    }
    
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (table[i][j] == 1 && !visited[i][j])
                puzzles.push_back(preprocess(bfs(i, j, 1, table)));
        }
    }
    matching();
    return answer;
}