#include <iostream>

using namespace std;

const int MOD = 1000000009;

long long mod_pow(long long base, long long exp)
{
    long long res = 1;
    base %= MOD;
    
    while (exp > 0)
    {
        if (exp % 2)
        {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    
    return res;
}

int main ()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    if (n == 1)
    {
        cout << 0 << "\n";
    }
    else
    {
        long long ret = mod_pow(3, n-2);
        long long ans = (2 * ret) % MOD;
        cout << ans << "\n";
    }
        
    return 0;
}