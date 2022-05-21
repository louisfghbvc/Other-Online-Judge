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

vector<array<LL, 3>> graph[N]; // next node, length, u-v edge idx

void solve(int T) {
    // cout << "Case #" << T+1 << ": ";
    int n, m;
    cin >> n >> m; 

    // goal: n city, m road, 
    // only maintain n-1 roads

    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --v, --u;
        graph[u].push_back({v, c, i});
        graph[v].push_back({u, c, i});
    }    

    // idea: dijkstra, record the edge, find the parent

    vi dis(n, LLONG_MAX);
    dis[0] = 0;

    priority_queue<array<LL, 3>, vector<array<LL, 3>>, greater<>> pq; // {cost, E}
    pq.push({0, 0, -1});

    vi ans;

    while (pq.size()) {
        auto [cost, u, eid] = pq.top(); pq.pop();
        if (cost > dis[u]) continue;
        if (eid >= 0)
            ans.push_back(eid);
        for (auto &[v, c, idx]: graph[u]) {
            if (dis[v] > dis[u] + c) {
                dis[v] = dis[u] + c;
                pq.push({dis[v], v, idx});
            }
        }
    }

    for (auto &x: ans)
        cout << x+1 << " ";
    cout << "\n";

}                         

int main(){
    Fast;
    // freopen("in.txt", "r", stdin), freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    return 0;
}
