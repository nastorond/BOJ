#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp1[1000000 + 30];
int dp2[1000000 + 30];

int solution(vector<int> money)
{
    int answer = 0;
    
    dp1[0] = money[0];
    dp1[1] = money[0];
    
    dp2[0] = 0;
    dp2[1] = money[1];
    
    for (int i=2; i<money.size()-1; i++) {
        dp1[i] = max(dp1[i-2] + money[i], dp1[i-1]);
    }
    
    for (int i=2; i<money.size(); i++) {
        dp2[i] = max(dp2[i-2] + money[i], dp2[i-1]);
    }
    
    answer = *max(max_element(dp1, dp1+money.size()), max_element(dp1, dp2+money.size()));
    
    return answer;
}