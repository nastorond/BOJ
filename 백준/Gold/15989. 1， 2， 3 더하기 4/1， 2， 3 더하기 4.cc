#include <iostream>
#include <vector>

using namespace std;

int main() {

    int tc, n;
    cin >> tc;

    vector<int> dp(10001, 0);
    dp[0] = 1;

    for (int i = 1; i <= 3; i++) {
        for (int j = i; j <= 10001; j++) {
            dp[j] += dp[j - i];
        }
    }

    while (tc--) {
        cin >> n;
        
        cout << dp[n] << "\n";
    }

    return 0;
}