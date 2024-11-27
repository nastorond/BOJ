#include <iostream>
#include <vector>

using namespace std;

int main() {

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        vector<int> dp(n+1, 0);
        dp[0] = 1;

        for (int i = 1; i <= 3; i++) {
            for (int j = i; j <= n; j++) {
                dp[j] += dp[j - i];
            }
        }

        cout << dp[n] << "\n";
    }

    return 0;
}