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
 
const int N = 1e5+5;
const LL INF = 1e13;
const int mod = 998244353;
const LL MXP = 1e10;
/**
**/

// comp_sz: group size
// ID: node to new graph vertex
int low[N], dfn[N], ID[N], inst[N], comp_sz[N], stamp, key;
stack<int> st;
vector<int> graph[N];

void dfs(int u) {
    dfn[u] = low[u] = ++stamp;
    st.push(u);
    inst[u] = 1;
    for (int v: graph[u]) {
        if (!dfn[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (inst[v]) 
            low[u] = min(low[u], dfn[v]);
    }

    if (low[u] == dfn[u]) {
        int x;
        do {
            x = st.top(); st.pop();
            inst[x] = 0;
            ID[x] = key;
            comp_sz[key]++;
        } while (x != u);
        key++;
    }
}

void solve(int T) {
    cout << "Case #" << T+1 << ": ";

    // goal: given n people, m statements
    // find the number of n people that be proved innocent

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        graph[i].clear();
    stamp = 0;
    key = 0; // new graph index
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    memset(inst, 0, sizeof inst);
    memset(ID, 0, sizeof ID);
    memset(comp_sz, 0, sizeof comp_sz);

    vector<ii> edges;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v; u--, v--;
        graph[u].push_back(v);
        edges.push_back({u, v});
    }

    // first we use SCC to compress the graph
    for (int i = 0; i < n; ++i) {
        if (!dfn[i]) dfs(i);
    }

    vector<unordered_set<int>> adj(key); // reverse graph
    for (auto &[u, v]: edges)
        if (ID[u] != ID[v])
            adj[ID[v]].insert(ID[u]);

    int ans = 0;
    for (int i = 0; i < key; ++i) {
        unordered_set<int> vis;
        vis.insert(i);
        int now = comp_sz[i];
        queue<int> q;
        q.push(i);

        while (now <= k && q.size()) {
            int u = q.front(); q.pop();
            for (int v: adj[u]) {
                if (vis.insert(v).second) {
                    q.push(v);
                    now += comp_sz[v];
                }
            }
        }

        if (now > k)
            ans += comp_sz[i];

    }

    cout << ans << "\n";
}                                

int main(){
    Fast;
    // freopen("in.txt", "r", stdin), freopen("out.txt", "w", stdout);
    louisfghbvc
        solve(tt);
    return 0;
}
