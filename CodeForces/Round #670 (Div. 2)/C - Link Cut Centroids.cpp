// dfs 1 time to get the subtree size, and get center1, 2.
// second, if center only 1. just remove random edge add that edge.
// or 2 center. remove center2 leaf. add to center1. so that only 1 center.
// if 2 center, 2 center must adjacent. why? because if not, they are not connected graph.
// O(N).

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

const int N = 1e5+5;
vi g[N];
LL sz[N];
int cent1, cent2, mn;
int n;

void dfs(int u = 1, int p = -1){
    LL mx = 0;
    sz[u] = 1;
    for(int v: g[u]){
        if(v != p){
            dfs(v, u);
            sz[u] += sz[v];
            mx = max(mx, sz[v]);
        }
    }
    mx = max(mx, (LL)n-sz[u]);
    if(mn > mx) mn = mx, cent1 = u, cent2 = 0;
    else if(mn == mx) cent2 = u;
}

void solve(){
    int a, b;
    cin >> n;
    for(int i = 1; i <= n; ++i) g[i].clear();
    memset(sz, 0, sizeof sz);
    cent1 = cent2 = 0; mn = 1e9;

    for(int i = 0; i+1 < n; ++i){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs();
    if(!cent2){
        cout << 1 << " " << g[1][0] << "\n";
        cout << 1 << " " << g[1][0] << "\n";
        return;
    }
    for(int v : g[cent2]){
        if(v == cent1) continue;
        cout << cent2 << " " << v << "\n";
        cout << cent1 << " " << v << "\n";
        return;
    }
}

int main()
{
    Fast;
    louisfghbvc{
        solve();
    }
    return 0;
}
