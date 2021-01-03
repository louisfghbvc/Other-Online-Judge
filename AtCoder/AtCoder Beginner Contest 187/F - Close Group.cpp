// Dp O(3^N + N^2 * 2^N).
// First calculate mask is good or not.
// after that enum dp mask = min(sub_mask + other sub_mask)

#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
#define sz(x) (int)(x).size()
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<int> vi;

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 18;
const int mod = 1e9+7;

int dp[1<<N];
bool good[1<<N];
bool g[N][N];

void solve(){
    memset(dp, 0x3f, sizeof dp);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u][v] = g[v][u] = 1;
    }

    for(int i = 1; i < 1<<n; ++i){
        vi sub;
        for(int j = 0; j < n; ++j) if(i&(1<<j)) sub.push_back(j);

        good[i] = 1;
        for(int j = 0; j < sz(sub); ++j){
            for(int k = j+1; k < sz(sub); ++k){
                if(!g[sub[j]][sub[k]]) good[i] = 0;
            }
        }
    }

    dp[0] = 0;
    for(int S = 1; S < 1<<n; ++S){
        if(good[S]){
            dp[S] = 1;
            continue;
        }
        for(int T = S; T; T = (T-1)&S){
            dp[S] = min(dp[S], dp[T] + dp[S^T]);
        }
    }

    cout << dp[(1<<n) - 1] << "\n";
}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}
