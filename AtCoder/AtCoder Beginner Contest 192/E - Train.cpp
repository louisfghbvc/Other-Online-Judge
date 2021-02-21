#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
#define sz(x) (int)(x).size()
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 1e5+5;
const int inf = 0x3f3f3f3f;
/**
Read problem statement carefully
**/


struct node{
    LL v, t, k;
};
vector<node> g[N];

void solve(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for(int i = 0; i < m; ++i){
        int u, v, t, k;
        cin >> u >> v >> t >> k;
        g[u].push_back({v, t, k});
        g[v].push_back({u, t, k});
    }

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    vi dp(n+1, 1e16);
    pq.push({0, x});
    dp[x] = 0;
    while(pq.size()){
        auto [cost, u] = pq.top(); pq.pop();
        if(cost > dp[u]) continue;
        dp[u] = cost;
        //cout << cost << " " << u << "\n";
        for(node nd: g[u]){
            LL tran = (cost % nd.k == 0) ? 0 : nd.k - cost % nd.k;
            if(dp[nd.v] > dp[u] + tran + nd.t){
                dp[nd.v] = dp[u] + tran + nd.t;
                pq.push({dp[nd.v], nd.v});
            }
        }
    }
    cout << (dp[y] > 1e15 ? -1 : dp[y])<< "\n";
}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}

/**
Enjoy the problem.
**/
