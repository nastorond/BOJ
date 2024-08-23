#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[52] = {false, };
int answer = 1e9;

bool canSwitch(string cur, string next) {
    int cnt = 0;
    for (int i=0; i<cur.size(); i++) {
        if (cur[i] != next[i]) cnt++;
    }
    return cnt == 1 ? true : false;
}

void dfs (int cur, int turn, string goal, vector<string> words) {
    if (goal == words[cur]) {
        answer = min(answer, turn);
        return ;
    }
    for (int i=0; i<words.size()-1; i++) {
        if (i != cur && !visited[i] && canSwitch(words[cur], words[i])) {
            visited[i] = true;
            dfs(i, turn+1, goal, words);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    words.push_back(begin);
    if (find(words.begin(), words.end(), target) == words.end()) return 0;
    
    dfs(words.size()-1, 0, target, words);
    
    return answer;
}