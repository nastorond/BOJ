#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp1[100000 + 30];
int dp2[100000 + 30];

int solution(vector<int> sticker)
{
    if (sticker.size() == 1) {
        return sticker[0];
    }
    int answer = 0;
    
    dp1[0] = sticker[0];
    dp1[1] = sticker[0];
    
    dp2[0] = 0;
    dp2[1] = sticker[1];
    
    for (int i=2; i<sticker.size()-1; i++) {
        dp1[i] = max(dp1[i-2] + sticker[i], dp1[i-1]);
    }
    
    for (int i=2; i<sticker.size(); i++) {
        dp2[i] = max(dp2[i-2] + sticker[i], dp2[i-1]);
    }
    
    answer = *max(max_element(dp1, dp1+sticker.size()), max_element(dp1, dp2+sticker.size()));
    
    return answer;
}