#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; for(int tt = 0; tt < t; ++tt)
#define sz(x) (int)(x).size()
#define sort_unique(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()));
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const LL N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
Read problem statement carefully
**/



vi g[N];
vi dis[N];
int in[N];
int out[N];
int gt = 0;

void dfs(int u, int c = 0, int p = -1){
    in[u] = ++gt;
    dis[c].push_back(in[u]);
    for(int v: g[u]){
        if(v == p) continue;
        dfs(v, c+1, u);
    }
    out[u] = ++gt;
}

void solve(LL n){
    cin >> n;
    for(int i = 2, p; i <= n; ++i){
        cin >> p;
        g[p].push_back(i);
        g[i].push_back(p);
    }
    dfs(1);

    int q;
    cin >> q;
    for(int i = 0, u, d; i < q; ++i){
        cin >> u >> d;
        const auto &can = dis[d];
        cout << lower_bound(All(can), out[u]) - lower_bound(All(can), in[u]) << "\n";
    }

}

int main()
{
    Fast;
    //freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    return 0;
}

/**
Enjoy the problem.
**/
