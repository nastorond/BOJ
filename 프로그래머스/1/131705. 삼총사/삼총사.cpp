#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ret=0;
void dfs(int cur, int val, int cnt, vector<int>& num, vector<bool>& visited) {
    if (cnt == 3) {
        if (val == 0) {
            ret++;
        }
        
        return ;
    }
    for (int i=cur; i<num.size(); i++) {
        if(visited[i]) continue;
        visited[i] = true;
        dfs(i, val+num[i], cnt+1, num, visited);
        visited[i] = false;
    }
}

int solution(vector<int> number) {
    int answer = 0;
    vector<bool> v(number.size(), false);
    
    dfs(0, 0, 0, number, v);
    
    return ret;
}