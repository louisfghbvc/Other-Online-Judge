/**                                          
 __         ______     __  __     __     ______     ______   ______     __  __     ______     __   __   ______    
/\ \       /\  __ \   /\ \/\ \   /\ \   /\  ___\   /\  ___\ /\  ___\   /\ \_\ \   /\  == \   /\ \ / /  /\  ___\   
\ \ \____  \ \ \/\ \  \ \ \_\ \  \ \ \  \ \___  \  \ \  __\ \ \ \__ \  \ \  __ \  \ \  __<   \ \ \'/   \ \ \____  
 \ \_____\  \ \_____\  \ \_____\  \ \_\  \/\_____\  \ \_\    \ \_____\  \ \_\ \_\  \ \_____\  \ \__|    \ \_____\ 
  \/_____/   \/_____/   \/_____/   \/_/   \/_____/   \/_/     \/_____/   \/_/\/_/   \/_____/   \/_/      \/_____/                                       
**/
#include <bits/stdc++.h>
// #pragma GCC optimize("O3")
#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; for(int tt = 0; tt < t; ++tt)
#define sz(x) (int)(x).size()
#define sort_unique(x) sort(All(x)); x.erase(unique(All(x)), x.end());
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
 
const int N = 2e5+5;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
/**
 * T: O(Q*sqrt(M))
**/

vi g[N];
vi big_g[N];

void solve(int T){
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0, u, v; i < m; ++i){
        cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    const int M = sqrt(m); // sqrt(M)

    for(int i = 0; i < n; ++i){
        for(int u: g[i])
            if(sz(g[u]) > M)
                big_g[i].push_back(u);
    }

    vector<int> x(n), t(n); 
    iota(All(x), 1); // x[i]: i
    vector<array<int, 2>> lazy(n); // value x, time

    auto pull = [&](int u){ // download node value from others.
        for(int v : big_g[u]){
            if(lazy[v][1] > t[u]){
                t[u] = lazy[v][1];
                x[u] = lazy[v][0];
            }
        }
    };

    for(int i = 1; i <= q; ++i){
        int u; cin >> u; --u;
        pull(u);
        if(sz(g[u]) <= M){ // light
            for(int v : g[u]){
                x[v] = x[u];
                t[v] = i;
            }
        }
        else{ // heavy, no matter light or heavy, u just add a tag, record current value, timestamp
            lazy[u] = {x[u], i};
        }
    }


    for(int i = 0; i < n; ++i){
        pull(i);
        cout << x[i] << ' ';
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
