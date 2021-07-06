#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; for(int tt = 0; tt < t; ++tt)
#define sz(x) (int)(x).size()
#define sort_unique(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()));
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 500 + 5;
const LL INF = LLONG_MAX / 2;
const int mod = 1e9+7;
/**
Read problem statement carefully
**/

LL g[N][N];

void solve(int T){
    int n, m, q;
    cin >> n >> m >> q; 

    for(int i = 1; i <= n; ++i)
        fill(g[i] + 1, g[i] + n + 1, INF);
    for(int i = 1; i <= n;++i)
        g[i][i] = 0;

    for(int i = 0; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], (LL)c);
        g[b][a] = min(g[b][a], (LL)c);
    }

    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    while(q--){
        int u, v;
        cin >> u >> v;
        if(g[u][v] >= INF) cout << -1 << "\n";
        else cout << g[u][v] << "\n";
    }
}   


int main()
{
    Fast;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    return 0;
}

/**
Enjoy the problem.
**/
