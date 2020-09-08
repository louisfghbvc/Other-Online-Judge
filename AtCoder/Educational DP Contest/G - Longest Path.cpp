// Simple like tree dp.
// each node = max leaf + 1.

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

const int N = 1e5+5;
vector<int> g[N];
bool vis[N];
int dp[N];

void dfs(int u){
    for(int v: g[u]){
        if(!vis[v]){
            vis[v] = 1;
            dfs(v);
        }
        dp[u] = max(dp[u], dp[v]+1);
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) g[i].clear();
    memset(dp, 0, sizeof dp);
    memset(vis, 0, sizeof vis);

    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            vis[i] = 1;
            dfs(i);
        }
    }

    cout << *max_element(dp+1, dp+n+1) << "\n";
}

int main()
{
    Fast;
    //louisfghbvc{
        solve();
    //}
    return 0;
}
