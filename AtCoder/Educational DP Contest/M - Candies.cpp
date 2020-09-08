// IF Brute force. it will be O(NKK) TLE.
// So use prefix sum. the dp[i][k] can from (sum of dp[i-1][0~k]).
// think about example n = 3, k = 4.
// and 1, 2, 3.
// dp[0][0] = 1. base.
// if i = 3, rolling.
// k = 0-3, dp[i][k] = sum of dp[i-1][k]. think about dp[i][1]. means candy = 1, how many ways. is from dp[i-1][0]+dp[i-1][1]
// O(NK).

#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
#define sz(x) (int)(x).size()
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int mod = 1e9+7;
const int N = 1e5+5;
LL arr[105];
LL dp[105][N];

void solve(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> arr[i];

    memset(dp, 0, sizeof dp);

    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i){
        int sum[k+1];
        sum[0] = dp[i-1][0];
        for(int j = 1; j <= k; ++j)
            sum[j] = (sum[j-1] + dp[i-1][j]) % mod;
        for(int j = 0; j <= k; ++j){
            int tmp = sum[j];
            int cur = j-arr[i]-1;
            if(cur >= 0){
                tmp = (tmp - sum[cur]+ mod) % mod;
            }
            dp[i][j] = tmp;
        }
    }
    cout << dp[n][k] << "\n";
}

int main()
{
    Fast;
    //louisfghbvc{
        solve();
    //}
    return 0;
}
