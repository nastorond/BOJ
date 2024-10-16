#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    vector<int> mlq(10, 0);
    queue<pair<int, int>> q;
    
    for (int i=0; i<priorities.size(); i++) {
        mlq[priorities[i]]++;
        q.push(make_pair(priorities[i], i));
    }
    
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        
        bool flg = false;
        for (int i=9; i > p.first; i--) {
            if (mlq[i] > 0) {
                flg = true;
                break;
            }
        }
        
        if (flg) {
            q.push(p);
            continue;
        }
        
        if (location == p.second) {
            return answer;
        }
        answer++;
        mlq[p.first]--;
    }
    
    
    return answer;
}