#include <bits/stdc++.h>
 
// #pragma GCC optimize("O3")
#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; for(int tt = 0; tt < t; ++tt)
#define sz(x) (int)(x).size()
#define sort_unique(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()));
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/**
order_of_key(k) : nums strictly smaller than k
find_by_order(k): index from 0
**/
 
template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ' '; dbg_out(T...); }
 
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
Read problem statement carefully
**/

vi g[N];
int stamp = 0, in[N], out[N];
int par[N][20]; // parent
int dis[N];

void dfs(int u, int depth = 0, int p = -1){
    in[u] = stamp++;
    dis[u] = depth;
    for(int v: g[u]) if(v != p){
        par[v][0] = u; 
        dfs(v, depth+1, u);
    }
    out[u] = stamp++;
}

bool anc(int x, int y){
    return in[x] <= in[y] && out[x] >= out[y];
}

int LCA(int x, int y){
    if(anc(x, y)) return x;
    if(anc(y, x)) return y;

    for(int i = 19; i >= 0; --i){
        if(!anc(par[x][i], y))
            x = par[x][i];
    }
    return par[x][0];
}

void solve(int T){
    int n, q;
    cin >> n >> q;
    for(int i = 0; i+1 < n; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1);

    for(int i = 1; i < 20; ++i){
        for(int j = 1; j <= n; ++j){
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }

    for(int i = 0; i < q; ++i){
        int c, d;
        cin >> c >> d;
        int lca = LCA(c, d);
        LL route = dis[c] + dis[d] - 2*dis[lca];
        if(route & 1) cout << "Road\n";
        else cout << "Town\n";
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
