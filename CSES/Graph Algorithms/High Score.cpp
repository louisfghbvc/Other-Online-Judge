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
 
const int N = 3e3+5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
**/

vector<ii> g1[N];
vector<ii> g2[N]; // backward
bool vis1[N], vis2[N]; // forward, backward.

void dfs1(int u){
    vis1[u] = 1;
    for(auto &[v, _]: g1[u]){
        if(!vis1[v]) dfs1(v);
    }
}
void dfs2(int u){
    vis2[u] = 1;
    for(auto &[v, _]: g2[u]){
        if(!vis2[v]) dfs2(v);
    }
}

void solve(int T){
    int n, m;
    cin >> n >> m;
    vector<vi> arr(m, vi(3));
    for(int i = 0; i < m; ++i){
        cin >> arr[i];
        LL a = arr[i][0], b = arr[i][1], c = arr[i][2];
        g1[a].push_back({b, c});
        g2[b].push_back({a, c});
    }
    dfs1(1);
    dfs2(n);
    vi dp(n+1, -1e13);
    dp[1] = 0;

    for(int i = 0; i < n-1; ++i){
        for(int j = 0; j < m; ++j){
            LL a = arr[j][0], b = arr[j][1], c = arr[j][2];
            if(dp[a] + c > dp[b]){
                dp[b] = dp[a] + c;
            }
        }
    }

    bool gg = 0;
    for(int j = 0; j < m; ++j){
        LL a = arr[j][0], b = arr[j][1], c = arr[j][2];
        if(dp[a] + c > dp[b]){
            if(vis1[b] && vis2[b]) gg = 1;
            dp[b] = dp[a] + c;
        }
    }
    cout << (gg ? -1 : dp[n]) << "\n";
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
