#include <string>
#include <vector>

using namespace std;

vector<bool> visited;
int ret = 0;

void simulation(int k, int turn, vector<vector<int>>& dungeons) {
    for (int i=0; i<dungeons.size(); i++) {
        if (visited[i] || k < dungeons[i][0]) continue;
        visited[i] = true;
        simulation(k - dungeons[i][1], turn+1, dungeons);
        visited[i] = false;
    }
    
    ret = max(turn, ret);
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    visited.resize(dungeons.size(), false);
    
    simulation(k, 0, dungeons);
    
    return ret;
}