#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void sol(int idx, int len, vector<int> nums, unordered_set<int>& sumOfSub) {
    int n=0, lim=nums.size();
    while (len>0) {
        n += nums[idx];
        idx++;
        idx = idx%lim;
        len--;
    }
    sumOfSub.insert(n);
    return ;
}

int solution(vector<int> elements) {
    int answer = 0, tmp=0, len=elements.size();
    unordered_set<int> sumOfSub;
    
    for (int i=1; i<=len; i++) {
        for (int start=0; start<len; start++) {
            sol(start, i, elements, sumOfSub);
        }
    }
    
    return sumOfSub.size();
}