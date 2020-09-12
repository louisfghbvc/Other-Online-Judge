// O(2^N*N + 2^N*N).
// Bit dp. man order put, and woman enum all mask to determine.
// Nice prune is if man cnt != woman cnt. cut.

#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
#define sz(x) (int)(x).size()
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int mod = 1e9+7;
const int N = 22;
bool g[N][N];
LL dp[N][1<<N];

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> g[i][j];

    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int mask = 0; mask < (1<<n); ++mask){
            int cnt_woman = __builtin_popcount(mask);
            if(cnt_woman != i) continue;
            for(int j = 0; j < n; ++j){
                if(g[i][j] && (mask&(1<<j))){
                    int m2 = mask^(1<<j);
                    dp[i][mask] += dp[i-1][m2];
                    dp[i][mask] %= mod;
                }
            }
        }
    }
    cout << dp[n][(1<<n)-1] << "\n";
}

int main()
{
    Fast;
    //louisfghbvc{
        solve();
    //}
    return 0;
}
