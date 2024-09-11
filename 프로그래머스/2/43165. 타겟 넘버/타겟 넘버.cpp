#include <string>
#include <vector>

using namespace std;

int ret=0;

void dfs (int cur, int val, int goal, vector<int>& nums) {
    if (cur == nums.size()) {
        if (val == goal) {
            ret++;   
        }
        return ;
    }
    
    dfs(cur+1, val + nums[cur]*(-1), goal, nums);
    dfs(cur+1, val + nums[cur], goal, nums);
    
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(0, 0, target, numbers);
    
    return ret;
}