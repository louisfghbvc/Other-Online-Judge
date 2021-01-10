// Record maximum gold i can get. and res is this - max.
// the payment only once. so is simle.
// O(N).

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

const int N = 2e5+5;
/**
Read problem statement carefully
**/

vi g[N];
bool vis[N];
LL arr[N];
LL mx[N];

LL dfs(int u){
    if(vis[u]) return max(mx[u], arr[u]);
    vis[u] = 1;
    mx[u] = 2LL * INT_MIN;
    for(int v: g[u]){
        mx[u] = max(mx[u], dfs(v));
    }
    return max(mx[u], arr[u]);
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
    }

    for(int i = 0; i < n; ++i){
        if(!vis[i]){
            dfs(i);
        }
    }

    LL ans = INT_MIN;
    for(int i = 0; i < n; ++i){
        ans = max(ans, mx[i] - arr[i]);
    }

    cout << ans << "\n";
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
