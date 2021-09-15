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
**/

void solve(int T){
    int n, m;
    cin >> n >> m;
    vector<vi> g(n, vi(n, -1));
    vector<ii> edge(m);

    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b; a--, b--;
        g[a][b] = i; // record edge id
        edge[i] = {a, b};
    }

    vector<ii> memo(n); // parent, edge id
    vi dis(n, -1); 
    dis[0] = 0;

    auto bfs = [&](){
        queue<int> q; q.push(0);
        while(sz(q)){
            int u = q.front(); q.pop();
            for(int v = 0; v < n; ++v) if(dis[v] == -1 && g[u][v] != -1){
                dis[v] = dis[u]+1;
                memo[v] = {u, g[u][v]};
                q.push(v);
            }
        }
    };

    bfs();

    if(dis[n-1] == -1){ // unreachable
        for(int i = 0; i < m; ++i)
            cout << -1 << "\n";
        return;
    }

    int cur = n-1;
    vi shortest_path_id; 
    while(cur != 0){
        shortest_path_id.push_back(memo[cur].second);
        cur = memo[cur].first;
    }

    vi ans(m, dis[n-1]);
    for(auto &id: shortest_path_id){
        auto &[u, v] = edge[id];
        g[u][v] = -1;
        dis = vi(n, -1); 
        dis[0] = 0;
        bfs();
        ans[id] = dis[n-1];
        g[u][v] = id;
    }

    for(int x: ans) 
        cout << x << "\n";
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
