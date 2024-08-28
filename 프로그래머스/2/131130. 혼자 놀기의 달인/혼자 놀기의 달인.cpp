#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[101] = {false, };
vector<int> group;

bool compare(int a, int b) {
    return a > b;
}

void game(int cur, int cnt, vector<int> cards) {
    if (visited[cur-1]) {
        group.push_back(cnt);
        return ;
    }
    visited[cur-1] = true;
    game(cards[cur-1], cnt+1, cards);
}

int solution(vector<int> cards) {
    int answer = 0, lim = cards.size();
    
    for (int i=0; i<lim; i++) {
        if (!visited[cards[i]-1]) game(cards[i], 0, cards);        
    }
    
    if (group.size() == 1) return 0;
    
    sort(group.begin(), group.end(), compare);
    
    return group[0] * group[1];
}