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

int segment[8*N], first[N], height[N];
vi g[N]; // tree
int euler[2*N], timer = 0;

void dfs(int u = 1, int p = -1, int h = 0){
    height[u] = h;
    first[u] = timer;
    euler[timer++] = u;
    for(int v: g[u]) if(v != p){
        dfs(v, u, h+1);
        euler[timer++] = u;
    }
}

void build(int l = 0, int r = timer-1, int root = 1){
    if(l == r) return (void)(segment[root] = euler[l]);
    int mid = (l+r)>>1;
    build(l, mid, root*2);
    build(mid+1, r, root*2+1);
    int lc = segment[root*2], rc = segment[root*2+1];
    segment[root] = height[lc] > height[rc] ? rc : lc; 
}

int query(int ll, int rr, int l = 0, int r = timer-1, int root = 1){
    if(r < ll || l > rr) return -1;
    if(l >= ll && r <= rr) return segment[root];
    int mid = (l+r)>>1;
    int left = query(ll, rr, l, mid, root*2);
    int right = query(ll, rr, mid+1, r, root*2+1);
    if(left == -1) return right;
    if(right == -1) return left;
    return height[left] < height[right] ? left : right;
}

int lca(int a, int b){
    if(first[a] > first[b]) swap(a, b);
    return query(first[a], first[b]);
}

void solve(int T){
    int n, q;
    cin >> n >> q;
    for(int i = 0; i+1 < n; ++i){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs();
    build();

    while(q--){
        int u, v; cin >> u >> v;
        --u, v--;
        int an = lca(u, v);
        cout << height[u] + height[v] - 2*height[an] << "\n";
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
