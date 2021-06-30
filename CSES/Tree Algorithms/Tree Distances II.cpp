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
 
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
Read problem statement carefully
the ans change can consider only neightbor size.
**/

vi g[N];
int subtree[N]; // subtree size
LL ans[N];

int n;
void dfs1(int u, int p = -1, int depth = 0){
    ans[1] += depth;
    subtree[u] = 1;
    for(int v: g[u]) if(v != p){
        dfs1(v, u, depth+1);
        subtree[u] += subtree[v];
    }
}

void dfs2(int u, int p = -1){
    for(int v: g[u]) if(v != p){
        int up = n - subtree[v];
        int down = subtree[v];
        ans[v] = ans[u] + up - down;
        dfs2(v, u);
    }
}

void solve(int T){
    cin >> n;
    for(int i = 0, u, v; i+1 < n; ++i){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs1(1);
    dfs2(1);

    for(int i = 1; i <= n; ++i)
        cout << ans[i] << " ";

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
