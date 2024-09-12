#include <vector>

using namespace std;

int answer=0;

vector<bool> fillSeive() {
    vector<bool> seive(3002, true);
    seive[0] = seive[1] = true;
    for (int i=2; i*i<=3001; i++) {
        if (seive[i]) {
            for (int j=i*i; j<=3001; j+=i) {
                seive[j] = false;
            }
        }
    }
    return seive;
}

void dfs(int cur, int cnt, int val, vector<bool>& visit, vector<int>& nums, vector<bool>& seive) {
    if (cnt == 3) {
        if (seive[val]) answer++;
        return ;
    }
    for (int i=cur; i<nums.size(); i++) {
        if (visit[i]) continue;
        visit[i] = true;
        dfs(i, cnt+1, val+nums[i], visit, nums, seive);
        visit[i] = false;
    }
}

int solution(vector<int> nums) {    
    vector<bool> seive = fillSeive();
    vector<bool> visited(nums.size(), false);
    
    dfs(0, 0, 0, visited, nums, seive);
    
    return answer;
}