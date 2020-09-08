// 01 bag but wight is so big.
// why not take value as weight?. so just minimum wight.
// O(NV). remember V is 1e3*1e2, why? because if all value can put. maximum is 1e5

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

const int V = 1e5+5;
int dp[105][V];
int cost[105], val[105];

void solve(){
    int n, w;
    cin >> n >> w;
    for(int i = 0; i < n; ++i) cin >> cost[i] >> val[i];

    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= 1e5; ++j)
            dp[i][j] = dp[i-1][j];
        for(int j = val[i-1]; j <= 1e5; ++j){
            dp[i][j] = min(dp[i-1][j-val[i-1]] + cost[i-1], dp[i][j]);
        }
    }

    for(int v = 1e5; v >= 0; --v){
        if(dp[n][v] <= w){
            cout << v << "\n";
            return;
        }
    }
}

int main()
{
    Fast;
    //louisfghbvc{
        solve();
    //}
    return 0;
}
