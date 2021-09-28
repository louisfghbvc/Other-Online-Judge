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
/**.
**/

int val[N], st[N], ed[N], timer = 0;
vi g[N]; // tree

void dfs(int u = 0, int p = -1){
    st[u] = timer++;
    for(int v: g[u]) if(v != p){
        dfs(v, u);
    }
    ed[u] = timer-1;
}

struct BIT{
    LL arr[N] = {};
    void add(int x, int v){
        for(++x ; x < N; x += x&-x) arr[x] += v;
    }
    LL sum(int x){
        LL res = 0;
        for(++x ; x; x -= x&-x) res += arr[x];
        return res;
    }
} bt;

void solve(int T){
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; ++i) cin >> val[i];

    for(int i = 0; i+1 < n; ++i){
        int u, v; cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs();
    for(int i = 0; i < n; ++i){ // range update.
        bt.add(st[i], val[i]);
        bt.add(ed[i]+1, -val[i]);
    }
    
    while(q--){
        int t, s, x;
        cin >> t;
        if(t == 1){ // change val s to x, range update
            cin >> s >> x; --s;
            int dif = x - val[s];
            bt.add(st[s], dif);
            bt.add(ed[s]+1, -dif);
            val[s] = x;
        }
        else{
            cin >> s; --s;
            cout << bt.sum(st[s]) << "\n";
        }
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
