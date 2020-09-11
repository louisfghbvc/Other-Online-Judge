// Tree dp. the way is multiply. not just add. 
// O(N). useful tree dp.

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
const int N = 1e5+5;
int n;
vi g[N];
LL dp[N][2];

void dfs(int u, int p = -1){
    dp[u][0] = dp[u][1] = 1;
    for(int v: g[u]){
        if(v != p){
            dfs(v, u);
            dp[u][1] = (dp[u][1] * dp[v][0]) % mod;;
            dp[u][0] = (dp[u][0] * (dp[v][1] + dp[v][0]) % mod) % mod;
        }
    }
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i) g[i].clear();
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(dp, 0, sizeof dp);
    dfs(1);
    cout << (dp[1][0]+dp[1][1])%mod << "\n";
}

int main()
{
    Fast;
    //louisfghbvc{
        solve();
    //}
    return 0;
}
