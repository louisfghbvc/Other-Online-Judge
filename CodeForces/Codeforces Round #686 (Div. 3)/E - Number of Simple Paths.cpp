// O(N). DFS. Tree Concept.
// Cn2 if just a tree. but add one edge.
// So just total n*(n-1). cuz cycle. and in cycle point count subtree size. because subtree size are not double times.

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

const int N = 2e5+5;
vi g[N];
bool cycle[N], vis[N];
int pre[N], Size[N];

bool dfs(int u, int p = -1){
    vis[u] = 1;
    for(int v: g[u]){
        if(v == p) continue;
        if(vis[v]){
            for(int t = u; t != v; t = pre[t])
                cycle[t] = true;
            cycle[v] = true;
            return true;
        }
        else{
            pre[v] = u;
            if(dfs(v, u)) return true;
        }
    }
    return false;
}

void down(int u, int p = -1){
    Size[u] = 1;
    for(int v: g[u]){
        if(cycle[v] || v == p) continue;
        down(v, u);
        Size[u] += Size[v];
    }
}

void solve(){
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) g[i].clear();
    memset(cycle, 0, sizeof cycle);
    memset(vis, 0, sizeof vis);

    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0);
    LL res = 1LL * n * (n-1);
    for(int i = 0; i < n; ++i){
        if(!cycle[i]) continue;
        down(i);
        res -= 1LL * Size[i] * (Size[i]-1) / 2;
    }
    cout << res << "\n";
}

int main()
{
    Fast;
    louisfghbvc
        solve();
    return 0;
}
