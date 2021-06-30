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
**/

vi g[N];
int par[N][19]; // par[u][i] u's 2^i parent
int n;

void dfs(int u = 1, int p = -1){
    for(int v: g[u]) if(v != p) {
        par[v][0] = u;
        dfs(v, u);
    }
}

int kth_anc(int x, int k){
    int res = x;
    for(int i = 18; i >= 0; --i){
        if(res == -1) return res;
        if(k & (1<<i)){
            res = par[res][i];
        }
    }
    return res;
}

void solve(int T){
    int q;
    memset(par, -1, sizeof par);

    cin >> n >> q;
    for(int i = 2, p; i <= n; ++i){
        cin >> p;
        g[p].push_back(i);
    }
    
    dfs();

    for(int i = 1; i <= 18; ++i){
        for(int j = 1; j <= n; ++j){
            if(par[j][i-1] != -1)
                par[j][i] = par[par[j][i-1]][i-1];
        }
    }

    while(q--){
        int x, k;
        cin >> x >> k;
        cout << kth_anc(x, k) << "\n";
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
