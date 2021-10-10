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
 
const int N = 1e3+5;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
/**
**/

vi g[N]; // v
int cnt[N]; // edge cnt
map<ii, int> mp; // edge id

void bfs(int s, int t){
    int vis[N] = {};
    int path[N] = {};

    queue<int> q;
    q.push(s);
    vis[s] = 1;
    
    while(sz(q)){
        int u = q.front(); q.pop();
        if(u == t){
            while(t != s){
                cnt[mp[{t, path[t]}]]++;
                t = path[t];
            }
            return;
        }
        for(auto &v: g[u]) if(!vis[v]){
            vis[v] = 1;
            path[v] = u;
            q.push(v);
        }
    }
}

void solve(int T){
    int n, m, k;
    cin >> n >> m >> k;

    vi arr(m);
    cin >> arr;

    for(int i = 0; i+1 < n; ++i){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        mp[{u, v}] = mp[{v, u}] = i;
    }

    for(int i = 0; i+1 < m; ++i){
        bfs(arr[i], arr[i+1]);
    }

    // tot -> R = B+K
    int tot = 0;
    for(int i = 0; i+1 < n; ++i) tot += cnt[i];
    if((tot + k) % 2 || tot + k < 0){
        cout << 0 << "\n"; return;
    }
    
    vi dp(100005); dp[0] = 1;
    for(int i = 0; i+1 < n; ++i)
        for(int x = 100000; x >= cnt[i]; --x)
            dp[x] = (dp[x] + dp[x - cnt[i]]) % mod;

    cout << dp[(tot + k) / 2] << "\n";
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
