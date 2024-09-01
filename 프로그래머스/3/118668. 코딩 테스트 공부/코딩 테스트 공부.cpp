#include <string>
#include <vector>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    
    int dp[160][160], MAXAlgo=0, MAXCoding=0;
    
    for (vector<int> v : problems) {
        MAXAlgo = max(MAXAlgo, v[0]);
        MAXCoding = max(MAXCoding, v[1]);
    }
    
    for (int i=0; i<=MAXAlgo; i++) {
        for (int j=0; j<=MAXCoding; j++) {
            dp[i][j] = 1e9;
        }
    }

    alp = min(alp, MAXAlgo);
    cop = min(cop, MAXCoding);
    
    dp[alp][cop]=0;
    for (int i=alp; i<=MAXAlgo; i++) {
        for (int j=cop; j<=MAXCoding; j++) {
            if (i < MAXAlgo) dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1);
            if (j < MAXCoding) dp[i][j+1] = min(dp[i][j+1], dp[i][j]+1);
            for(auto v: problems) {
                if (i >= v[0] && j >= v[1]) {
                    int tmpAlp = min(i+v[2], MAXAlgo);
                    int tmpCop = min(j+v[3], MAXCoding);
                    dp[tmpAlp][tmpCop] = min(dp[tmpAlp][tmpCop], dp[i][j]+v[4]);
                }
            }
        }
    }
    
    return dp[MAXAlgo][MAXCoding];
}