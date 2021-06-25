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
 
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
Read problem statement carefully
**/

vi g[N];

void solve(int T){
    int n, m;
    cin >> n >> m;
    for(int i = 0, u, v; i < m; ++i){
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vi dis(n, 1e9);
    vi path(n);

    dis[0] = 0;
    queue<ii> q;
    q.push({0, 0}); // node, cost

    while(sz(q)){
        auto [u, cost] = q.front(); q.pop();
        if(dis[u] < cost) continue;
        dis[u] = cost;
        for(int v: g[u]){
            if(dis[v] > dis[u] + 1){
                path[v] = u;
                dis[v] = dis[u]+1;
                q.push({v, dis[v]});
            }
        }
    }

    if(dis[n-1] == 1e9) cout << "IMPOSSIBLE\n";
    else{
        vi ans = { n };
        int p = n-1;
        while(p != 0){
            ans.push_back(path[p]+1);
            p = path[p];
        }
        cout << sz(ans) << "\n";
        for(int i = 0; i < sz(ans); ++i)
            cout << ans[sz(ans)-i-1] << " \n"[i+1==sz(ans)]; 
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
