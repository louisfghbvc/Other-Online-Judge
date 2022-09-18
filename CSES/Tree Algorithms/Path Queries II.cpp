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
// template <class T> using ordered_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
const LL INF = 1e13;
const int mod = 998244353;
const LL MXP = 1e10;
/**
**/

int sz[N], dep[N], bson[N], fa[N]; // for dfs
int top[N], dfn[N], stamp = 0; // for link
int val[N], n; // weight, node
vector<int> tree[N];

// --------- segment tree ---------------  
int tre[4*N];
void update(int id, int l, int r, int pos, int x) {
    if (l == r && l == pos) {
        tre[id] = x;
        return;
    }
    int mid = (l+r)/2;
    if (pos <= mid)
        update(id*2, l, mid, pos, x);
    else
        update(id*2+1, mid+1, r, pos, x);
    tre[id] = max(tre[id*2], tre[id*2+1]);
}
int query(int id, int l, int r, int ll, int rr) {
    if (l > rr || r < ll) return 0;
    if (ll <= l && r <= rr) return tre[id];
    int mid = (l+r)/2;
    return max(
        query(id*2, l, mid, ll, rr),
        query(id*2+1, mid+1, r, ll, rr)
    );
}
// ------------------------------------


void dfs(int u, int p=0) {
    sz[u] = 1;
    fa[u] = p;
    bson[u] = -1;
    for (int v: tree[u]) {
        if (v == p) continue;
        dep[v] = dep[u]+1;
        dfs(v, u);
        sz[u] += sz[v];
        if (bson[u] == -1 || sz[v] > sz[bson[u]]) bson[u] = v;
    }
}

void link(int u, int t) {
    top[u] = t;
    dfn[u] = ++stamp;
    update(1, 1, n, dfn[u], val[u-1]); // for segment tree
    if (bson[u] == -1) return;
    link(bson[u], t);
    for (int v: tree[u]) {
        if (v == bson[u] || v == fa[u]) continue;
        link(v, v);
    }
}

int path(int x, int y) {
	int ret = 0;
	while(top[x] != top[y]){
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		ret = max(ret, query(1, 1, n, dfn[top[x]], dfn[x]));
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	ret = max(ret, query(1, 1, n, dfn[x], dfn[y]));
	return ret;
}

void solve(int T) {
    // cout << "Case #" << T+1 << ": ";
    
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> val[i];
    for (int i = 0; i+1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1);
    link(1, 1);

    for (int i = 0; i < q; ++i) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) { // change a->b
            update(1, 1, n, dfn[a], b);
        }
        else {
            cout << path(a, b) << " ";
        }
    }
    cout << "\n";
}   

int main(){
    Fast;
    // freopen("in.txt", "r", stdin), freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    return 0;
}
