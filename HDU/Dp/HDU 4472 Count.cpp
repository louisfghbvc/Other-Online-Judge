//understand problem is really important
#include <bits/stdc++.h>
using namespace std;

int dp[1005];
const int mod = 1e9 + 7;

int main()
{
    int cas = 1, n;
    memset(dp, 0, sizeof dp);
    dp[1] = 1; dp[2] = 1;

    for(int i = 3; i <= 1000; ++i){
        for(int j = 1; j <= i - 1; ++j){
            if((i - 1) % j == 0){
                dp[i] += dp[(i - 1) / j];
                dp[i] %= mod;
            }
        }
    }

    while(cin >> n){
        printf("Case %d: %d\n", cas++, dp[n]);
    }

    return 0;
}
